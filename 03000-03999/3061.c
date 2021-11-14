#include <stdio.h>

/*
문제 : N(N <= 1000)개의 선으로 이루어진 사다리에서 해당하는 순서로 바꾸기 위해 넣어야 하는 선의 최소 개수를 구한다.

해결 방법 : 매 선마다 두 순서만 교환되기 때문에 모든 순서쌍들 가운데 순서가 반대인 것의 개수를 세면 된다.

주요 알고리즘 : 그리디 알고리즘?
*/

int a[1024];

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] > a[j]) r++;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}