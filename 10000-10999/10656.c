#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N * M(N, M <= 50) ũ���� ���ڸ�Ǯ�̰� �ִ�. �� ���ڸ�Ǯ�̿��� �ܼ��� �ִ� ĭ�� ������ ������ ��ġ�� ����Ѵ�.
�ܼ��� �ִ� ĭ�� ���� �Ǵ� ���η� ���� ĭ�� �����ְ� ���ķ� 2ĭ �̻��� ����ִ� ����̴�.
�� ��ġ�� ����->���� ������ ���������� �Ǿ�� �Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�. �� �� -> �� ������ Ž���ϰ� �ܼ��� ���� �� �ִ��� ���ϸ� �ȴ�.

�ֿ� �˰��� : ����

��ó : USACO 2014D B2��
*/

char cw[64][64];
int clue[4096][2];
int cp = 0;

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("crosswords.in", "r");
        fo = fopen("crosswords.out", "w");
    }
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", cw[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cw[i][j] == '#') continue;
            if (((j == 0 || cw[i][j - 1] == '#') && (cw[i][j + 1] == '.') && (cw[i][j + 2] == '.'))
                || ((i == 0 || cw[i - 1][j] == '#') && (cw[i + 1][j] == '.') && (cw[i + 2][j] == '.'))) {
                clue[cp][0] = i + 1;
                clue[cp++][1] = j + 1;
            }
        }
    }
    printf("%d\n", cp);
    for (int i = 0; i < cp; i++) {
        printf("%d %d\n", clue[i][0], clue[i][1]);
    }
    return 0;
}