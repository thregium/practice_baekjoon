#include <stdio.h>
#include <string.h>

/*
문제 : 디지털 카운터의 숫자를 1씩 올릴 때, 선분의 수가 주어지는 숫자의 선분의 수와 같아지는 첫 시점을 구한다. 디지털 카운터에 있는 숫자의 갯수는 입력으로 주어지는 숫자의 갯수와 같다.
입력은 0으로 시작할 수 있고, 모든 숫자가 9가 되면 다시 모든 숫자를 0으로 바꾸고 카운터는 새로 시작한다.

해결 방법 : 먼저 입력받은 자릿수를 통해 카운터의 자릿수를 알아낸다. 그 다음, 카운터의 값에서 시작해서 맨 뒷자리부터 자릿수를 1씩 늘려가며 선분의 갯수를 비교한다.
현재 자릿수까지 확인했을 때 남은 자릿수를 임의로 배치해서 선분의 수가 같아질 수 있는 경우 그 자리에서 카운트를 중단하고 반대 방향으로 이동하기 시작한다.
현재 자릿수에서 발견하지 못한 경우 그 자리를 0으로 바꾸고 자릿수를 한칸 앞으로 옮긴다. 이미 맨 앞자리인 경우 다시 한번 0부터 확인 후 반대 방향으로 이동하기 시작한다.
다시 돌아와서 맨 마지막 자리에 도달하면 현재 상태의 카운터와 원래의 카운터의 수를 비교해 (현재 카운터 - 원래 카운터 + 음수인 경우 10^자릿수)를 출력한다.

주요 알고리즘 : 수학, 다이나믹 프로그래밍?
*/

int numlines[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };

int len;

long long int getdiff(char* a, char* b) {
     long long int an = 0, bn = 0;
     for (int i = 0; i < len; i++) {
          an *= 10;
          bn *= 10;
          an += a[i];
          bn += b[i];
     }
     if(an - bn > 0) return an - bn;
     else {
          long long int r = 1;
          for (int i = 0; i < len; i++) r *= 10;
          an += r;
          return an - bn;
     }
}

int getlines(char* n, int d) {
     int l = 0;
     for (int i = 0; i <= d; i++) l += numlines[n[i]];
     return l;
}

long long int getnum(char* n, int lines) {
     long long int res = 0;
     int d = len - 1;
     char find = 0, p[16];
     for (int i = 0; i < 16; i++) p[i] = n[i];
     while (1) {
          for (int i = p[d] + 1; i < 10; i++) {
               p[d] = i;
               if (lines - getlines(p, d) >= 2 * (len - d - 1) && lines - getlines(p, d) <= 7 * (len - d - 1)) {
                    find = 1;
                    if (getlines(p, len - 1) == lines) {
                         return getdiff(p, n);
                    }
                    break;
               }
          }
          if (find) {
               d++;
          }
          else if (d == 0) {
               p[d] = -1;
               find = 1;
          }
          else {
               p[d] = -1;
               d--;
          }
     }
     return 0;
}

int main(void) {
     int lines = 0;
     long long int result = 0;
     char n[24];
     scanf("%s", &n);
     len = strlen(n);
     for (int i = 0; i < len; i++) {
          n[i] -= 48;
          lines += numlines[n[i]];
     }
     result = getnum(n, lines);
     printf("%lld", result);
     return 0;
}