#include <stdio.h>

/*
���� : N(N <= 50)���� ����(��ȸ��, ����, ��ȸ��)�� ������� �־��� ��, (0, 0)���� y��ǥ�� �����ϴ� ��������
ó�� ���°� ���� ��, (X, Y)(|X|, |Y| <= 50)�� ������ ���� �ϳ��� �ٲٴ� ����� ����Ѵ�.
�׷��� ����� �����ϴ�.

�ذ� ��� : ��� ���ۿ� ���� �ٲ� �� �ִ� ��� ��츦 ���� �õ��غ���. N�� ������ �����Ƿ� ����� �����ϴ�.

�ֿ� �˰��� : ����, �ùķ��̼�, ���Ʈ ����

��ó : NAQ 2017 F��
*/

char buff[16];
int mv[64], mvt[64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, x, y, d, xf, yf;
    scanf("%d %d", &xf, &yf);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (buff[0] == 'F') mv[i] = 0;
        else if (buff[0] == 'R') mv[i] = 1;
        else mv[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = -1; j <= 1; j++) {
            x = 0, y = 0, d = 0;
            for (int k = 0; k < n; k++) {
                mvt[k] = mv[k];
                if (k == i) mvt[k] = j;
                if (mvt[k] == 0) {
                    x += dxy[d][0];
                    y += dxy[d][1];
                }
                else if (mvt[k] == 1) d = ((d + 1) & 3);
                else d = ((d + 3) & 3);
            }
            if (x == xf && y == yf) {
                printf("%d %s", i + 1, j < 0 ? "Left" : j == 0 ? "Forward" : "Right");
                return 0;
            }
        }
    }
    return 1;
}