#include <stdio.h>

/*
���� : 12�������� ��� ��ǰ�� ��ȭ�� �־��� ��, 1���� �ŷ��� M(M <= 500)�� �ں��ݿ���
���� �� �ִ� �ִ� ������ ���� ������ �� ���� ������ ���Ѵ�. �׷��� ������ ������ ���
���� ���� ��� �Ĵ� ��츦 �������� ���Ѵ�. ��ǰ ������ ��� �޿��� �ٸ���.
������ �� �� ���� ��� "IMPOSSIBLE"�� ����Ѵ�.

�ذ� ��� : ���� ���� �����Ƿ� ��� �޿� ���ؼ� ���� Ȯ���� ���� ���� ������ ���� ������ ã��
�� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : GCJ 2011AQ B2��
*/

int p[16];

int main(void) {
    int t, m, a, b, best;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &m);
        for (int i = 1; i <= 12; i++) {
            scanf("%d", &p[i]);
        }
        p[0] = 103000;
        a = 0, b = 0, best = 1;
        for (int i = 1; i <= 12; i++) {
            if (p[i] > m) continue;
            for (int j = i + 1; j <= 12; j++) {
                if (m / p[i] * (p[j] - p[i]) > best ||
                    (m / p[i] * (p[j] - p[i]) == best && m / p[i] > m / p[a])) {
                    a = i, b = j, best = m / p[i] * (p[j] - p[i]);
                }
            }
        }
        if (a == 0) printf("Case #%d: IMPOSSIBLE\n", tt);
        else printf("Case #%d: %d %d %d\n", tt, a, b, best);
    }
    return 0;
}