#include <stdio.h>

/*
���� : M * N(M, N <= 100) ũ���� ������ �ڽ����� ���� ���°� �־�����. �ڽ����� ������ �Ÿ��� ���� ���Ѵ�.

�ذ� ��� : �� ���� �ڽ����� �Ʒ��ʺ��� ���鼭 ������ ��ġ���� �Ÿ� ���� �ᱣ���� ���س�����.
�� ����, ������ ��ġ�� 1ĭ ���� �ű��. �̸� ��� ���� ���� �ݺ��ϸ� ���� ���� �� �ִ�.

�ֿ� �˰��� : ����

��ó : Daejeon 2013 A��
*/

int box[128][128];

int main(void) {
    int t, m, n, r, cnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &box[i][j]);
            }
        }
        r = 0;
        for (int i = 0; i < n; i++) {
            cnt = 1;
            for (int j = m - 1; j >= 0; j--) {
                if (box[j][i]) r += (m - cnt++) - j;
            }
        }
        printf("%d\n", r);
    }
    return 0;
}