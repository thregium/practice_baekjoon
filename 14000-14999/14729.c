#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10^7)개의 실수(소수점 아래 3자리, 0 이상 100 이하)가 주어질 때,
가장 작은 7개의 실수를 소수점 아래 3자리까지 출력한다. (제한시간 10초)

해결 방법 : 각 실수들을 오름차순으로 정렬한 다음, 앞에서부터 7개를 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : 중앙대 2017P D번
*/

double score[10485760];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &score[i]);
    }
    qsort(score, n, sizeof(double), cmp1);
    for (int i = 0; i < 7; i++) {
        printf("%.3lf\n", score[i]);
    }
    return 0;
}
