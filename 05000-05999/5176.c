#include <stdio.h>

/*
문제 : P명과 M(P, M <= 500)개의 자리가 있을 때, P명의 각 사람이 원하는 자리를 선점한다.
원하는 자리가 선점된 경우 앉지 못한다면 앉지 못하는 사람의 수를 구한다.

해결 방법 : 방문 배열을 이용해 이미 방문한 경우 결괏값을 1 늘리고 방문하지 않았다면 방문하는 것을 반복해
나온 결괏값을 출력하면 된다.

주요 알고리즘 : 구현

출처 : USC 2007F B번
*/

int a[512];

int main(void) {
    int t, p, m, x, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        r = 0;
        scanf("%d %d", &p, &m);
        for (int i = 1; i <= m; i++) a[i] = 0;
        for (int i = 0; i < p; i++) {
            scanf("%d", &x);
            if (a[x]) r++;
            else a[x] = 1;
        }
        printf("%d\n", r);
    }
    return 0;
}