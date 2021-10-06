#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100000)���� ������ ���ʷ� �̵��ϵ�, �߰��� �ִ� �� ��(ù ���� ������ ���� ����)�� �ǳʶٷ��� �Ѵ�.
�Ÿ� ������ ����ư �Ÿ���� �̵��ϴµ� �ɸ��� �ִܰŸ��� ���Ѵ�. ��� ���� ��ǥ�� +- 1000 ������ �����̴�.

�ذ� ��� : �� �Ÿ��� ��� ���� �̵��ϴµ� �ɸ��� �Ÿ����� �� ���� ���� �̵��Ͽ� ����Ǵ� �Ÿ��� �� ���� ����.
����, ��� ���� �̵��ϴµ� �ɸ��� �Ÿ��� ���� ����, ��� �ִ� ��� ���� ���� �� ���� ���� �̵��Ͽ�
����Ǵ� �Ÿ��� ��� ���� ū ���� ���ϰ� ù ��° ������ �� ��° ���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : USACO 2014D B1��
*/

int pos[103000][2];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("marathon.in", "r");
        fo = fopen("marathon.out", "w");
    }
    int n, sum = 0, best = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        if (i > 0) sum += abs(pos[i][0] - pos[i - 1][0]) + abs(pos[i][1] - pos[i - 1][1]);
    }
    for (int i = 1; i + 1 < n; i++) {
        best = big(best, (abs(pos[i + 1][0] - pos[i][0]) + abs(pos[i + 1][1] - pos[i][1]))
            + (abs(pos[i - 1][0] - pos[i][0]) + abs(pos[i - 1][1] - pos[i][1]))
            - (abs(pos[i + 1][0] - pos[i - 1][0]) + abs(pos[i + 1][1] - pos[i - 1][1])));
    }
    printf("%d", sum - best);
    return 0;
}