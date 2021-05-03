#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100)���� ���� �̷���� �������� ���ĵ��� ���� ���� �ϳ� �ִ�. �� ������ ���ĵ� ���·� ����� ���ؼ� ��ȯ ������ �ּ� �� ȸ �ʿ����� ���Ѵ�.

�ذ� ��� : ���ĵ��� ���� ���� �� ���� ���� ���� ��� �� ������ �۰ų� ��� �� ������ ũ��.
�׷���, �������� �׷��� ���� 2���� �����ϱ� ������ ��� ������ �˱� �������, �ּ� �̵� Ƚ���� �� �� ���� ���ĵ��� ���� ���̱� ������
�� ��� ��� �õ��غ��� �ȴ�. �ּ� �̵� Ƚ���� ���ĵ��� ���� ���� ��ġ���� ���� �־�� �� ��ġ ���̿� �ִ� ���� ������ ����.

�ֿ� �˰��� : �׸��� �˰���, �ֵ� Ȥ

��ó : USACO 2018J B3��
*/

int a[128];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("outofplace.in", "r");
        fo = fopen("outofplace.out", "w");
    }
    int n, x = 0, y = 0, c = 0, d = 0;
    scanf("%d", &n);
    a[n + 1] = 1234567;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) x = i;
        else if (a[i] < a[i - 1] && a[i] < a[i + 1]) y = i;
    }
    if (x) {
        for (int i = x + 1; a[i] < a[x]; i++) {
            if (a[i - 1] != a[i]) c++;
        }
    }
    if(y) {
        for (int i = y - 1; a[i] > a[y]; i--) {
            if (a[i + 1] != a[i]) d++;
        }
    }
    printf("%d", c > d ? c : d);
    return 0;
}