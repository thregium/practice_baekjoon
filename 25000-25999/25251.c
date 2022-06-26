#include <stdio.h>

/*
���� : N * M(N, M <= 2000) ũ���� ������ 'C'�� '_'�� �ִ�. �ִ� ��η� �� ���� ������
�� ������ �Ʒ��� ���� ���� �̵��� �ݺ��� ��, ��� 'C'�� �ִ� ĭ�� ������ ����
�̵��ؾ� �ϴ� �ּ� Ƚ���� ���Ѵ�.

�ذ� ��� : ���� ���� �κ��� �����鼭 ������ ���� 'C'�� ���� ���� ���� �ݺ��Ѵ�.
���� ���� �κ��� ��ġ�� �� ������ �˰����� �̿��� ���� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, �� ������

��ó : GCPC 2021 G��
*/

char c[2048][2048];
int hi[2048];

int main(void) {
    int n, m, res = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", c[i]);
    }
    for (int i = 0; i < m; i++) {
        hi[i] = n;
        for (int j = n - 1; j >= 0; j--) {
            if (c[j][i] == 'C') hi[i] = j;
        }
    }
    hi[m] = n;
    for (int i = m - 1; i >= 0; i--) {
        if (hi[i] > hi[i + 1]) hi[i] = hi[i + 1];
    }
    while (hi[0] < n) {
        for (int i = 0; i < m; i++) {
            for (int j = hi[i]; j <= hi[i + 1]; j++) c[j][i] = '_';
        }
        for (int i = 0; i < m; i++) {
            for (int j = hi[i]; j < n; j++) {
                if (c[j][i] == '_') hi[i] = j + 1;
                else break;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            if (hi[i] > hi[i + 1]) hi[i] = hi[i + 1];
        }
        res++;
    }
    printf("%d", res);
    return 0;
}