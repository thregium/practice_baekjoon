#include <stdio.h>

/*
���� : N * M(N, M <= 500) ũ���� �迭���� ���� 9�� ���� ���� ���� �� �Ǵ� ���� ������ ĭ���� ���� 9�� ������ ���Ѵ�.

�ذ� ��� : ��ü �迭�� ���� 9�� ������ ���� ����, �� ��� ���� ���� 9�� ���� ��� ���� ���� ���� ������ ã�´�.
��ü 9�� ������ �� ���� ���� �ȴ�.

�ֿ� �˰��� : ����

��ó : ���� 1ȸ�� C��
*/

int bingo[512][512];

int main(void) {
    int n, m, tot = 0, sum = 0, best = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < m; j++) {
            scanf("%d", &bingo[i][j]);
            for (int x = bingo[i][j]; x; x /= 10) sum += (x % 10 == 9);
        }
        tot += sum;
        if (sum > best) best = sum;
    }
    for (int i = 0; i < m; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            for (int x = bingo[j][i]; x; x /= 10) sum += (x % 10 == 9);
        }
        if (sum > best) best = sum;
    }
    printf("%d", tot - best);
    return 0;
}
