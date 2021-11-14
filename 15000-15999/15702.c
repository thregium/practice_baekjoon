#include <stdio.h>

/*
���� : N(N <= 100)���� ������ ������ M(M <= 100)���� ä�� ���, ���� ��ȣ�� �־��� ��, ���� ������ ���� �л���
���� ��ȣ�� ���� ������ ���Ѵ�. ��, �̷��� �л��� ������ ��� ���� ��ȣ�� ���� ���� �л��� ����Ѵ�.

�ذ� ��� : �� �л��� ������ ���� ���� �ִ񰪺��� ���ٸ� �ִ񰪰� �л��� �����Ѵ�. ���� ��쿡��
�����ȣ�� ���ؼ� �����ȣ�� �� �۴ٸ� �л��� �����Ѵ�.
��� �л��� Ȯ���ߴٸ� �ִ񰪰� ���� ��ȣ�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����
*/

int prob[128], score[128], num[128];

int main(void) {
    int n, m, best = -1, bn = -1;
    char c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &prob[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &num[i]);
        for (int j = 0; j < n; j++) {
            scanf(" %c", &c);
            if (c == 'O') score[i] += prob[j];
        }
        if (score[i] > best) {
            best = score[i];
            bn = num[i];
        }
        else if (score[i] == best) {
            if (num[i] < bn) bn = num[i];
        }
    }
    if (bn < 0) return 1;
    printf("%d %d", bn, best);
    return 0;
}