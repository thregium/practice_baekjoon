#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 1000)명의 사람과 M(M <= 1000)개의 일이 주어진다. 이때, K(K <= N)명의 사람은 2개의 일을 할 수 있고,
나머지는 1개의 일만 할 수 있다면 할 수 있는 일의 최대 개수를 구한다.

해결 방법 : 이분 매칭을 통해 우선 모든 사람들이 1개의 일만 하는 경우의 매칭을 구한다.
그리고 그 상태에서 사람의 정점을 2배 늘리고 늘린 정점에서 추가 매칭을 더한다. 단, 추가 매칭이 K개가 되는 순간
추가 매칭을 종료한다. 그 후 원래 매칭과 추가 매칭의 합을 구하면 답이 된다.

주요 알고리즘 : 이분 매칭
*/

vector<int> ed[2048];
int vis[2048], left[2048], right[1024];

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
    int n, m, k, c, w, r = 0, r2 = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c);
        for (int j = 0; j < c; j++) {
            scanf("%d", &w);
            ed[i].push_back(w);
        }
    }
    for (int i = 1; i <= n; i++) {
        r += match(i);
        for (int j = 1; j <= n; j++) vis[j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        ed[i + n] = ed[i];
    }
    for (int i = n + 1; i <= n * 2; i++) {
        r2 += match(i);
        if (r2 == k) break;
        for (int j = 1; j <= n * 2; j++) vis[j] = 0;
    }
    printf("%d", r + r2);
    return 0;
}