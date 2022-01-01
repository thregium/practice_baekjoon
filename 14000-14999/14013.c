#include <stdio.h>

/*
문제 : A와 B의 교환비가 주어질 때, N(N <= 100000)개의 물음에 답한다. 실수와 A 또는 B가 주어질 때,
A가 주어지면 해당량의 A에 대한 B의 양, B가 주어지면 해당향의 B에 대한 A의 량을 출력한다.

해결 방법 : A에 대한 B의 양은 Z * B / A로 구할 수 있고(Z는 주어진 실수), B에 대한 A의 양은 Z * A / B로 구할 수 있다.

주요 알고리즘 : 수학

출처 : CornH 2016 J번
*/

int main(void) {
    double x, y, z;
    int n;
    char q;
    scanf("%lf %lf", &x, &y);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %c", &z, &q);
        if (q == 'A') printf("%.9f\n", z * y / x);
        else if (q == 'B') printf("%.9f\n", z * x / y);
        else return 1;
    }
    return 0;
}