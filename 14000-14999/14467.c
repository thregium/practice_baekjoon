#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : �� 10������ ���� ����� N(N <= 100)ȸ �־�����. �̶�, ���� ��ġ�� 0 �Ǵ� 1���̶�� �ҵ��� ��ġ�� �ٲ� �ּ� Ƚ���� ���Ѵ�.

�ذ� ��� : �ҵ��� ó�� ������ �ʾҴٸ� ���������� ������ ��ҿ� ���� ������ �����ߴ��� Ȯ���ϰ� �ƴ϶��
�ݵ�� ��Ҹ� �̵��� ���̴�. �̷��� ����� Ƚ���� ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : USACO 2017F B1��
*/

int cows[16];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("crossroad.in", "r");
        fo = fopen("crossroad.out", "w");
    }
    int n, r = 0, c, p;
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++) cows[i] = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &p);
        if (cows[c] < 0) cows[c] = p;
        else if (cows[c] != p) {
            r++;
            cows[c] = p;
        }
    }
    printf("%d", r);
    return 0;
}