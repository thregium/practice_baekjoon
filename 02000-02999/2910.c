#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 자연수(<= 10^9)들을 빈도 순으로 정렬한다. 빈도가 같다면 같은 원소 가운데
가장 먼저 나온 것을 기준으로 정렬한다.

해결 방법 : 먼저 사전순으로 정렬한 다음, 각 원소의 빈도와 첫 등장을 추가한 다음, 빈도 순서대로 정렬하고 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : COCI 09/10#3 3번
*/

int a[1024][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 2);
    int bi = *((int*)b + 2);
    if (ai != bi) return ai < bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, c, stt = 0, smol;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i][0]);
        a[i][1] = i + 1;
    }
    qsort(a, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        if (a[i][0] == a[i + 1][0]) continue;
        else {
            smol = 103000;
            for (int j = stt; j <= i; j++) {
                a[j][2] = i - stt + 1;
                if (a[j][1] < smol) smol = a[j][1];
            }
            for (int j = stt; j <= i; j++) a[j][1] = smol;
            stt = i + 1;
        }
    }
    qsort(a, n, sizeof(int) * 3, cmp2);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i][0]);
    }
    return 0;
}