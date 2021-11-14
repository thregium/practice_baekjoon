#include <stdio.h>

/*
���� : N(N <= 100)���� ������ �ְ�, �� ������ ������ ���� �ð��� �־�����. �� ������ �Ϻθ� ������ ���� ���ٸ�
�ð� T(T <= 10000) �̳��� �����Ͽ� ���� �� �ִ� �ְ� ������ ���Ѵ�.

�ذ� ��� : ���� ������ �����̹Ƿ� �׷��� DP�� �ϸ� �ȴ�.

�ֿ� �˰��� : DP, ����

��ó : �߾Ӵ� 2017P C��
*/

int chap[128][2], mem[128][10240];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int n, t, score = 0;
    scanf("%d %d", &n, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &chap[i][0], &chap[i][1]);
        for (int j = 0; j <= t; j++) {
            mem[i][j] = big(mem[i - 1][j], j < chap[i][0] ? -1 : mem[i - 1][j - chap[i][0]] + chap[i][1]);
        }
    }
    for (int i = 0; i <= t; i++) {
        score = big(score, mem[n][i]);
    }
    printf("%d", score);
    return 0;
}