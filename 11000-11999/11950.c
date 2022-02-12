#include <stdio.h>

/*
���� : N * M(N, M <= 50) ũ���� ���ڿ� ���, �Ķ���, �������� ĥ���� �ִ�.
�� ���ڸ� ���Ϸ� ���ʷ� ���, �Ķ���, ������ ������ ������ �ٸ� ���� ������ ���� ��,
���� �ٸ� ���� ������ ���� ����� �ٸ� �� ���� ���Ѵ�. �� ���� ���� ���� 1 �̻��̾�� �Ѵ�.

�ذ� ��� : �� �κ����� ������ ��� ��츦 �õ��غ��� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����

��ó : JOI 2016�� 3��
*/

char flag[64][64];

int main(void) {
    int n, m, r = 103000, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", flag[i]);
    }
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            t = 0;
            for (int k = 0; k < m; k++) {
                for (int l = 0; l <= i; l++) {
                    if (flag[l][k] != 'W') t++;
                }
                for (int l = i + 1; l <= j; l++) {
                    if (flag[l][k] != 'B') t++;
                }
                for (int l = j + 1; l < n; l++) {
                    if (flag[l][k] != 'R') t++;
                }
            }
            if (t < r) r = t;
        }
    }
    if (r == 103000) return 1;
    printf("%d", r);
    return 0;
}