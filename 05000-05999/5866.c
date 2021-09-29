#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : ���򼱻� (0, 0)�� �� ���� ���� �ְ�, ������ ���� B(B <= 50000)�� �̵� ���, ���� E(E <= 50000)�� �̵� ����� �־�����.
�̶�, �� ���� �̵��ϸ� ������ �Ǵ� Ƚ���� ���Ѵ�. �� ���� ���� �ӵ��� �����δ�.

�ذ� ��� : �� ���� �̵��� �ùķ��̼��Ѵ�. �� ���� ��ǥ�� �������� ������ ������ ����, ���� ��ǥ�� ���� ���� �����ϰ� ����.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : USACO 2012D B1��
*/

int bessie[51200], elsie[51200];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("greetings.in", "r");
        fo = fopen("greetings.out", "w");
    }
    int b, e, t = 0, r = 0, bm = 0, em = 0, bp = 0, ep = 0, last = 1;
    char c;
    scanf("%d %d", &b, &e);
    for (int i = 0; i < b; i++) {
        scanf("%d %c", &bessie[i], &c);
        if (c == 'L') bessie[i] *= -1; //���� �̵��� ������ ǥ��
    }
    for (int i = 0; i < e; i++) {
        scanf("%d %c", &elsie[i], &c);
        if (c == 'L') elsie[i] *= -1; //���� �̵��� ������ ǥ��
    }

    while (bm < b || em < e) {
        if (bessie[bm] == 0) bm++; //���� �̵����� �Ѿ
        if (bm >= b); //�̵��� ���� ���
        else if (bessie[bm] < 0) {
            //���� �̵�
            bp--;
            bessie[bm]++;
        }
        else if (bessie[bm] > 0) {
            //������ �̵�
            bp++;
            bessie[bm]--;
        }
        else return 1;

        if (elsie[em] == 0) em++; //���� �̵����� �Ѿ
        if (em >= e); //�̵��� ���� ���
        else if (elsie[em] < 0) {
            //���� �̵�
            ep--;
            elsie[em]++;
        }
        else if (elsie[em] > 0) {
            //������ �̵�
            ep++;
            elsie[em]--;
        }
        else return 1;

        t++;
        //printf("%d %d\n", bp, ep);
        if (bp == ep) {
            if (!last) r++;
            //printf("!%d\n", t);
            last = 1;
        }
        else last = 0;
    }
    printf("%d", r);
    return 0;
}