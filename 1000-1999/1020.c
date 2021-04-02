#include <stdio.h>
#include <string.h>

/*
���� : ������ ī������ ���ڸ� 1�� �ø� ��, ������ ���� �־����� ������ ������ ���� �������� ù ������ ���Ѵ�. ������ ī���Ϳ� �ִ� ������ ������ �Է����� �־����� ������ ������ ����.
�Է��� 0���� ������ �� �ְ�, ��� ���ڰ� 9�� �Ǹ� �ٽ� ��� ���ڸ� 0���� �ٲٰ� ī���ʹ� ���� �����Ѵ�.

�ذ� ��� : ���� �Է¹��� �ڸ����� ���� ī������ �ڸ����� �˾Ƴ���. �� ����, ī������ ������ �����ؼ� �� ���ڸ����� �ڸ����� 1�� �÷����� ������ ������ ���Ѵ�.
���� �ڸ������� Ȯ������ �� ���� �ڸ����� ���Ƿ� ��ġ�ؼ� ������ ���� ������ �� �ִ� ��� �� �ڸ����� ī��Ʈ�� �ߴ��ϰ� �ݴ� �������� �̵��ϱ� �����Ѵ�.
���� �ڸ������� �߰����� ���� ��� �� �ڸ��� 0���� �ٲٰ� �ڸ����� ��ĭ ������ �ű��. �̹� �� ���ڸ��� ��� �ٽ� �ѹ� 0���� Ȯ�� �� �ݴ� �������� �̵��ϱ� �����Ѵ�.
�ٽ� ���ƿͼ� �� ������ �ڸ��� �����ϸ� ���� ������ ī���Ϳ� ������ ī������ ���� ���� (���� ī���� - ���� ī���� + ������ ��� 10^�ڸ���)�� ����Ѵ�.

�ֿ� �˰��� : ����, ���̳��� ���α׷���?
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