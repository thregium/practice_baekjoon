#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : 10 * 10 ũ���� ���ڿ� ���� �ٸ� �� ���� B, R, L�� �ִٰ� �Ѵ�.
���ڰ� �־��� �� B���� L�� �ִܰŸ��� ������ �� �������� �ϴ� ĭ�� ���� ����Ѵ�. ��, B�� L�� �������� �ʴ´�. ����, R�� �ִ� �������δ� �� �� ����.

�ذ� ��� : ���ڿ��� B, R, L�� ��ǥ�� ���� ã�´�. ���� R�� �����̳� �������� B�� L ���̿� �ִ� ��� 2ĭ ��ȸ�ؾ� �ϰ�,
�׷��� ���� ��� �ִܰ�η� �� �� �ִ�. �ִ� �Ÿ��� �� ��ǥ�� ���밪�� ���̷� ���� �� �ִ�. ���⼭�� �� ���� �������� �����Ƿ� �� ������ 1�� �پ���.

�ֿ� �˰��� : ����, ���̽� ��ũ

��ó : USACO 2019O B1��
*/

char map[16][16];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("buckets.in", "r");
        fo = fopen("buckets.out", "w");
    }
    int bx = -1, by = -1, rx = -1, ry = -1, lx = -1, ly = -1;
    for (int i = 0; i < 10; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 'B') {
                bx = i;
                by = j;
            }
            if (map[i][j] == 'R') {
                rx = i;
                ry = j;
            }
            if (map[i][j] == 'L') {
                lx = i;
                ly = j;
            }
        }
    }
    if ((bx == lx && bx == rx && ((ry < by && ry > ly) || (ry > by && ry < ly))) || (by == ly && by == ry && ((rx < bx && rx > lx) || (rx > bx && rx < lx)))) {
        //L, R, B�� ��� ������ �����鼭, R�� L�� B ���̿� �ִ� ��� (�̷��� ���� ����)
        printf("%d", abs(bx - lx) + abs(by - ly) + 1); //2ĭ ��ȸ�ؾ� �Ѵ�.
    }
    else {
        printf("%d", abs(bx - lx) + abs(by - ly) - 1); //�ִ� ��η� �� �� �ִ�.
    }
    return 0;
}