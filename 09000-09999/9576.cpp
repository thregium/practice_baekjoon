#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 1000)개의 책을 M(M <= 1000)명에게 나누어 주려고 한다. 이때, 각 사람이 받을 수 있는 책의 범위가 주어지면
책을 받을 수 있는 최대의 사람 수를 구한다.

해결 방법 : 이분 매칭을 이용하면 간단하게 풀 수 있다.

주요 알고리즘 : 이분 매칭
*/

int left[1024], right[1024], vis[1024];
vector<int> ed[1024];

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
    int t, n, m, a, b, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &a, &b);
            for (int j = a; j <= b; j++) ed[i].push_back(j);
        }
        r = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) vis[j] = 0;
            r += match(i);
        }
        printf("%d\n", r);
        for (int i = 0; i <= 1000; i++) {
            left[i] = 0;
            right[i] = 0;
            vis[i] = 0;
            ed[i].clear();
        }
    }
    return 0;
}