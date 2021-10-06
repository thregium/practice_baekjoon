#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : ������������ N(N <= 100)ȸ ������ ����� �־�����. �� ���� ���� �� ���� 1, 2, 3���� ǥ�õǰ�, �̴� ����, ����, ��
�� �ϳ���� �� ��, ù ��° ����� ���� ���� �̱⵵�� �����Ͽ��� ���� �̱� Ƚ���� ���Ѵ�.

�ذ� ��� : ����, ����, ���� �����ϴ� ��� ��츦 �õ��غ��� ù ��° ����� ���� ���� �̱� ���� ã���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : USACO 2017J B2��
*/

int hps[128][2];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("hps.in", "r");
        fo = fopen("hps.out", "w");
    }
    int n, r = 0, x, h, p, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &hps[i][0], &hps[i][1]);
    }
    for (h = 1; h <= 3; h++) {
        for (p = 1; p <= 3; p++) {
            if (h == p) continue;
            for (s = 1; s <= 3; s++) {
                if (s != h && s != p) break;
            }
            x = 0;
            for (int k = 0; k < n; k++) {
                if ((hps[k][0] == p && hps[k][1] == h) || (hps[k][0] == s && hps[k][1] == p) || (hps[k][0] == h && hps[k][1] == s)) x++;
            }
            if (x > r) r = x;
        }
    }
    printf("%d", r);
    return 0;
}