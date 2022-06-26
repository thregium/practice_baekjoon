#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : [A, B](A <= B <= 2 * 10^6)에서 멋진 쌍의 개수를 구한다.
멋진 쌍은 두 자연수가 서로 자릿수를 밀어서 만들어지는 것이 가능한 쌍이다.

해결 방법 : 모든 수에 대해 그 수보다 큰 멋진 쌍의 개수를 구한다.
문자열 함수를 이용하면 편리하다.

주요 알고리즘 : 수학, 브루트 포스, 문자열
*/

char s[16], t[16];
int x[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int a, b, l, res = 0;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        sprintf(s, "%d", i);
        l = strlen(s);
        for (int j = 0; j < l; j++) {
            strcpy(t, s + j);
            for (int k = 0; k < j; k++) t[l - j + k] = s[k];
            t[l] = '\0';
            x[j] = strtoll(t, NULL, 10);
        }
        qsort(x, l, sizeof(int), cmp1);
        for (int j = 0; j < l; j++) {
            if (j > 0 && x[j] == x[j - 1]) continue;
            if (x[j] <= i || x[j] > b) continue;
            res++;
        }
    }
    printf("%d", res);
    return 0;
}