#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100)���� �������� �̷���� ���� Ʈ������ ��� �������� ���� ������ ��尡 �ִ��� ã�� �ִٸ� �� �� ���� ���� ���� ����Ѵ�.

�ذ� ��� : �׷����� ����Ŭ�� �������� �����Ƿ� �� �������� ����ϴ� �ٸ� ��忡���� �� �������� �ٽ� ���ƿ� �� ����.
����, ����ϴ� ������ ���� ��尡 �������� ��� ���ΰ����� ������ �Ұ����ϴ�. ����, ����ϴ� ������ ���� ��尡 1���� ���
�� ��尡 ��� �������� ���� ������ ��������� �׷��� ��尡 2�� �̻��� ��� ��� �������� ���� ������ ���� ����.
�׷��� ��尡 0���� ���� �׷��� Ư���� ���簡 �Ұ����ϴ�.

�ֿ� �˰��� : �׷��� �̷�

��ó : USACO 2019O B2��
*/

int cnt[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("factory.in", "r");
        fo = fopen("factory.out", "w");
    }
    int n, a, b, r = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        cnt[a]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) r++;
    }
    if (r == 1) {
        for (int i = 1; i <= n; i++) {
            if (!cnt[i]) {
                printf("%d", i);
            }
        }
    }
    else printf("%d", -1);
    return 0;
}