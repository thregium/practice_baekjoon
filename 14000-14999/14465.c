#include <stdio.h>
#define INF 1012345678
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 100000)���� �Ϸķ� �þ ��ȣ�� ��� B���� ��ȣ���� ���峪 �ְ�, �� ���峭 ��ȣ���� ��ġ�� �־����ٸ�
���ӵ� K���� ��ȣ���� ���峪�� ���� ���·� ����� ���ؼ��� �ּ� �� ���� ��ȣ���� ���ľ� �ϴ��� ���Ѵ�.

�ذ� ��� : ���峭 ��ȣ���� ���� ���� ������ ��, K��°���� 1ĭ�� �̵��ϸ� i - k��°�� ���� �հ��� �񱳸� ���� �ش� ������
���峭 ��ȣ�� ���� ���� �����ش�. ���峭 ��ȣ���� ���� ���� �������� ���峭 ��ȣ����� ��ġ�� �ȴ�.

�ֿ� �˰��� : ���� ��, �����̵� ������

��ó : USACO 2017F S2��
*/

int broken[103000], sum[103000];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("maxcross.in", "r");
        fo = fopen("maxcross.out", "w");
    }
    int n, k, b, x, best = INF;
    scanf("%d %d %d", &n, &k, &b);
    for (int i = 0; i < b; i++) {
        scanf("%d", &x);
        broken[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + broken[i];
    }
    for (int i = k; i <= n; i++) {
        if (sum[i] - sum[i - k] < best) best = sum[i] - sum[i - k];
    }
    printf("%d", best);
    return 0;
}