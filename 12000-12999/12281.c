#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 정수로 이루어진 배열을 홀수는 오름차순으로, 짝수는 내림차순으로 정렬한다.
이때, 홀수와 짝수의 순서를 유지해야 한다. 주어지는 정수는 +- 1000 이내 범위에 있다.

해결 방법 : 배열을 홀수와 짝수로 나눈 후 각각 정렬한다. 그리고 다시 원래 배열로 돌아와서 홀 짝 여부를 확인하며 합치면 된다.

주요 알고리즘 : 구현, 정렬

출처 : GGCT 2014A C2번 // GKS 2013A A2번
*/

int s[1024], odd[1024], even[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, o, e;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        o = 0, e = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
            if (s[i] & 1) odd[o++] = s[i];
            else even[e++] = s[i];
        }
        qsort(odd, o, sizeof(int), cmp1);
        qsort(even, e, sizeof(int), cmp2);
        o = 0, e = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] & 1) s[i] = odd[o++];
            else s[i] = even[e++];
        }
        printf("Case #%d: ", tt);
        for (int i = 0; i < n; i++) {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
    return 0;
}