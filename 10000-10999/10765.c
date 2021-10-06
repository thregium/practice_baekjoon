#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : B, E, S, I, G, O, M�̶�� ������ �� �� �ִ� ������ ���� �ִ� 20������ �־�����.
�̶�, (B+E+S+S+I+E)(G+O+E+S)(M+O+O)��� ���� ����� ¦���� �Ǵ� ����� ���� ���Ѵ�.

�ذ� ��� : ������ �������� ���� Ȧ���� �Ǵ� ��츸 �����ϸ� ����� ¦���� �ȴ�. ��� ����� ����
��� ������ �������� ���� �Ͱ� ����. ������ �������� ���캸�� ù ��° �Ŀ����� E�� S�� 2���� �־� �׻� ¦���� ���̹Ƿ�
B�� I�� ���� Ȧ���̸� Ȧ���� �ȴ�. �� ��°������ ��� ���� ���� Ȧ���̸� Ȧ���� �ǰ�, �������� M�� Ȧ���̸� Ȧ���� �ȴ�.
������ ���� ���Ʈ ������ ���� ����� ���� ���ϰ�, �� ��츦 ���� ���� ��� Ȧ���� ����� ���� �ȴ�.
��ü ��쿡�� Ȧ���� ����� ���� ���� ¦���� ����� ���� �� ���̴�.

�ֿ� �˰��� : ����, ���շ�

��ó : USACO 2015O B2��
*/

int vari[7][32];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("geteven.in", "r");
        fo = fopen("geteven.out", "w");
    }
    int n, v, r = 1, m1 = 0, m2 = 0, m3 = 0;
    char c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %d", &c, &v);
        if (c == 'B') vari[0][++vari[0][0]] = v;
        else if (c == 'E') vari[1][++vari[1][0]] = v;
        else if (c == 'S') vari[2][++vari[2][0]] = v;
        else if (c == 'I') vari[3][++vari[3][0]] = v;
        else if (c == 'G') vari[4][++vari[4][0]] = v;
        else if (c == 'O') vari[5][++vari[5][0]] = v;
        else if (c == 'M') vari[6][++vari[6][0]] = v;
        else return 1;
    }
    for (int i = 0; i < 7; i++) {
        r *= vari[i][0];
    }
    for (int i = 1; i <= vari[6][0]; i++) {
        if (vari[6][i] & 1) m1++;
    }
    for (int i = 1; i <= vari[1][0]; i++) {
        for (int j = 1; j <= vari[2][0]; j++) {
            for (int k = 1; k <= vari[4][0]; k++) {
                for (int l = 1; l <= vari[5][0]; l++) {
                    if ((vari[1][i] + vari[2][j] + vari[4][k] + vari[5][l]) & 1) m2++;
                }
            }
        }
    }
    for (int i = 1; i <= vari[0][0]; i++) {
        for (int j = 1; j <= vari[3][0]; j++) {
            if ((vari[0][i] + vari[3][j]) & 1) m3++;
        }
    }
    printf("%d", r - m1 * m2 * m3);
    return 0;
}