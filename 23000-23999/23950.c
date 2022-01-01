#include <stdio.h>

/*
문제 : N(N <= 100000)개의 논문에 대한 인용수(<= 100000, 자연수)가 주어질 때, 각 논문을 작성할 때 마다의 H-index를 구한다.

해결 방법 : 각 논문의 인용수 범위가 크지 않기 때문에 각 인용수의 등장 횟수를 배열에 저장해둔다.
논문을 작성할 때 마다 그 인용수의 등장 횟수를 1 늘리고, 다음 H-index의 값 이상인 경우 달성 횟수에 1을 추가한다.
달성 횟수가 다음 H-index가 되면 그 인용수의 등장 횟수 만큼을 달성 횟수에서 빼고(다다음 H-index에는 포함되지 않으므로)
H-index를 1 올린다. 이때마다의 H-index의 값을 출력하면 된다.

주요 알고리즘 : 구현, 애드 혹

출처 : GKS 2019H A번
*/

int cnt[103000];

int main(void) {
    int t, n, a, r, c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        r = 0, c = 0;
        printf("Case #%d: ", tt);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            cnt[a]++;
            if (a > r) c++;
            while (c > r) {
                c -= cnt[++r];
            }
            printf("%d ", r);
        }
        printf("\n");
        for (int i = 0; i < 103000; i++) cnt[i] = 0;
    }
    return 0;
}