#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : [A, B](1 <= A <= B <= 10^11) 범위의 자연수들 가운데 제곱수이면서 뒤집어서 0으로 시작하지 않는
제곱수인 수의 개수를 구한다.

해결 방법 : 모든 범위 내의 제곱수에 대해 주어진 조건에 맞는 지 확인하면 된다.
단, 제곱수 여부를 확인하기 위한 방법을 생각해야 한다.(이 코드에서는 전처리 + 이분 탐색을 사용했다.)

주요 알고리즘 : 수학, 브루트 포스, 이분 탐색, 구현

출처 : ROI 2021H A번
*/

char s[16];
long long sqr[327680];

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void revstring(char* s) {
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        swap(&s[i], &s[j]);
    }
}

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    long long a, b, c, r = 0;
    scanf("%lld %lld", &a, &b);
    for (long long i = 1; i < 327680; i++) {
        sqr[i] = i * i;
    }
    for (long long i = 1; i < 327680; i++) {
        if (i * i < a || i * i > b) continue;
        sprintf(s, "%lld", i * i);
        revstring(s);
        if (s[0] == '0') continue;
        c = strtoll(s, NULL, 10);
        if (bsearch(&c, sqr, 327680, sizeof(long long), cmp1)) r++;
    }
    printf("%lld", r);
    return 0;
}