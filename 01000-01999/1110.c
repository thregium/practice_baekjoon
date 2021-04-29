#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*
문제 : 두 자릿수가 주어질 때, 주어진 수의 오른쪽 자리와 자릿수 합의 오른쪽 자리를 붙여 새로운 수를 만드는 연산을 반복하면
몇 번만에 원래 수로 돌아오는지를 출력한다. (앞 자리에는 0이 올 수 있다.)

해결 방법 : 두 자릿수이므로 아무리 많이 하더라도 100번 이내에는 돌아올 수 있다. 따라서, 브루트 포스로 돌아올 때 까지
연산을 반복하다 보면 답을 알 수 있다.

주요 알고리즘 : 구현, 브루트 포스
*/

int main(void) {
     int n, t, s = 0;
     scanf("%d", &n);
     t = n;
     while ((n != t) || (!s)) {
          t = (t % 10) * 10 + (t / 10 + t % 10) % 10; //문제에 주어진 연산
          s++;
     }
     printf("%d", s);
     return 0;
}