#include <stdio.h>

/*
���� : N(N <= 1000)���� �л����� M(M <= 50)�� ���� ���� ������ �־��� ��, ������ ���� ���� ū ����� ������ ���Ѵ�.

�ذ� ��� : �� �л����� ���� ���� ����� ����, ���� ū ���� ã���� �ȴ�.

�ֿ� �˰��� : ����, ��Ģ����

��ó : JDC 2019 A��
*/

int score[1024];

int main(void) {
    int n, m, x, best;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &x);
                score[j] += x;
            }
        }
        best = -1;
        for (int i = 0; i < n; i++) {
            if (score[i] > best) best = score[i];
            score[i] = 0;
        }
        printf("%d\n", best);
    }
    return 0;
}