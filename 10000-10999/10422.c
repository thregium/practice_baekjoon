#include <stdio.h>
#define DIV 1000000007

/*
문제 : 괄호 문자열의 주변을 괄호로 감싸거나 두 괄호 문자열을 합친 것은 전부 괄호 문자열이라고 할 때 길이가 L인 서로 다른 괄호 문자열의 수를 구한다.

해결 방법 : 길이가 L인 괄호 문자열의 수를 f(L)이라고 하면 f(L) = f(0) * f(L - 2) + f(2) * f(L - 4) + ... + f(L - 2) * f(0)이다.

주요 알고리즘 : 다이나믹 프로그래밍, 수학?
*/

int s[8192];

int bracket(int l) {
     if (s[l]) return s[l];
     else if (l % 2) return 0;
     else if (l == 0) return 1;

     int a = 0;
     for (int i = 0; i <= l - 2; i += 2) {
          a = (a + (long long)bracket(i) * bracket((l - 2) - i)) % DIV;
     }
     return s[l] = a;
}

int main(void) {
     int t, l;
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          scanf("%d", &l);

          printf("%d\n", bracket(l));
     }
     return 0;
}