#include <stdio.h>

/*
���� : R * C(R, C <= 200) ũ���� ���ڿ� ��ź�� �� ĭ���� �ִ�. �̶�, N(N <= 200)�� �� ������ ����� ���Ѵ�.
��ź�� 3�� �� ������, ��ź�� ������ �����¿� 4ĭ�� ��ź�鵵 ���� ������. ���� �ۿ��� �Ͼ�� �ʴ´�.
2�ʸ��� ��ź�� ���� ĭ�� ��ź�� �����Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�. �迭�� 2�� �θ� �� ������ Ǯ �� �ִ�.

�ֿ� �˰��� : ����, �ùķ��̼�
*/

char bombs[256][256], bombs2[256][256];
int dxy[5][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0} };

int main(void) {
    int r, c, n;
    char ch;
    scanf("%d %d %d", &r, &c, &n);
    for (int i = 0; i <= r + 1; i++) {
        for (int j = 0; j <= c + 1; j++) {
            bombs[i][j] = -1;
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf(" %c", &ch);
            if (ch == 'O') bombs[i][j] = 3;
            else bombs[i][j] = -1;
        }
    }
    for (int tm = 0; tm < n; tm++) {
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                bombs[i][j]--;
            }
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                bombs2[i][j] = 0;
                for (int d = 0; d < 5; d++) {
                    if (bombs[i + dxy[d][0]][j + dxy[d][1]] == 0) bombs2[i][j] = 1;
                }
            }
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (bombs2[i][j]) bombs[i][j] = -1;
            }
        }
        if (tm & 1) {
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (bombs[i][j] < 0) bombs[i][j] = 3;
                }
            }
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            printf("%c", bombs[i][j] < 0 ? '.' : 'O');
        }
        printf("\n");
    }
    return 0;
}