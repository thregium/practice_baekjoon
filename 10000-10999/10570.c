#include <stdio.h>

/*
���� : V(V <= 1000)���� 1000 ������ �ڿ����� ��� ���� ���� ���� �� �� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �� �ڿ����� ���� Ƚ���� �� ����, ���� ������ ������ Ȯ���ϸ� ���� ���� ������ ���� ã���� �ȴ�.

�ֿ� �˰��� : ����

��ó : PacNW 2014 N��
*/

int cnt[1024];

int main(void) {
    int n, v, s, r, b;
    scanf("%d", &n);
    for (int nn = 0; nn < n; nn++) {
        scanf("%d", &v);
        for (int i = 0; i < v; i++) {
            scanf("%d", &s);
            if (s > 1000 || s <= 0) return 1;
            cnt[s]++;
        }
        r = -1, b = -1;
        for (int i = 1; i <= 1000; i++) {
            if (cnt[i] > b) {
                b = cnt[i];
                r = i;
            }
            cnt[i] = 0;
        }
        if (r < 0) return 2;
        printf("%d\n", r);
    }
    return 0;
}