#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : �������� N(N <= 100)���� ���� �ִ�. �̶�, �� �������� ���� ����� ��(���� ���� ��� �� �� ���� ���� ��)���� �̵� �����ϴٰ� �� ��,
��� ������ �̵��ϱ� ���� �ʿ��� ������� �ּ� ������ ���Ѵ�.

�ذ� ��� : ������ ������ ���� ��� ���� ���ؼ� �̵� ������ ������ ���� ����صΰ� �� ���鿡 ���� �ش� ������ �����ϰ� �Ǵ� ������ ���� ����صд�.
�׷��� ��� ������ �̵��ϱ� ���� �ʿ��� ������� �ٸ� ������ ������ �� ���� ����� �� 2���� ���� �¹��� ������ �ٸ� ���鿡�� ������ �� ���� ������
��������� �ؾ� �Ѵ�. ���� ���� �������� ���� 0�� �����̰�, ���� ���� ������, �̵��� ���� �������� ��� 1�̰�, 2�� �̵��� ���� ��ġ�� ���ƿ��� ������ �� / 2�̴�.

�ֿ� �˰��� : �׷��� �̷�

��ó : USACO 2018F B2��
*/

int a[128], g[128], in[128];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("hoofball.in", "r");
        fo = fopen("hoofball.out", "w");
    }
    int n, cnt = 0, cnt2 = 0;
    scanf("%d", &n);
    if (n == 1) {
        printf("%d", 1);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i == 0) g[i] = 1;
        else if (i == n - 1) g[i] = n - 2;
        else if (abs(a[i] - a[i - 1]) > abs(a[i] - a[i + 1])) g[i] = i + 1;
        else g[i] = i - 1;
        in[g[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (!in[i]) cnt++;
        else if (in[i] == 1 && in[g[i]] == 1 && g[g[i]] == i) cnt2++;
    }
    if (cnt2 & 1) return 1;
    printf("%d", cnt + (cnt2 >> 1));
    return 0;
}