#include <stdio.h>

/*
문제 : 혼합물을 만들기 위해 구해온 재료 3개와 세 재료의 배합비가 주어질 때,
혼합물을 최대한 만들고 남은 재료의 양을 각각 구한다.

해결 방법 : 만들 수 있는 가장 많은 재료의 양은 세 재료 가운데 하나 이상을 전부 쓸 때 까지 혼합물을 만들 때의 양이다.
세 재료 각각만 있다고 할 때의 배수를 구한 다음, 가장 작은 배수를 기준으로 만들고 남은 재료의 양을 구하면 된다.

주요 알고리즘 : 수학

출처 : COCI 09/10#5 1번
*/

int main(void) {
    double a, b, c, i, j, k, x, y, z;
    scanf("%lf %lf %lf%lf %lf %lf", &a, &b, &c, &i, &j, &k);
    x = a / i;
    y = b / j;
    z = c / k;
    if (x < y && x < z) printf("%lf %lf %lf", 0.0, b - x * j, c - x * k);
    else if (y < x && y < z) printf("%lf %lf %lf", a - y * i, 0.0, c - y * k);
    else printf("%lf %lf %lf", a - z * i, b - z * j, 0.0);
    return 0;
}