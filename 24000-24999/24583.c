#include <stdio.h>
#include <math.h>

/*
���� : R * C(R, C <= 50) ũ���� ���ڿ� ������ �ְų� ����. ���� �ִ� ĭ�� ���η� �� �� ���� ��
(�𼭸��δ� �̵� ����), ���� �� �������� ������ �Ʒ� �������� �̵��ϴ� �� �ɸ��� �ִܰŸ��� ���Ѵ�.
(�ð����� 5��)

�ذ� ��� : ��� ���� / �� �������� ������ / �Ʒ� �������� �̵��ϴ� �ֿ� ����
�̵� ���������� Ȯ���Ѵ�. ���������� ���� ������ ���������� ���� �ִ� ���� Ȯ���ϴ� ����� ����.
�̴� ��� �ֿ��� O(R + C) �ð��� �����ϰ� ���� ������ O(R^2C^2)�̹Ƿ� �ð� ���� ��� Ȯ���� �����ϴ�. 
��� �ֿ� ���� Ȯ�������� ���� �� ������������ ������� ���̳��� ���α׷����� ����
�ִ� �Ÿ��� ���� ������ ���������� ������ �Ʒ� ���������� �Ÿ��� ã���� �ȴ�.

�ֿ� �˰��� : DP, ������

��ó : MidAtl 2021 G�� // NCNA 2021 I��
*/

char car[64][64], cango[64][64][64][64];
double mem[64][64];

int main(void) {
    int r, c;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", car[i]);
    }
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            for (int ii = i; ii <= r; ii++) {
                for (int jj = j; jj <= c; jj++) {
                    if (i == ii || j == jj) {
                        cango[i][j][ii][jj] = 1;
                        continue;
                    }
                    cango[i][j][ii][jj] = 1;
                    for (int k = i; k < ii; k++) {
                        for (int l = j + (jj - j) * (k - i) / (ii - i);
                            l < j + ((jj - j) * (k - i + 1) + (ii - i - 1)) / (ii - i); l++) {
                            if (car[k][l] == '#') cango[i][j][ii][jj] = 0;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i <= r; i++) {
        for (int j = 0; j <= c; j++) {
            if (i + j == 0) continue;
            mem[i][j] = 103000.0;
            for (int ii = 0; ii <= i; ii++) {
                for (int jj = 0; jj <= j; jj++) {
                    if (ii == i && jj == j) continue;
                    if (cango[ii][jj][i][j]) {
                        if (sqrt(pow(i - ii, 2) + pow(j - jj, 2)) + mem[ii][jj] < mem[i][j]) {
                            mem[i][j] = sqrt(pow(i - ii, 2) + pow(j - jj, 2)) + mem[ii][jj];
                        }
                    }
                }
            }
        }
    }
    printf("%.9f", mem[r][c]);
    return 0;
}