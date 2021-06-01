#include <stdio.h>

/*
���� : ���� ������ �ʷ� ������ ���ļ� N�� �̻� M(N, M <= 2000)�� ���� ���� �� �ִ�. �̶�, ���� ���� �� �������� 2���� �̾��� ��
���� �ٸ� ���� Ȯ���� p / q��� �̶� ������ ���� �� �ִ��� Ȯ���ϰ� �����ϴٸ� ������ ������ ����, �� �߿��� ���� ������ �ʷ� �������� ���� �ִ� ����� ���Ѵ�.

�ذ� ��� : �� ������ ���� ���� ���� ���� ������ ���� Ȯ���� �������� r, �ʷϻ��� g��� �ϸ� (rC2 + gC2) / (r + g)C2�̴�.
�� ���� (q - p) / q�� �Ǿ�� �ϹǷ� �и�� ���ڳ��� ���ؼ� ����� �ȴٴ� ���� �̿��ϸ� (r + g)C2 * (q - p) = rC2 + gC2 * q�� �����ϸ� �ȴ�.
���� ���� N�� ������ M�� ������ �ϳ��� ã�ƺ��� �� ���� �����ϴ� ���� ���� ������ ã���� �ȴ�.

�ֿ� �˰����� : ���Ʈ ����, ���շ�

��ó : GNY 2020 E��
*/

int main(void) {
    int p, q, n, m, y;
    scanf("%d %d %d %d", &p, &q, &n, &m);
    for (int s = n; s <= m; s++) {
        for (int x = 1; x <= s - x; x++) {
            y = s - x;
            if (s * (s - 1) * (q - p) == (x * (x - 1) + y * (y - 1)) * q) {
                printf("%d %d", x, y);
                return 0;
            }
        }
    }
    printf("NO SOLUTION");
    return 0;
}