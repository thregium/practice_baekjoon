#include <stdio.h>

/*
���� : �Ͼ� ���� ��ü ����� n*n���� ���簢������ ������ �߾��� k*k���� ���簢���� �˰� ĥ�Ѵ�. �̰��� s�� �ݺ��Ͽ��� �� r1�� c1������ r2�� c2�������� ����� ����Ѵ�.

�ذ� ��� : (r1, c1)���� (r2, c2)������ ��ǥ�� ���� (r, c)�� (n^(s-1))�� ���� ���� n���� ���� �������� k ���� �ȿ� �ִٸ� 1�� ��ȯ�ϰ� ���ٸ� �ٽ� s���� 1�� ���� �ٽ� �ݺ��Ѵ�.
���⼭ k�� ������ (n - k) / 2 <= r, c < (n + k) / 2�̴�. �׸��� s�� 0�� �� ��쿡�� 0�� ��ȯ�Ѵ�.

�ֿ� �˰��� : ���� ����
*/

int fractal(int s, int n, int k, int r, int c) {
     //�ش� ������ ������ ��ȯ
	 if (s == 0) {
          return 0;
     }
     int rx = r, cx = c;
     for (int i = 1; i < s; i++) {
          rx /= n;
          cx /= n;
     }
     if (rx % n >= (n - k) / 2 && cx % n >= (n - k) / 2 && rx % n < (n + k) / 2 && cx % n < (n + k) / 2) {
          return 1;
     }
     else return fractal(s - 1, n, k, r, c);
}

int main(void) {
     int s, n, k, r1, r2, c1, c2;
     int res[60][60] = { 0, };
     scanf("%d %d %d %d %d %d %d", &s, &n, &k, &r1, &r2, &c1, &c2);
     for (int r = r1; r <= r2; r++) {
          for (int c = c1; c <= c2; c++) {
               res[r - r1][c - c1] = fractal(s, n, k, r, c);
               printf("%d", res[r - r1][c - c1]);
          }
          printf("\n");
     }
     return 0;
}