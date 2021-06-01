#include <stdio.h>

/*
���� : R * C(R, C <= 100) ũ���� ���ڿ��� ���ڰ� �ִ� ĭ���� �־��� ��, ���ڰ� ���� ĭ�� �ֺ���
���ڰ� �� ������ ���� ���� �� ���� ĭ���� �°� ����Ѵ�.

�ذ� ��� : �� ĭ�� ���ڰ� �ִ��� Ȯ���ϰ� �ִٸ� �״�� ���, ���ٸ� �ֺ� ĭ���� ���ڰ� �ִ� ĭ�� ã�� ������ ���� �� ���� ����Ѵ�.

�ֿ� �˰��� : ����

��ó : SEUSA 2009 E��
*/

char mines[128][128];
int dxy[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };

int main(void) {
    int r, c, cnt;
    while (1) {
        scanf("%d %d", &r, &c);
        if (r == 0) break;
        for (int i = 1; i <= r; i++) {
            scanf("%s", mines[i] + 1);
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (mines[i][j] == '*') {
                    printf("*");
                    continue;
                }
                cnt = 0;
                for (int d = 0; d < 8; d++) {
                    if (mines[i + dxy[d][0]][j + dxy[d][1]] == '*') cnt++;
                }
                printf("%d", cnt);
            }
            printf("\n");
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) mines[i][j] = '\0';
        }
    }
    return 0;
}