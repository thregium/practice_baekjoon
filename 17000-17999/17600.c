#include <stdio.h>
#define INF 1012345678

/*
���� : N(N <= 50)���� ������ ��ġ(<= 100000)�� �־��� ��, 100000 ���Ͽ��� ���� ������ �׸����� Ǯ����
�ݷʰ� �ִ� �� ���ϰ�, �ִٸ� �� �� ���� ���� ���� ����Ѵ�. ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : ������ ���� 100000 ������ ��� ���� ���� ���� ���� ���� ����, 0���� 10������
�׸����� ����� ������ ���� ������. �� �� ���� �ٸ� ���� ���� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : DP, ����, �׸��� �˰���

��ó : TOPC 2019 C��
*/

int coin[50], mem[103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int greedy(int x, int n) {
    int r = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (x >= coin[i]) {
            r += x / coin[i];
            x %= coin[i];
        }
    }
    return r;
}

int main(void) {
    int n;
    for (int i = 1; i <= 103000; i++) mem[i] = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
        for (int j = coin[i]; j <= 100000; j++) {
            mem[j] = small(mem[j], mem[j - coin[i]] + 1);
        }
    }
    for (int i = 0; i <= 100000; i++) {
        if (greedy(i, n) != mem[i]) {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}