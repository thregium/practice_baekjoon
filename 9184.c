#include <stdio.h>

/*
���� : �־��� ����Լ��� ȿ������ �ð� �ȿ� �Ϸ��ϵ��� �ٲ۴�.

�ذ� ��� : �޸������̼��� �̿��� ���� ������ �ϴ� Ƚ���� ���δ�.

�ֿ� �˰��� : ���̳��� ���α׷���
*/

int mem[32][32][32];

int w(int a, int b, int c) {
     if (a <= 0 || b <= 0 || c <= 0) return 1;
     if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
     if (mem[a][b][c]) return mem[a][b][c];
     if (a < b && b < c) return mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
     return mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main(void) {
     while (1) {
          int a, b, c;
          scanf("%d %d %d", &a, &b, &c);
          if (a == -1 && b == -1 && c == -1) break;
          printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
     }
     return 0;
}