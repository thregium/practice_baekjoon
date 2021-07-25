#include <stdio.h>
#include <math.h>

/*
���� : 2���� �÷��̾ �ְ�, �� �ϸ��� �� �÷��̾�� �ֻ����� ������. �̶� ���� �ֻ����� ���� At(At <= 5) ������ ���
�÷��̾� 1�� ����� ������ D(D <= 10)��ŭ ��������, �Ѵ� ��� �÷��̾� 2�� ����� ������ D��ŭ �����´�.
�� �÷��̾��� ���� ���� Ev1, Ev2(Ev1, Ev2 <= 10)�� D, At�� �־��� ��, �÷��̾� 1�� �̱� Ȯ���� ���Ѵ�.

�ذ� ��� : ��� �迭�� �̿��� �� �÷��̾ 1�� �ֻ����� ������ �� ��� �������� ��߽� �� ��ġ���� �̵��� Ȯ���� ���Ѵ�.
�� �������δ� �迭�� �� ĭ���� (i - 1)��°���� ���� Ƚ�� * 2�� �ֻ����� ������ ���� �� ��ġ�� �̵� Ȯ���� ���Ѵ�.
�̴� �ٽ� ��� ĭ�� ���� ���� �ܰ�� ���� �ܰ��� �̵� Ȯ���� ���� ���ϸ� �ȴ�. �̸� �ݺ��� �� ���� ���� �� �� �ϳ���
�̵��ϴ� ������ �����ϰ� �ǰ�, ����� ���� �ݺ��ϸ� ���� ���� ���� 1�� �����Ѵ�.

1�� �����ϸ� ��� ������ ���� ó�� ���¿��� 0���� �̵��� Ȯ���� ���� ���� �� �ְ� �̵��� �̸� ���� �����صд�.
�� ���� �����ص� ���� ���� ���� �ȴ�.

�ֿ� �˰����� : ����, Ȯ����, DP, ��� �迭

��ó : Brasil 2008 J��
*/

double arr[64][32][32]; //cnt, start, end
double mem[32][32][8]; //x, y, at

int main(void) {
    int ev1, ev2, at, d, x, y;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2008\\J.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2008\\J.out", "w", stdout);
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            for (int k = 0; k < 8; k++) mem[i][j][k] = -1;
        }
    }
    while (1) {
        scanf("%d %d %d %d", &ev1, &ev2, &at, &d);
        if (d == 0) break;
        x = (ev1 + (d - 1)) / d;
        y = (ev2 + (d - 1)) / d;
        if (mem[x][y][at] > -1) {
            printf("%.1f\n", mem[x][y][at]);
            continue;
        }
        for (int k = 0; k < 64; k++) {
            for (int i = 0; i <= x + y; i++) {
                for (int j = 0; j <= x + y; j++) arr[k][i][j] = 0.0;
            }
        }
        for (int i = 1; i < x + y; i++) {
            arr[0][i][i] = 100.0;
            arr[1][i][i - 1] = 100.0 * (6.0 - at) / 6.0;
            arr[1][i][i + 1] = 100.0 * at / 6.0;
        }
        for (int i = 1; i < 63; i++) {
            arr[i][0][0] = 100.0;
            arr[i][x + y][x + y] = 100.0;
            for (int j = 1; j < x + y; j++) {
                for (int k = 0; k <= x + y; k++) {
                    for (int l = 0; l <= x + y; l++) {
                        arr[i + 1][j][l] += arr[i][j][k] * arr[i][k][l] / 100.0;
                    }
                }
            }
        }

        for (int i = 1; i < x + y; i++) {
            mem[i][x + y - i][at] = arr[63][i][x + y];
        }
        printf("%.1f\n", mem[x][y][at]);
    }
    return 0;
}