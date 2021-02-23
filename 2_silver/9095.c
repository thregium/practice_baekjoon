#include <stdio.h>

/*
���� : �Է����� ������ ���� N�� 1, 2, 3�� �ո����� ���� �� �ִ� �������� ���Ͽ���.

�ذ� ��� : N�� 1, 2, 3�� �ո����� ����� �������� (N - 1) + 1, (N - 2) + 2, (N - 3) + 3�� 3������ �ְ�, �̴� N - 1, N - 2, N - 3�� �������� �հ� �����Ƿ�
���̳��� ���α׷����� ���� ���� �� �ִ�. �̶� �ʱ����� 1(n == 1), 2(n == 2), 4(n == 3)�̴�.

�ֿ� �˰��� : ���̳��� ���α׷���
*/

int mem[16] = { 0, };

int getres(int n) {
     if (mem[n]) return mem[n];
     if (n == 1) return 1;
     if (n == 2) return 2;
     if (n == 3) return 4;
     int a = getres(n - 1) + getres(n - 2) + getres(n - 3);
     mem[n] = a;
     return a;
}

int main(void) {
     int t, n;
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          scanf("%d", &n);
          printf("%d\n", getres(n));
     }
     return 0;
}