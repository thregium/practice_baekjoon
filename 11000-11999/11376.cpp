#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 1000)명과 일 M(M <= 1000)개가 있다. 각 사람이 할 수 있는 일들이 주어질 때, 일을 최대 몇 개까지
동시에 할 수 있는지 구한다. 각 사람은 2개까지 일을 할 수 있고, 각 일들은 1명만 있으면 된다.

해결 방법 : 이분 매칭을 이용해 해결 가능하다. 일반적인 이분매칭에서 각 사람쪽의 정점을 2개로 늘리고 이분 매칭을 시행하면 된다.

주요 알고리즘 : 그래프 이론, 이분 매칭
*/

int left[2048], right[1024], vis[2048];
vector<int> ed[2048];

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
    int n, m, c, x, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c);
        for (int j = 0; j < c; j++) {
            scanf("%d", &x);
            ed[i * 2 - 1].push_back(x);
            ed[i * 2].push_back(x);
        }
    }
    for (int i = 1; i <= n * 2; i++) {
        if (left[i]) continue;
        for (int j = 1; j <= n * 2; j++) vis[j] = 0;
        r += match(i);
    }
    printf("%d", r);
    return 0;
}