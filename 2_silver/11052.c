#include <stdio.h>

/*
���� : n�� ������ p[i](i <= n)�� ���� �־��� �� i�� ���� n���� ���� �� �ִ� i�� ���� ��� p[i]�� ���� ���� ū ������ p[i]�� ���� ���Ѵ�.

�ذ� ��� : n�� ���� m�� ���� �κ� ������ �����Ѵ�. �̶� f(m)�� ���� M(f(m - 1) + p[1], f(m - 2) + p[2], ... f(m - m) + p[m])�� �ȴ�.

�ֿ� �˰��� : ���̳��� ���α׷���
*/

int p[1024], mem[1024];

int main(void) {
     int n, l;
     scanf("%d", &n);
     for (int i = 1; i <= n; i++) {
          scanf("%d", &p[i]);
          l = 0;
          for (int j = 1; j <= n; j++) {
               if (i >= j && mem[i - j] + p[j] > l) l = mem[i - j] + p[j];
          }
          mem[i] = l;
     }
     printf("%d", mem[n]);
     return 0;
}