#include <stdio.h>
#define INF 1012345678
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 50000)���� ���� �̷���� ������ �־�����. �� �������� ��ȣ�� K(K < N) ���Ϸ� ���� ���� ���� ���� ���� ��,
�� ���� ȥ���ϴٰ� �� ��, �������� ȥ���� ���� ū ���� ���Ѵ�. ���ٸ� -1�� ����Ѵ�.
������ ������ 0 �̻� 10^6 ������ �����̴�.

�ذ� ��� : �� ���� ���������� ������ ��ġ�� �迭�� �����Ѵ�. �־��� ���� ��ġ�� K ���Ϸ� ���̰� ���� �ᱣ������
ū ����� �ᱣ���� �����Ѵ�.

�ֿ� �˰��� : ����?

��ó : USACO 2013M B2��
*/

int breed[1048576];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("proximity.in", "r");
        fo = fopen("proximity.out", "w");
    }
    int n, k, x, r = -1;
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= 1000000; i++) breed[i] = -INF;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (i - breed[x] <= k && x > r) r = x;
        breed[x] = i;
    }
    printf("%d", r);
    return 0;
}