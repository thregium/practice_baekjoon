#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100)���� ������ ���� �׷������� ������ ������ ���� �ٸ��� �Ϸ��� �Ѵ�. �̶� ������ ĥ�ϴ� ��� �� ���������� ���� �ռ� ���� ã�´�.
��, �� ������ �ִ� 3�������� ������ ������.

�ذ� ��� : ���� �� ������ ����� �ٸ� �������� ���� Ȯ���Ѵ�. �� ����, �������� ��ȣ ������� ���鼭 ������ ������ ���� �� ��
���� ���� ��ȣ�� ���� ������ ĥ�ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �׸��� �˰���

��ó : USACO 2019F B2��
*/

int link[128][3], r[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("revegetate.in", "r");
        fo = fopen("revegetate.out", "w");
    }
    int n, m, a, b, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        for (int j = 0; j < 3; j++) {
            if (!link[a][j]) {
                link[a][j] = b;
                break;
            }
        }
        for (int j = 0; j < 3; j++) {
            if (!link[b][j]) {
                link[b][j] = a;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            t = 1;
            for (int k = 0; k < 3; k++) {
                if (r[link[i][k]] == j) {
                    t = 0;
                    break;
                }
            }
            if (t) {
                r[i] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d", r[i]);
    }
    return 0;
}