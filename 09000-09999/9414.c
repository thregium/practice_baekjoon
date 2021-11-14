#include <stdio.h>
#include <stdlib.h>

/*
문제 : 40개 이하의 땅에 대해 가격이 매년 처음 가격 배만큼 오를 때, 모든 땅을 사는 가장 싼 값을 구한다.

해결 방법 : 가장 비싼 것 부터 차례로 사면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : Thai 2010N G번
*/

int price[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, r, x;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        n = 0;
        while (1) {
            scanf("%d", &price[n]);
            if (price[n] == 0) break;
            n++;
        }
        qsort(price, n, sizeof(int), cmp1);
        r = 0;
        for (int i = 0; i < n; i++) {
            x = 2;
            for (int j = 0; j <= i; j++) x *= price[i];
            r += x;
            if (r > 5000000) {
                r = -1;
                break;
            }
        }
        if (r < 0) printf("Too expensive\n");
        else printf("%d\n", r);
    }
    return 0;
}