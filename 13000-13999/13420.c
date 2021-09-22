#include <stdio.h>

/*
문제 : 사칙연산 식이 주어질 때, 이 식이 맞는지 구한다.

해결 방법 : 식의 연산자에 따라 경우를 나누어 확인하면 된다.

주요 알고리즘 : 수학, 구현

출처 : 국민대 2016 H번
*/

int main(void) {
    int t;
    long long a, b, r;
    char c;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld %c %lld = %lld", &a, &c, &b, &r);
        if (c == '+') printf("%s\n", a + b == r ? "correct" : "wrong answer");
        else if (c == '-')printf("%s\n", a - b == r ? "correct" : "wrong answer");
        else if (c == '*')printf("%s\n", a * b == r ? "correct" : "wrong answer");
        else if (c == '/')printf("%s\n", a / b == r ? "correct" : "wrong answer");
        else return 1;
    }
    return 0;
}