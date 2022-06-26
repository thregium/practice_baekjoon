#include <stdio.h>

/*
���� : N(N <= 15)���� ����� ���缺�а� ������ �־�����.
������ ����� ���缺�� ���� ��ǥġ �̻��� �Ǹ鼭 �������� �ǵ��� ������ ������ ��,
�׷��� �����ϴ� ��� ��� ���������� ���� ���� ���� ���Ѵ�.
�׷��� ����� ���� ��� -1�� ����Ѵ�.

�ذ� ��� : �� ��Ḧ �����ϰų� �������� �ʴ� ��� ��츦 ���س�����.
���� ���� ������ ������ ��ǥ ���簪�� �����ߴٸ� ������ ������� �߿� ���� ���� �� Ȯ���ϰ�
�׷��� ��� ��� �迭�� �����Ѵ�.
����� ���� ���� ������ Ž���ϱ� ������ ���� ���� ��� �ݵ�� ���� ������ ó�� ������ ���� �����ϰ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : ���� 2020_1 ��2��
*/

int mn[4], ing[16][5], stk[16], tsum[4], res[16];
int best = 103000, rcnt = 0;

void track(int n, int m, int cnt, int c) {
    int fin = 1;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < 4; j++) tsum[j] += ing[stk[i]][j];
    }
    for (int i = 0; i < 4; i++) {
        if (mn[i] > tsum[i]) fin = 0;
        tsum[i] = 0;
    }
    if (fin) {
        if (c < best) {
            best = c;
            for (int i = 0; i < cnt; i++) res[i] = stk[i];
            rcnt = cnt;
        }
        return;
    }
    for (int i = m; i < n; i++) {
        stk[cnt] = i;
        track(n, i + 1, cnt + 1, c + ing[i][4]);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &mn[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &ing[i][j]);
        }
    }
    track(n, 0, 0, 0);
    if (best == 103000) {
        printf("-1");
        return 0;
    }
    printf("%d\n", best);
    for (int i = 0; i < rcnt; i++) {
        printf("%d ", res[i] + 1);
    }
    return 0;
}