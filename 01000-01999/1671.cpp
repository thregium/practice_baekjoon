#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 50)마리의 상어들의 능력치가 주어진다. 각 상어는 세 능력치가 모두 상대의 능력치 이상인 경우
그 상대를 잡아먹을 수 있다. 각 상어는 최대 2마리까지 잡아먹을 수 있고, 상어는 차례로 다른 상어를 잡아먹게 된다.
물론 먹힌 상어는 다른 상어를 먹을 수 없다. 이때, 남는 상어의 최소 마리수를 구한다.

해결 방법 : 왼쪽 정점을 먹는 상어(*2), 오른쪽 정점을 먹히는 상어로 두고 이분 매칭을 하면 된다.
어떤 매칭의 경우라도 먹히는 상어가 먼저 상어를 먹도록 하면 되기 때문에 이분 매칭이 성립된다.
단, 서로 능력치가 완전히 같은 상어끼리는 서로 먹고 먹히지 않도록 임의의 순서를 정해서 일방적으로 먹고 먹히도록 해야 한다.

주요 알고리즘 : 이분 매칭 

출처 : SRM 358D1 1번
*/

int shark[64][3], left[128], right[64], vis[128];
vector<int> ed[128];

int match(int x) {
    vis[x] = 1;
    for (int i : ed[x]) {
        if (right[i] == 0 || (!vis[right[i]] && match(right[i]))) {
            left[x] = i;
            right[i] = x;
            return 1;
        }
    }
    return 0;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &shark[i][0], &shark[i][1], &shark[i][2]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (shark[i][0] == shark[j][0] && shark[i][1] == shark[j][1] && shark[i][2] == shark[j][2]) {
                if (j > i) {
                    ed[i * 2].push_back(j);
                    ed[i * 2 - 1].push_back(j);
                }
            }
            else if (shark[i][0] >= shark[j][0] && shark[i][1] >= shark[j][1] && shark[i][2] >= shark[j][2]) {
                ed[i * 2].push_back(j);
                ed[i * 2 - 1].push_back(j);
            }
        }
    }

    for (int i = 1; i <= n * 2; i++) {
        r += match(i);
        for (int j = 1; j <= n * 2; j++) vis[j] = 0;
    }
    printf("%d", n - r);
    return 0;
}