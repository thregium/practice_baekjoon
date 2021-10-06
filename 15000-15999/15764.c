#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100)������ �ҵ��� �ִ�. M������ �ҵ��� �־����� ������� ��ġ�Ǿ�� �ϰ�, K������ �ҵ��� �־�����
��ġ�� ��ġ�Ǿ�� �Ѵ�. �� �ҵ��� ��ġ�ϴ� ����� �ݵ�� �ִٰ� �� ��, 1�� �Ұ� ���� �� �ִ� ���� ���� ��ġ�� ���Ѵ�.

�ذ� ��� : ���� �־��� �Ұ� K���� ��� �ϳ����� Ȯ���Ѵ�. �׷��ٸ� �ش��ϴ� ��ġ�� ��ġ�ϸ� �ȴ�.
M���� ��� �ϳ���� M���� ��� 1�� �� ������ ��ġ�� Ȯ���� ���� ���� �Һ��� Ȯ���ϸ� ���� �� ���� M������
�ҵ��� ��ġ�ϸ� 1�� �Ұ� ������ ��ġ�� ã���� �ȴ�.
�� �� �ƴ� ��쿡�� M������ �ҵ��� �������� Ȯ���ϸ� ��ġ�� �� �ִ� ���� ���ʿ� �ҵ��� ��ġ�� ���� ����,
���� ����ִ� ���� ���� ĭ�� 1�� �Ҹ� ��ġ�ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����, ���̽� ��ũ

��ó : USACO 2018O B2��
*/

int order[128], rel[128][2], relchk[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("milkorder.in", "r");
        fo = fopen("milkorder.out", "w");
    }
    int n, m, k, c, p, inc = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &rel[i][0]);
        if (rel[i][0] == 1) inc = i;
        relchk[rel[i][0]] = i;
    }
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &c, &p);
        order[p] = c;
        if (relchk[c]) rel[relchk[c]][1] = p;
        if (c == 1) {
            printf("%d", order[c]); //K���� ��� �ϳ��� ���
            return 0;
        }
    }

    if (inc) {
        while (rel[inc][1] == 0 && inc > 0) inc--;
        p = rel[inc][1];
        inc++;
        while (1) {
            while (order[++p]);
            if (rel[inc][0] == 1) {
                printf("%d", p); //M���� ��� �ϳ��� ���
                return 0;
            }
            inc++;
        }
    }
    else {
        c = m;
        for (int i = n; i > 0 && c > 0; i--) {
            while (c > 0 && rel[c][1]) {
                i = rel[c--][1];
            }
            while (i > 0 && order[i]) i--;
            if (c <= 0 || i <= 0) break;
            order[i] = rel[c][0];
            c--;
        }
        for (int i = 1; i <= n; i++) {
            if (order[i] == 0) {
                printf("%d", i); //�� �� �ƴ� ���
                return 0;
            }
        }
    }

    return 0;
}