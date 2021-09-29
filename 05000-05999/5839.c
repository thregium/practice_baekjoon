#include <stdio.h>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : �� ���� ���� �޸��⸦ �Ѵ�. �� ���� N(N <= 1000)���� M(M <= 1000)���� ������ ���� �޸���.
�� �������� �� ���ڴ� �־��� �ð����� �־��� �ӵ��� �޸���. �̶�, ������ �� ȸ �Ͼ���� ���Ѵ�.
�� ���� ������ �ð��� �׻� ����. ����, �־��� �簣�� �ӵ��� �� �� 1000 ������ �ڿ����̴�.

�ذ� ��� : �� ���� �������� �ùķ��̼��ϸ� �� ���� �� �ռ����� �� ���� ���������� �ռ����� ����� �ٸ��ٸ�
�ᱣ���� 1�� ���Ѵ�. �޸��Ⱑ ������ �ᱣ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : USACO 2013M B1��
*/

int bessie[1024][2], elsie[1024][2];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("cowrace.in", "r");
        fo = fopen("cowrace.out", "w");
    }
    int n, m, t = 0, bp = 0, ep = 0, bs = 0, es = 0, last = 0, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &bessie[i][0], &bessie[i][1]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &elsie[i][0], &elsie[i][1]);
    }

    while (bs < n || es < m) {
        if (bessie[bs][1] == 0) bs++;
        bessie[bs][1]--;
        bp += bessie[bs][0];
        if (elsie[es][1] == 0) es++;
        elsie[es][1]--;
        ep += elsie[es][0];

        if (bp > ep) {
            if (last == 2) r++;
            last = 1;
        }
        else {
            if (last == 1) r++;
            last = 2;
        }

        t++;
    }
    printf("%d", r);
    return 0;
}