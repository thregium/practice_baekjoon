#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : N(N <= 1000)���� ���� ���̰� �־��� ��, ������ �ִ� ���̿� �ּ� ���� ���̸� 17 ���Ϸ� �Ϸ��� �� ����
�ּ� ����� ���Ѵ�. ������ ���̸� �ٲ� ���� ����� (���� ���̿��� ����)^2�̴�. �� ������ ���̴� 0 �̻� 100 ������ �����̴�.

�ذ� ��� : �� ������ ���� ������ �ſ� �۱� ������ ��� ������ ���̿� ���ؼ� ����� ����ϰ� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : USACO 2014J B1��
*/

int elev[1024];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("skidesign.in", "r");
        fo = fopen("skidesign.out", "w");
    }
    int n, r = INF, t = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &elev[i]);
    }
    for (int e = 0; e <= 83; e++) {
        t = 0;
        for (int i = 0; i < n; i++) {
            if (elev[i] < e) t += (e - elev[i]) * (e - elev[i]);
            else if (elev[i] > e + 17) t += (elev[i] - e - 17) * (elev[i] - e - 17);
        }
        if (t < r) r = t;
    }
    printf("%d", r);
    return 0;
}