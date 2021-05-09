#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N * N(N <= 1000)ũ���� �簢�� �ȿ� �ִ� ��� 2 * 2 �簢���� �ҵ��� 2������ �ֵ��� �ҵ��� ��ġ�Ϸ� �Ѵ�.
�� ������ ��ġ�� �־��� ��, �ҵ��� �ִ� ������ ��ġ ���� ���� ũ���� ��ġ���� ���� ��ġ�� ���Ѵ�.

�ذ� ��� : �簢�� �� �� ���� �簢������ ��ġ�ϸ� �� ���� ���� �� �ٰ� ������ �ݴ�� ��ġ�ؾ� ��� 2 * 2 �簢���� �ҵ��� 2������ ��ġ�� �� �ִ�.
�̸� �ݺ��ϸ� ù �� ���� ��ġ�� �ݺ��ϰ� �ǰ�, ���ο� ������ 2���� ��찡 �ִ�. ����, ���ο� ���ο� ���� �� �پ� �ݺ��� ������ ����,
N���� ĭ�� ���� �� ū ���� ���� ���� ���� ���ϸ�, ���ο� ������ ��쿡�� ���� ū ���� ���� �� �ְ�, �� �� �� ū ���� ���� ū ���� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����, �ֵ� Ȥ

��ó : USACO 2021J S3��
*/

int b[1024][1024], ver[2][1024], hor[1024][2];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("f.in", "r");
        fo = fopen("f.out", "w");
    }
    int n, v = 0, h = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
            ver[i & 1][j] += b[i][j];
            hor[i][j & 1] += b[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        v += big(ver[0][i], ver[1][i]);
        h += big(hor[i][0], hor[i][1]);
    }
    printf("%d", big(v, h));
    return 0;
}