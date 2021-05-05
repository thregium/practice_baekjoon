#include <stdio.h>

/*
���� : N * M(N, M <= 10^6) ũ���� �������� T(T <= 100)���� ������ ��ġ�� �־�����. �̶�, K * K(K <= 10^6) ũ���� ���簢�� �ȿ�
���� ���� ������ �ֵ��� �ϸ� �� ���簢���� ��ġ�� �ȿ� �����ϴ� ������ ���� ����Ѵ�.
��, ���簢���� ������ ��� �� ����.

�ذ� ��� : �������� �� ������ X, Y��ǥ�� ���� ����صд�. �� ����, �������� ����� �ʴ´ٸ� �� ������ X, Y ��ǥ�� �ش��ϴ�
��� �������� ���簢���� �� �������� �������� ���� ���簢�� �ȿ� ���� ������ ���� ����Ѵ�.
�� ���� �ְ����� ũ�ٸ� ���� �����ϰ� �׶��� ��ǥ�� �����ϸ� �ȴ�.
�׷���, �� �������� ��� �������� ��ǥ�� ��� ���� �ֱ� ������ 0�� N, M�� �� X, Y ��ǥ�� �����ؼ� ����ؾ� �Ѵ�. 

�ֿ� �˰��� : ���Ʈ ����

��ó : ���� 2009�� ��3��
*/

int pos[128][2], xl[128], yl[128], bp[2];

int main(void) {
    int n, m, t, k, best = 0, cnt;
    scanf("%d %d %d %d", &n, &m, &t, &k);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        xl[i] = pos[i][0];
        yl[i] = pos[i][1];
    }
    pos[t][0] = 0;
    pos[t][1] = 0;
    pos[t + 1][0] = n;
    pos[t + 1][1] = m;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (xl[i] + k <= n && yl[j] + k <= m) {
                cnt = 0;
                for (int c = 0; c < t; c++) {
                    if (pos[c][0] >= xl[i] && pos[c][0] <= xl[i] + k && pos[c][1] >= yl[j] && pos[c][1] <= yl[j] + k) cnt++;
                }
                if (cnt > best) {
                    bp[0] = xl[i];
                    bp[1] = yl[j] + k;
                    best = cnt;
                }
            }

            if (xl[i] >= k && yl[j] + k <= m) {
                cnt = 0;
                for (int c = 0; c < t; c++) {
                    if (pos[c][0] >= xl[i] - k && pos[c][0] <= xl[i] && pos[c][1] >= yl[j] && pos[c][1] <= yl[j] + k) cnt++;
                }
                if (cnt > best) {
                    bp[0] = xl[i] - k;
                    bp[1] = yl[j] + k;
                    best = cnt;
                }
            }

            if (xl[i] + k <= n && yl[j] >= k) {
                cnt = 0;
                for (int c = 0; c < t; c++) {
                    if (pos[c][0] >= xl[i] && pos[c][0] <= xl[i] + k && pos[c][1] >= yl[j] - k && pos[c][1] <= yl[j]) cnt++;
                }
                if (cnt > best) {
                    bp[0] = xl[i];
                    bp[1] = yl[j];
                    best = cnt;
                }
            }

            if (xl[i] >= k && yl[j] >= k) {
                cnt = 0;
                for (int c = 0; c < t; c++) {
                    if (pos[c][0] >= xl[i] - k && pos[c][0] <= xl[i] && pos[c][1] >= yl[j] - k && pos[c][1] <= yl[j]) cnt++;
                }
                if (cnt > best) {
                    bp[0] = xl[i] - k;
                    bp[1] = yl[j];
                    best = cnt;
                }
            }

        }
    }
    printf("%d %d\n%d", bp[0], bp[1], best);
    return 0;
}