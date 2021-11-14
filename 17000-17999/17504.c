#include <stdio.h>

/*
문제 : N(N <= 15)개의 분수로 이루어진 연속 분수를 푼 결과를 1에서 뺀 값을 구한다.
각 분수 앞의 자연수는 1 이상 9 이하로 주어진다.

해결 방법 : 맨 밑에서부터 재귀적으로 값들을 채워나간다. 분모와 분자, 오버플로에 주의한다.

주요 알고리즘 : 수학

출처 : 경북대 2019 I번
*/

int a[16];

void swap(long long* a, long long* b) {
    long long c = *a;
    *a = *b;
    *b = c;
}

int main(void) {
    int n;
    long long ru = 0, rd = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    ru = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        swap(&ru, &rd);
        ru += rd * a[i];
    }
    swap(&ru, &rd);
    ru = rd - ru;
    printf("%lld %lld", ru, rd);
    return 0;
}