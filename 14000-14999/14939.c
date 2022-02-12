#include <stdio.h>

/*
���� : 10 * 10 ũ���� ���ڿ� �������� �����ų� ���� ���·� �ִ�.
�� �������� ������ �ش� ������ �����¿��� �������� ���°� ������ ��,
��� ������ �� �� �ִ� �� ���ϰ�, ������ ��� �׷��� �ϱ� ���� �ּ� ������ Ƚ���� ���Ѵ�.

�ذ� ��� : �� �� ���� �������� ���°� ������ ��� �� �Ʒ� �ٵ��� ������ ������ ������
������ ������ ���� �� �� �ִ�. �� �� ���� ������ ���´� 2^10 = 1024�����̹Ƿ�,
�� ��� ��쿡 ���� �� ���ٱ��� �ش� ������� ������ ������, ��� ������ ���� ������
������ Ƚ���� ���ϸ� �ȴ�. ��� ������ ���� ���¸� ����� ����� �ݵ�� �����ϴ�.

�ֿ� �˰��� : ���Ʈ ����, �ֵ� Ȥ?

��ó : ������ 2017M E��
*/

char light[16][16], tmp[16][16];
int dxy[5][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0} };
int best = 103000, cnt, t;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= 10 || y >= 10) return 0;
    return 1;
}

char revlight(char c) {
    if (c == 'O') return '#';
    else return 'O';
}

void pushlight(int x, int y) {
    for (int i = 0; i < 5; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) {
            tmp[x + dxy[i][0]][y + dxy[i][1]] = revlight(tmp[x + dxy[i][0]][y + dxy[i][1]]);
        }
    }
    cnt++;
}

int main(void) {
    for (int i = 0; i < 10; i++) {
        scanf("%s", light[i]);
    }
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) tmp[j][k] = light[j][k];
        }
        cnt = 0;
        for (int j = 0; j < 10; j++) {
            if ((i >> j) & 1) pushlight(0, j);
        }
        for (int j = 1; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                if (tmp[j - 1][k] == 'O') pushlight(j, k);
            }
        }

        t = 1;
        for (int j = 0; j < 10; j++) {
            if (tmp[9][j] == 'O') t = 0;
        }
        if (t) {
            if (cnt < best) best = cnt;
        }
    }
    printf("%d", best == 103000 ? -1 : best);
    return 0;
}