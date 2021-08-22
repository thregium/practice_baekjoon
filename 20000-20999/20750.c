#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� LTH ��ȸ ����� �߰� ������ �־��� ��, �� �������� ������ ���Ѵ�. ������ ICPC ����̰�,
������ ���� ������ �̸� �������ִ�. ���� �����ڰ� ������ ��� ������ ����� �ø��Ͽ� ����� ���Ѵ�.

�ذ� ��� : �� �������� ��ȸ ����� �����Ͽ� ������ ���Ѵ�. �� ����, 1������ ������ ���� ������ ���� �����Ѵ�.
�� �������� ������ ���� ó���� ���ش�. �߰� ������ �� ������ ���� ������ ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����

��ó : LTH 2017 I��
*/

int conts[1024][4], r[1024];
int scores[30] = { 100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

int cmp1(const void* a, const void* b) {
    int as = *(int*)a;
    int bs = *(int*)b;
    if (as != bs) return as < bs ? 1 : -1;
    int ap = *((int*)a + 1);
    int bp = *((int*)b + 1);
    if (ap != bp) return ap > bp ? 1 : -1;
    int af = *((int*)a + 2);
    int bf = *((int*)b + 2);
    return af > bf ? 1 : af == bf ? 0 : -1;
}

int main(void) {
    int n, x, s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &conts[i][0], &conts[i][1], &conts[i][2], &x);
        if (x) r[i] = 1;
        conts[i][3] = i;
    }
    conts[n][0] = -1;
    qsort(conts, n, sizeof(int) * 4, cmp1);
    for (int i = 0; i < 30 && i < n; i++) {
        x = i, s = 0;
        while (conts[x][0] == conts[i][0] && conts[x][1] == conts[i][1] && conts[x][2] == conts[i][2]) {
            if (x < 30) s += scores[x];
            x++;
        }
        x--;
        s = (s + (x - i)) / (x - i + 1);
        for (int j = i; j <= x; j++) {
            r[conts[j][3]] += s;
        }
        i = x;
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", r[i]);
    }
    return 0;
}