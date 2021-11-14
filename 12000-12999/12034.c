#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100) * 2 크기의 배열(<= 10^9, 자연수)에 원래 수와 원래 수에서 4 / 3배 한 수들이 섞여 있다.
원래 수들을 오름차순으로 정렬하여 출력한다. 그러한 경우가 항상 나오도록 주어진다.

해결 방법 : 각 수를 오름차순으로 정렬한 다음, 4 / 3배 한 것을 제거한다. 이를 반복하면 중복해서 제거하지 않고
모든 4 / 3배 된 수들을 제거할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : GCJ 2016W A2번
*/

long long p[256];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, x;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n * 2; i++) {
            scanf("%lld", &p[i]);
        }
        qsort(p, n * 2, sizeof(long long), cmp1);
        for (int i = 0; i < n; i++) {
            x = 0;
            for (int j = i + 1; j < n * 2 - i; j++) {
                if (p[j] * 3 == p[i] * 4) {
                    for (int k = j; k < n * 2 - i - 1; k++) {
                        p[k] = p[k + 1];
                    }
                    x = 1;
                    break;
                }
            }
            if (!x) return 1;
        }
        printf("Case #%d: ", tt);
        for (int i = 0; i < n; i++) {
            printf("%lld ", p[i]);
        }
        printf("\n");
    }
    return 0;
}