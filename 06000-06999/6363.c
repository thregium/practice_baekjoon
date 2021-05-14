#include <stdio.h>

/*
���� : 5 * 6 ũ���� ���ڿ��� �� ĭ�� ������ �� ĭ�� �����¿� ĭ���� ���°� �����ȴٰ� �Ѵ�.
�̶� ��� ĭ�� ���¸� 0���� ����� ���� ������ �ϴ� ĭ���� ����Ѵ�.

�ذ� ��� : �� ���ٿ��� ���Ʈ ������ ��� ���ɼ��� ���� �˻��غ���, ���� �ٵ��� ������ ��� ĭ���� 0���� ���鵵�� �Ѵ�.
������ �ٱ��� ������ ���������� ���°� 0���� Ȯ���ϰ� 0�̶�� �� ���� ���� ĭ���� ���, �ƴ϶�� ��� Ž���Ѵ�.

�ֿ� �˰��� : �׸��� �˰���, ���Ʈ ����

��ó : GNY 2002 F��
*/

int puzzle[8][8], cpy[8][8], sel[8][8];

void press(int x, int y) {
    cpy[x][y] = !cpy[x][y];
    if (x > 0) cpy[x - 1][y] = !cpy[x - 1][y];
    if (y > 0) cpy[x][y - 1] = !cpy[x][y - 1];
    if (x < 4) cpy[x + 1][y] = !cpy[x + 1][y];
    if (y < 5) cpy[x][y + 1] = !cpy[x][y + 1];
}

int check(int b) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) cpy[i][j] = puzzle[i][j];
    }
    for (int i = 0; i < 6; i++) {
        if (b & (1 << i)) {
            press(0, i);
            sel[0][i] = 1;
        }
        else sel[0][i] = 0;
    }
    for (int i = 1; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (cpy[i - 1][j]) {
                press(i, j);
                sel[i][j] = 1;
            }
            else sel[i][j] = 0;
        }
    }
    for (int i = 0; i < 6; i++) {
        if (cpy[4][i]) return 0;
    }
    return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int tt = 1; tt <= n; tt++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                scanf("%d", &puzzle[i][j]);
            }
        }
        for (int i = 0; i < 64; i++) {
            if (check(i)) {
                printf("PUZZLE #%d\n", tt);
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 6; k++) {
                        printf("%d ", sel[j][k]);
                    }
                    printf("\n");
                }
                break;
            }
        }
    }
    return 0;
}