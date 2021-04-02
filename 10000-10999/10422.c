#include <stdio.h>
#define DIV 1000000007

/*
���� : ��ȣ ���ڿ��� �ֺ��� ��ȣ�� ���ΰų� �� ��ȣ ���ڿ��� ��ģ ���� ���� ��ȣ ���ڿ��̶�� �� �� ���̰� L�� ���� �ٸ� ��ȣ ���ڿ��� ���� ���Ѵ�.

�ذ� ��� : ���̰� L�� ��ȣ ���ڿ��� ���� f(L)�̶�� �ϸ� f(L) = f(0) * f(L - 2) + f(2) * f(L - 4) + ... + f(L - 2) * f(0)�̴�.

�ֿ� �˰��� : ���̳��� ���α׷���, ����?
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