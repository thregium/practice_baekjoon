#include <stdio.h>

/*
���� : A * B(A, B <= 100) ũ���� �濡�� N(N <= 100)���� �κ��� �ִ�. �� �κ����� ���� ��ġ�� �ʴ� ��ġ�� �ִٰ� �� ��,
M(M <= 100)���� ����� �浹���� �ʰ� ���������� �س� �� �ִ��� ���Ѵ�. ���� ���������� �س� �� ���ٸ� ������ �浹�ߴ��� ���Ѵ�.
�� ����� Rĭ ������ �̵��ϰų� Rȸ ���� �Ǵ� ���������� 90�� ȸ���ϴ� ���̴�.

�ذ� ��� : �� �κ����� ��ġ�� ����, �濡�� �κ��� �ִ� ���� �����صΰ� �κ��� �̵���ų �� ���� �ش� ������ ������Ʈ���Ѱ���
�浹�ϴ��� ���θ� Ȯ���ϸ� �ȴ�. ���� ��ȯ�ÿ��� �κ��� ���⸸ ������ �ǰ�, ������ �̵��ÿ��� �ش� �������� �κ��� �ִ���,
�Ǵ� �� ������ ������� �ʴ��� Ȯ���Ѵ�. ���� �� ��� �� �ϳ���� �浹�� ��븦 ã�� ����ϸ� �ǰ�,
�׷��� �ʴٸ� ���� ����� �����Ѵ�. ������ ����� ������ ��� ���������� �س� �� �ִ� ���̴�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : NCPC 2005 A��
*/

int room[128][128], robots[128][3]; //rooms : �ش� ��ġ�� �κ� ����, robots : 0 - X��ǥ / 1 - Y��ǥ / 2 - ����
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int h, w, n, m, x, y, d, rb, rp;
    char c;
    scanf("%d %d%d %d", &w, &h, &n, &m); //���ο� ���ο� �����Ѵ�.
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %c", &x, &y, &c);
        robots[i][0] = x;
        robots[i][1] = y;
        room[x][y] = 1;
        if (c == 'E') robots[i][2] = 1; //���� : 0, ���� : 1, ���� : 2, ���� : 3
        else if (c == 'S') robots[i][2] = 2;
        else if (c == 'W') robots[i][2] = 3;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %c %d", &rb, &c, &rp);
        x = robots[rb][0];
        y = robots[rb][1];
        d = robots[rb][2];
        if (c == 'F') {
            for (int j = 1; j <= rp; j++) {
                if (x + dxy[d][0] * j > w || x + dxy[d][0] * j <= 0 || y + dxy[d][1] * j > h || y + dxy[d][1] * j <= 0) {
                    //�ش� ��ġ�� ���� ���
                    printf("Robot %d crashes into the wall", rb);
                    return 0;
                }
                if (room[x + dxy[d][0] * j][y + dxy[d][1] * j]) {
                    //�ش� ��ġ�� �κ��� �ִ� ���
                    for (int k = 1; k <= n; k++) {
                        if (robots[k][0] == x + dxy[d][0] * j && robots[k][1] == y + dxy[d][1] * j) {
                            //�ش� ��ġ�� �ִ� �κ� ã��
                            printf("Robot %d crashes into robot %d", rb, k);
                            return 0;
                        }
                    }
                    return 1;
                }
            }
            room[x + dxy[d][0] * rp][y + dxy[d][1] * rp] = 1; //��� �κ� ���� ������Ʈ
            room[x][y] = 0;
            robots[rb][0] = x + dxy[d][0] * rp;
            robots[rb][1] = y + dxy[d][1] * rp;
        }
        else if (c == 'L') {
            for (int j = 1; j <= rp; j++) d = ((d + 3) & 3); //���� ȸ��
            robots[rb][2] = d;
        }
        else if (c == 'R') {
            for (int j = 1; j <= rp; j++) d = ((d + 1) & 3); //������ ȸ��
            robots[rb][2] = d;
        }
        else return 1;
    }
    printf("OK");
    return 0;
}