#include <stdio.h>

/*
���� : N * M(N, M <= 32) ũ���� �����̸� ���� �Ǵ� ���� �������� T(T <= 20)�� ���´�.
�Ź� ���� �������� ���� ��ġ�� �־����� P(P <= 20)���� ��ġ�� ���� ������ �վ��� ��
������ �� �� �ո� �� ���Ѵ�.

�ذ� ��� : �Ź� ���� �� ���� ����� ��ġ�� Ȯ���ϰ� �� ĭ���� ���̰� ��ģ ������ ���صд�.
�̸� �ݺ��� ���� ������ �ո��� ������ ���̰� ��ģ �����̹Ƿ� �̸� ����ϸ� �ȴ�.
���̰� ��ģ ������ ���� ��, N - C �Ǵ� M - C���� C�� ū ��쿡 �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : JDC 2018 B��
*/

int paper[48][48], temp[48][48];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, m, t, p, d, c;
    while (1) {
        scanf("%d %d %d %d", &n, &m, &t, &p);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) paper[i][j] = 1;
        }
        for (int i = 0; i < t; i++) {
            scanf("%d %d", &d, &c);
            if (d == 1) {
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n - c; j++) temp[i][j] = paper[i][j + c];
                    for (int j = 0; j < c; j++) temp[i][j] += paper[i][c - j - 1];
                }
                n = big(n - c, c);
            }
            else if (d == 2) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m - c; j++) temp[j][i] = paper[j + c][i];
                    for (int j = 0; j < c; j++) temp[j][i] += paper[c - j - 1][i];
                }
                m = big(m - c, c);
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) paper[i][j] = temp[i][j];
            }
            for (int i = 0; i < 48; i++) {
                for (int j = 0; j < 48; j++) temp[i][j] = 0;
            }
            continue;
        }
        for (int i = 0; i < p; i++) {
            scanf("%d %d", &d, &c);
            printf("%d\n", paper[c][d]);
        }
    }
    return 0;
}