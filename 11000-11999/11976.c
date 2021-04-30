#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : �����, �ǹ�, ���, �÷��ͳ� Ƽ� �ְ�, ���� �����ϴ� ����� ������ �����Ѵٰ� �Ѵ�.
�� Ƽ��� ���� ����� �ֱ� ������ �����ڼ��� �־�����, �� Ƽ��� �ش� �������� Ƽ� ���� ����� ���� ����Ѵ�.

�ذ� ��� : ���� ���� Ƽ����� ������� ������ ���� �þ ��� ���� Ȯ���Ѵ�.
�� ����, �Ʒ� Ƽ���� ���� �ο����� �� ����ŭ�� ���ش�. ������ Ƽ��� �ش��ϴ� �ο���ŭ�� ���� Ƽ��� �ö󰬱� �����̴�.
�̸� �ݺ��ϸ� �� ������ Ƽ� ���� ����� ���� �� �� �ִ�.

�ֿ� �˰��� : ����

��ó : USACO 2016J B1��
*/

int rank[4][2], prom[3];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("promote.in", "r");
        fo = fopen("promote.out", "w");
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d %d", &rank[i][0], &rank[i][1]);
    }
    for (int i = 2; i >= 0; i--) {
        prom[i] = rank[i + 1][1] - rank[i + 1][0];
        rank[i][0] -= prom[i];
    }
    for (int i = 0; i < 3; i++) printf("%d\n", prom[i]);
    return 0;
}