#include <stdio.h>
#include <string.h>

/*
문제 : 최대 10000자리의 자연수 A, B가 입력될 때 A + B의 값을 출력한다.

해결 방법 : 각각의 자릿수를 배열로 만들어 맨 뒷 자리부터 순서대로 수를 합한다. 자릿수의 합이 10 이상인 경우에는 캐리를 생각하여 앞자리에 1을 추가해야 한다.
출력시에도 맨 앞 자리의 값이 몇인지 확인이 필요하다.

주요 알고리즘 : 수학?
*/

char a[10240], b[10240], c[10240];

int big(int a, int b) {
     return a > b ? a : b;
}

int main(void) {
     int digits = 0, carry = 0, temp;

     scanf("%s %s", a, b);

     digits = big(strlen(a), strlen(b)) + 1;
     for (int i = 0; i < digits; i++) {
          temp = (i < strlen(a) ? a[strlen(a) - 1 - i] - 48 : 0) + (i < strlen(b) ? b[strlen(b) - 1 - i] - 48 : 0) + carry;
          c[digits - 1 - i] = temp % 10;
          if (temp >= 10) carry = 1;
          else carry = 0;
     }
     for(int i = !c[0]; i < digits; i++) printf("%d", c[i]);
     return 0;
}