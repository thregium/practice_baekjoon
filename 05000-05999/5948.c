#include <stdio.h>

/*
문제 : 네 자리 자연수 N이 주어질 때, N의 백의 자릿수와 십의 자릿수를 떼서 제곱한 수가 이전에 나온 수가 되기까지
몇 번의 해당 연산이 필요한지 구한다.

해결 방법 : 연산 이후의 수는 100가지밖에 없으므로 최대 100회 안에는 연산이 끝나게 된다. 따라서, 시뮬레이션을 통해
각 연산의 결과를 매번 확인하는 것 만으로도 충분하다.

주요 알고리즘 : 수학, 사칙연산, 시뮬레이션

출처 : USACO 2010D B2번
*/

int traces[10240];

int main(void) {
    int n, m;
    scanf("%d", &n);
    traces[0] = n;
    for (int i = 1;; i++) {
        m = n / 10 % 100;
        for (int j = 0; j < i; j++) {
            if (m * m == traces[j]) {
                printf("%d", i);
                return 0;
            }
        }
        n = m * m;
        traces[i] = n;
    }
    return 0;
}