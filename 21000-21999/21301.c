#include <stdio.h>

/*
문제 : 수 10개가 주어질 때 표준편차가 1 이하인지 구한다.

해결 방법 : 표준편차를 계산해서 1 이하인지 확인하면 된다. 루트 1은 1이므로 제곱근은 계산할 필요 없다.

주요 알고리즘 : 수학

출처 : GNY 2020 B번
*/

double a[10];

int main(void) {
    double average = 0, error = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%lf", &a[i]);
        average += a[i];
    }
    average /= 10;
    for (int i = 0; i < 10; i++) {
        error += (average - a[i]) * (average - a[i]);
    }
    //printf("error: %.4f\n", error);
    if (error > 9) printf("NOT ");
    printf("COMFY");
    return 0;
}