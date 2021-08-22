#include <stdio.h>

/*
https://www.acmicpc.net/problem/1001

문제 : A와 B가 주어질 때 A - B를 출력한다.

해결 방법 : A와 B를 입력받고 A - B를 출력한다.

주요 알고리즘 : 구현?
*/

int main(void) {
     long long int num1, num2, result;
     scanf("%lld %lld", &num1, &num2);
     result = num1 - num2;
     printf("%lld", result);
     return 0;
}
