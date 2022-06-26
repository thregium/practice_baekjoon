#include <stdio.h>

/*
���� : H * W(H, W <= 100) ũ���� ĭ�� �ֺ� 1���� �ٿ� ���� ���� 3 * 3 ������ ĭ���� ĥ�ؾ� �ϴ� ĭ��
���� �־�����. �̶�, ���ǿ� �°� ĥ�ϴ� ����� �ִ� �� ���ϰ�, �ִٸ� �׷��� ����� ����Ѵ�.
���ٸ� impossible�� ����Ѵ�.

�ذ� ��� : ���� �� ĭ���� ������ �Ʒ��� ĥ�س����� ĥ�ϴ� ����� �������� �� �� �ִ�.
�׷��� ĥ�� ���� ��� ĭ���� ���ǿ� �´� �� Ȯ���Ѵ�. ���ǿ� �´ٸ� �׷��� ĥ�ϴ� ����� ���̹Ƿ�
�״�� ����ϰ�, ���� �ʴ´ٸ� impossible�� ����ϸ� �ȴ�.

�ֿ� �˰����� : �׸��� �˰�����, ����

��ó : GCPC 2018 L��
*/

int clue[128][128], res[128][128];
int dxy[9][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {0, 0} };

int main(void) {
    int h, w, c, r = 1;
    scanf("%d %d", &h, &w);
    for (int i = 1; i <= h + 2; i++) {
        for (int j = 1; j <= w + 2; j++) {
            scanf("%d", &clue[i][j]);
        }
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            c = 0;
            for (int k = 0; k < 9; k++) c += res[i + dxy[k][0]][j + dxy[k][1]];
            if (c != clue[i][j]) res[i + 1][j + 1] = 1;
        }
    }
    for (int i = 1; i <= h + 2; i++) {
        for (int j = 1; j <= w + 2; j++) {
            c = 0;
            for (int k = 0; k < 9; k++) c += res[i + dxy[k][0]][j + dxy[k][1]];
            if (c != clue[i][j]) r = 0;
        }
    }
    if (!r) {
        printf("impossible");
        return 0;
    }
    for (int i = 2; i <= h + 1; i++) {
        for (int j = 2; j <= w + 1; j++) printf("%c", res[i][j] ? 'X' : '.');
        printf("\n");
    }
    return 0;
}