#include <stdio.h>

/*
���� : R * S(R, S <= 100) ũ���� '.'�� '*'�� �̷���� �迭�� �־��� ��, K * K(3 <= K <= small(R, S)) ũ���� ���簢��
���� �� �׵θ��� ������ �κ��� '*'�� ������ ���� ���� ���� ������ ���ϰ�,
�� ��ġ�� ǥ���ؼ� ����Ѵ�.

�ذ� ��� : ��� �κп� ���� K * K ũ�� ���� Ȯ���� ����, '*'�� ������ Ȯ���ϸ� ���� ���� ���� ������ ��ġ�� �����Ѵ�.
���� ���� ���� ��ġ���� ���� �迭�� �����Ͽ� ��ġ�� ǥ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : COCI 15/16#7 2��
*/

char wind[128][128];

int main(void) {
    int r, s, k, c, best = -1, bx = -1, by = -1;
    scanf("%d %d %d", &r, &s, &k);
    for (int i = 0; i < r; i++) {
        scanf("%s", &wind[i]);
    }
    for (int i = 0; i <= r - k; i++) {
        for (int j = 0; j <= s - k; j++) {
            c = 0;
            for (int ii = 1; ii < k - 1; ii++) {
                for (int jj = 1; jj < k - 1; jj++) {
                    if (wind[i + ii][j + jj] == '*') c++;
                }
            }
            if (c > best) {
                best = c;
                bx = i;
                by = j;
            }
        }
    }
    if (best < 0) return 1;

    for (int i = bx; i < bx + k; i++) {
        for (int j = by; j < by + k; j++) {
            if ((i == bx || i == bx + k - 1) && (j == by || j == by + k - 1)) wind[i][j] = '+';
            else if (i == bx || i == bx + k - 1) wind[i][j] = '-';
            else if (j == by || j == by + k - 1) wind[i][j] = '|';
        }
    }
    printf("%d\n", best);
    for (int i = 0; i < r; i++) {
        printf("%s\n", wind[i]);
    }
    return 0;
}