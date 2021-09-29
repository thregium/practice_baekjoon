#include <stdio.h>
#include <stdlib.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 15)������ �ҵ��� �ְ�, �� �ҵ��� 3 ���� ǰ�� ��� �ϳ��̴�. �� �ҵ� ���� ���� ǰ������ ���η�
���ǵ��� �־��� ��, �ҵ��� ǰ������ �� �� �ִ� ����� ���� ���Ѵ�.

�ذ� ��� : ��Ʈ��ŷ�� ���� �� �ҵ��� ǰ���� �ϳ��� Ȯ���ϸ� ��������� ���ǿ� �´��� ���Ѵ�.
�ҵ��� ǰ���� �� �� �ִ����� �̸� ������ ���� ��ó���� ���� �� �� ������ ���ϴ� ���� �ʿ��ϴ�.

�ֿ� �˰��� : ��Ʈ��ŷ

��ó : USACO 2013M B3��
*/

int breed[16], rel[64][3];
int r = 0;

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    int aj = *((int*)a + 1);
    int bj = *((int*)b + 1);
    return big(ai, aj) > big(bi, bj) ? 1 : big(ai, aj) == big(bi, bj) ? 0 : -1;
}

void track(int n, int x, int k) {
    for (int i = 0; i < k; i++) {
        if (rel[i][0] > x || rel[i][1] > x) break;
        if (rel[i][2] != (breed[rel[i][0]] != breed[rel[i][1]])) return;
    }
    if (n == x) {
        r++;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        breed[x + 1] = i;
        track(n, x + 1, k);
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("assign.in", "r");
        fo = fopen("assign.out", "w");
    }
    int n, k;
    char c;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf(" %c %d %d", &c, &rel[i][0], &rel[i][1]);
        if (c == 'D') rel[i][2] = 1;
    }
    qsort(rel, k, sizeof(int) * 3, cmp1);

    track(n, 0, k);
    printf("%d", r);
    return 0;
}