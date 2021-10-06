#include <stdio.h>

/*
문제 : +- 10^8 이하의 정수와 연산자들이 주어질 때, 우선순위를 무시하고 계산한 결과를 구한다.
연산 중간의 값들은 10^8을 넘지 않으며, 각 연산자들은 프로그래밍 언어에서 쓰이는 그대로 사용하면 된다.

해결 방법 : 현재의 값을 저장하면서 값과 연산자가 주어질 때 마다 연산자에 맞는 연산을 하고 등호가 나오면 결과를 출력하면 된다.

주요 알고리즘 : 수학, 사칙연산

출처 : JOI 2006모2 2번
*/

int main(void) {
    int n = 0, x;
    char c = '+';
    while (1) {
        scanf("%d", &x);
        if (c == '+') n += x;
        else if (c == '-') n -= x;
        else if (c == '*') n *= x;
        else if (c == '/') n /= x;
        else return 1;
        scanf(" %c", &c);
        if (c == '=') {
            printf("%d", n);
            break;
        }
    }
    return 0;
}