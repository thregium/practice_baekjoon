#include <stdio.h>

/*
���� : R * C(R, C <= 10) ũ���� �������� ���� 3ĭ �̻��� �ٴ��� ���� �ٴٰ� �ȴٰ� �� ��,
�� �� ��� ���� �����ϴ� ���� ���� ���簢�� ������ ������ ����Ѵ�.

�ذ� ��� : �켱 �� ĭ�� �ٴٰ� �Ǵ��� ������ ���� �� �����ص� ����, ����� ������ ã��,
�� ������ ����ϸ� �ȴ�. �ٴٰ� �Ǵ��� ���ο��� ���� �迭�� Ȱ���ϸ� ����.

�ֿ� �˰��� : ����

��ó : COCI 12/13#5 2��
*/

char now[16][16], fut[16][16];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int r, c, cnt, xl = 16, xh = -1, yl = 16, yh = -1;
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        scanf("%s", now[i] + 1);
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cnt = 0;
            for (int k = 0; k < 4; k++) {
                cnt += (now[i + dxy[k][0]][j + dxy[k][1]] != 'X');
            }
            if (cnt >= 3 || now[i][j] == '.') fut[i][j] = '.';
            else fut[i][j] = 'X';
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (fut[i][j] != 'X') continue;
            if (i < xl) xl = i;
            if (i > xh) xh = i;
            if (j < yl) yl = j;
            if (j > yh) yh = j;
        }
    }

    for (int i = xl; i <= xh; i++) {
        for (int j = yl; j <= yh; j++) {
            printf("%c", fut[i][j]);
        }
        printf("\n");
    }
    return 0;
}