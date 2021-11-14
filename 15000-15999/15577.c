#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 20)개의 자연수(1, 2, 3, 4, 5)가 주어질 때, 이 자연수를 2개씩 평균을 구하는 것을 반복해 구할 수 있는
가장 큰 값을 구한다.

해결 방법 : 작은 수부터 평균을 구해 나가는 것이 최적이다. 따라서, 오름차순으로 정렬한 후 배열에서 평균을 구해나가며
마지막 값을 구하면 그것이 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬, 수학

출처 : COCI 17/18#7 1번
*/

double num[32];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &num[i]);
    }
    qsort(num, n, sizeof(double), cmp1);
    for (int i = 1; i < n; i++) {
        num[i] = (num[i - 1] + num[i]) / 2;
    }
    printf("%.9f", num[n - 1]);
    return 0;
}