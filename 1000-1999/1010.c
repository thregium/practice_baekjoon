#include <stdio.h>

/*
���� : ������ ����� ���� �ְ�, �� ���ʿ��� n��, ���ʿ��� m���� ����Ʈ���� �ִ�. �� ����Ʈ�� ���̿� �ϴ��� �������� �ٸ��� �����ϰ�, �ٸ��鳢�� ��ġ�� ���� �� �ٸ��� ���� ����� �������� ���Ѵ�.

�ذ� ��� : �ٸ��� ���� ����� ���� mCn�� ����. mCn = (m-1)C(n-1) + (m-1)Cn�� �����Ƿ� ���̳��� ���α׷����� �̿��� Ǭ��.

�ֿ� �˰��� : ���̳��� ���α׷���
*/

int brid[32][32];

int build(int n, int m) {
     if (brid[n][m]) return brid[n][m];
     if (m == 0) return brid[n][m] = 1;
     if (n == m) return brid[n][m] = 1;
     return brid[n][m] = build(n - 1, m) + build(n - 1, m - 1);
}

int main(void) {
     int t, n, m;
     scanf("%d", &t);
     for (int i = 0; i < t; i++) {
          scanf("%d %d", &n, &m);
          printf("%d\n", build(m, n));
     }
     return 0;
}