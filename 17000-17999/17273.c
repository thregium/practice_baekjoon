#include <stdio.h>

/*
���� : N(N = 1)���� ī���� �յ޸鿡 ���� 10000 ������ �ڿ����� ���� �ִ�. �̶�, M(M <= 100)�� ������ ���� �ൿ�� ���� ��,
���� ���̴� �鿡 �ִ� ī�忡 ���� ���� ���� ���Ѵ�.
K(K <= 10000)�� �־��� ��, K ������ ���� ���̴� ī�带 �����´�.
�� ó������ ��� ī�尡 �ո��� ���� �ִ�.

�ذ� ��� : ������ �־������ �����ϸ� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : ���ϴ� 2019 K��
*/

int cards[10240][2], flips[10240];

int main(void) {
    int n, m, k, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cards[i][0], &cards[i][1]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        for (int j = 0; j < n; j++) {
            if (cards[j][flips[j]] <= k) flips[j] = !flips[j];
        }
    }
    for (int i = 0; i < n; i++) {
        r += cards[i][flips[i]];
    }
    printf("%d", r);
    return 0;
}