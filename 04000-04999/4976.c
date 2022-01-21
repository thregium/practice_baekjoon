#include <stdio.h>
#include <stdlib.h>

/*
���� : W * D(W, D <= 100) ũ���� �ɟ��� N(N <= 100)�� �߶���. �Ź� �ڸ� ������ P_i�� ������ ���� ��
���������� S_i��ŭ �ð�������� �̵��� ������ �������� �ڸ���. �װ��� ��ġ�� �������� �ƴϴ�.
�� ������ ������� ������� ��ȣ�� ���ŵǸ�, ���ο� ������ �߿��� �� ���� ���� �� ��ȣ�� �޴´�.
�̶�, N�� �ڸ��� �ൿ�� ���� �� �� ������ ũ�⸦ ������������ ����Ѵ�.

�ذ� ��� : �� ������ ��ȣ�� ���ʷ� Ȯ���ϸ鼭 �������� �߶󳪰���. �ڸ� ��ġ�� ������ ������
���� �� �� �ְ�, �� ������ ũ��� �� ������ ũ�⿡�� �� ���� ���ؼ� Ȯ�� �����ϴ�.
�Ź� �ڸ� �� ���� �ڸ� ����� ��ȣ���� �� ���� ��ȣ���� �ϳ��� ��ܿ;� �Ѵ�.
��� �ڸ��� �ൿ�� ������ �� �������� ��ȣ���� ���ʷ� Ȯ���ϸ� ���̸� ���ϰ� ���̸� ������ ����
�� ���̵��� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : JDC 2007 C��
*/

int rect[128][2], area[128];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, w, d, p, s;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2007\\INPUT\\C4", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2007\\OUTPUT\\C4_t.out", "w", stdout);
    while (1) {
        scanf("%d %d %d", &n, &w, &d);
        if (w == 0) break;
        rect[1][0] = w, rect[1][1] = d;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p, &s);
            w = rect[p][0], d = rect[p][1];
            for (int j = p; j <= i; j++) {
                rect[j][0] = rect[j + 1][0];
                rect[j][1] = rect[j + 1][1];
            }
            if (s % (w + d) < w) {
                rect[i + 1][0] = small(s % (w + d), w - s % (w + d));
                rect[i + 1][1] = d;
                rect[i + 2][0] = big(s % (w + d), w - s % (w + d));
                rect[i + 2][1] = d;
            }
            else {
                rect[i + 1][0] = w;
                rect[i + 1][1] = small(s % (w + d) - w, d - (s % (w + d) - w));
                rect[i + 2][0] = w;
                rect[i + 2][1] = big(s % (w + d) - w, d - (s % (w + d) - w));
            }
        }

        for (int i = 1; i <= n + 1; i++) {
            area[i - 1] = rect[i][0] * rect[i][1];
        }
        qsort(area, n + 1, sizeof(int), cmp1);
        for (int i = 0; i <= n; i++) {
            printf("%d%c", area[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}