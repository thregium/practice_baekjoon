#include <stdio.h>

/*
���� : �־��� ���� M(M <= 10^6)�� ���� �ǻ�� �ֱ⸦ ���Ѵ�. �� �ǻ�� �ֱ�� 500000 ���Ͽ��� ���� ���´�.

�ذ� ��� : �Ǻ���ġ ���� M ���θ� ���ϸ� �ֱ� 2���� ���� 1�� ���� �� ���� �ݺ��Ѵ�.
�ֱ� 2���� ���� 1�̶�� �� �� - 2�� �ǻ�� �ֱ��̴�.

�ֿ� �˰��� : ����, ������, DP

��ó : GNY 2013 D��
*/

int fibo[524288];

int main(void) {
    int p, n, m;
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d %d", &n, &m);
        fibo[1] = 1, fibo[2] = 1;
        for (int i = 3;; i++) {
            fibo[i] = (fibo[i - 1] + fibo[i - 2]) % m;
            if (fibo[i] == 1 && fibo[i - 1] == 1) {
                printf("%d %d\n", n, i - 2);
                break;
            }
        }
    }
    return 0;
}