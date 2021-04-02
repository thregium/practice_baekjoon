#include <stdio.h>

/*
문제 : 끝자리가 1, 3, 7, 9 중 하나인 10자리 이하의 숫자 S가 있다. S와 같거나 S보다 적은 자릿수를 갖는 수 가운데 세제곱하여 뒤쪽 자릿수가 S와 같은 수를 찾는다.

해결 방법 : S의 자릿수와 같거나 적은 자릿수를 갖고 세제곱하여 S로 끝나는 자연수는 모든 경우 유일하므로 맨 뒷 자리부터 순서대로 세제곱하여 S로 끝나는지 여부를 확인한다.
단, S가 10자리인 경우 10번째 자리는 제곱시 long long의 범위를 넘어가기 때문에 9번째 자리의 세제곱 값의 10번째 자리와
확인하고자 하는 값의 10번째 자리 * S의 맨 뒷자리^2 * 3을 더한 수의 마지막 자리를 S의 10번째 자리와 비교하여 확인한다.

주요 알고리즘 : 정수론, 백트래킹
*/

long long int cubd(long long int s, long long int p, int d, int f) {
     if (d == f) return p;
     long long int g = 1, q1 = 0, q2 = 0;
     for (int i = 0; i <= f; i++) g *= 10;

     if (f == 9) {
          q1 = (((p % (g / 10)) * (p % (g / 10)) % (g / 10) * (p % (g / 10))) / (g / 10) % 10);
          q2 = ((p % (g / 10) * (p % (g / 10)) / (g / 10) % 10 * (p % 10)) % 10);
     }

     for (int i = 0; i < 10; i++) {
          if (f == 9) {
               if ((s * 10 / g) == (q1 + q2 + ((p * 10 / g) * (s % 10) * (s % 10) * 3)) % 10) {
                    break;
               }
          }
          else if ((p % g * p % g) % g * p % g == s % g) {
               break;
          }
          p += g / 10;
     }
     cubd(s, p, d, f + 1);
}

int main(void) {
     long long int t, s, d;
     scanf("%lld", &t);
     for (int i = 0; i < t; i++) {
          scanf("%lld", &s);
          d = 0;
          for (long long int j = s; j > 0; j /= 10) d++;
          printf("%lld\n", cubd(s, 0, d, 0));
     }
     return 0;
}