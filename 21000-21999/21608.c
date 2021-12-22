#include <stdio.h>

/*
���� : N * N(N <= 20) ũ���� �¼����� �¼��� �����ϴ� ������ ��ȣ�ϴ� ��� 4���� �־��� ��, �¼��� �����ϰ� �������� ���Ѵ�.
�� ����� �����¿� 4ĭ ��� ���� ��ȣ�ϴ� ����� ���� �¼��� ������, �׷��� �ڸ��� �����̶�� ������ ���� �� �¼���
���� �¼��� �ɴ´�. �׸����� ���ٸ� �� -> ���� ������������ �ɴ´�.
�������� ������ ��ȣ�ϴ� ����� 0���̸� 0, 1���̸� 1, 2���̸� 10, 3���̸� 100, 4���̸� 1000����, �� ����� �������� ���̴�.

�ذ� ��� : ������ �־������ �����Ѵ�. �������� ���ϱ� ���ؼ��� �� ������ �ƴ� �� ����� ���� ��ȣ�ϴ� �����
�����ؾ� �Կ� �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ���Ʈ ����
*/

int seat[32][32], order[512], fav[512][4];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, r = 0, best, score, bx, by;
    scanf("%d", &n);
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) seat[i][j] = -1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) seat[i][j] = 0;
    }
    for (int i = 0; i < n * n; i++) {
        scanf("%d", &order[i]);
        for (int j = 0; j < 4; j++) {
            scanf("%d", &fav[order[i]][j]);
        }
    }

    for (int i = 0; i < n * n; i++) {
        best = -1, bx = -1, by = -1;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (seat[x][y] > 0) continue;
                score = 0;
                for (int d = 0; d < 4; d++) {
                    if (seat[x + dxy[d][0]][y + dxy[d][1]] == 0) score++;
                    for (int f = 0; f < 4; f++) {
                        if (seat[x + dxy[d][0]][y + dxy[d][1]] == fav[order[i]][f]) score += 10;
                    }
                }
                if (score > best) {
                    best = score;
                    bx = x, by = y;
                }
            }
        }
        if (bx < 0) return 1;
        seat[bx][by] = order[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            score = 1;
            for(int d = 0; d < 4; d++) {
                for (int f = 0; f < 4; f++) {
                    if (seat[i + dxy[d][0]][j + dxy[d][1]] == fav[seat[i][j]][f]) score *= 10;
                }
            }
            r += score / 10;
        }
    }
    printf("%d", r);
    return 0;
}