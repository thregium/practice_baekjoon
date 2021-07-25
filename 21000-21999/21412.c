#include <stdio.h>

/*
문제 : 분모와 분자의 합이 N(N <= 1000)이며 가분수가 아닌 가장 큰 기약분수를 찾는다.

해결 방법 : 분모가 N / 2 + 1일 때 부터 모든 수에 대해 분모와 분자의 최대공약수가 1인지 확인한다.
1인 분수가 나오면 그 분수를 출력하고 프로그램을 종료한다. 분자가 1인 경우 항상 기약분수이므로 그러한 수를 찾지 못하는 경우는 없다.

주요 알고리즘 : 수학, 정수론, 유클리드 호제법

출처 : ROI 2007H D번
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = n / 2 + 1; i < n; i++) {
        if (gcd(i, n - i) > 1) continue;
        printf("%d %d", n - i, i);
        break;
    }
    return 0;
}