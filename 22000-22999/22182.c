#include <stdio.h>
#define PI 3.141592653589793

/*
문제 : N(N <= 100)개의 값(<= 100)과 반지름 R(R <= 100)이 주어질 때,
각 값들로 이루어진 원그래프의 각 값이 차지하는 면적을 각각 구한다.

해결 방법 : 전체 값의 합을 구한 다음, 각 값에 대해 원의 넓이에 전체에서의 비율을 곱한 것을
매번 출력하면 된다. 원의 넓이는 2pir^2이고 전체에서의 비율은 a_i / sum이다.

주요 알고리즘 : 수학, 기하학

출처 : RCC 2011Q2 A번
*/

int a[128];

int main(void) {
    int n, r, sum = 0;
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (int i = 0; i < n; i++) {
        printf("%.9f\n", a[i] / (double)sum * r * r * PI);
    }
    return 0;
}