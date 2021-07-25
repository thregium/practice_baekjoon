#include <stdio.h>

/*
���� : M * N(M, N <= 100) ũ���� ĭ���� ����ã�⸦ �Ѵ�. ��ó �Ǵ� �ش� ĭ�� ���ڰ� �ִ� ĭ�� 1, ���� ĭ�� 0�̶�� �� ��,
�ش��ϴ� ���·� ���ڸ� ���� �� �ִ��� Ȯ���ϰ�, �ִٸ� ������ ��ġ�� �ֺ� ������ ĭ ���� ���Ѵ�.

�ذ� ��� : ���� �ش� ĭ�� �ֺ� ��� ĭ�� ������ ĭ�� ��ü�� ���ڸ� ��ġ�Ѵ�.(���ڰ� ���� �� �ִ� ��� ĭ)
�� ���� 1�� ĭ�� �� ��ó�� ���ڰ� ���� ĭ�� �ִ��� ã�´�. �ִٸ� �� ������ ��Ե� ���� ��ó�� ���� �� ���ٴ� �ǹ��̹Ƿ�
��ġ�� �Ұ����ϴ�. ��ġ�� �����ϴٸ� ��� ĭ�� ���� ��ó�� ���� ���� �� ���� ���ڹ��� ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ����, ������

��ó : ROI 2004H E��
*/

int opens[128][128], mines[128][128];
int dxy[8][2] = { {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1} };

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i <= m + 1; i++) {
        for (int j = 0; j <= n + 1; j++) opens[i][j] = 1;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &opens[i][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (opens[i][j]) mines[i][j] = -1;
            for (int k = 0; k < 8; k++) {
                if (!opens[i + dxy[k][0]][j + dxy[k][1]]) mines[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (mines[i][j] < 0) continue;
            for (int k = 0; k < 8; k++) {
                if (mines[i + dxy[k][0]][j + dxy[k][1]] < 0) mines[i][j]++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (mines[i][j] == 0 && opens[i][j] == 1) {
                printf("No solution");
                return 0;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (mines[i][j] < 0) printf("*");
            else if (mines[i][j] == 0) printf(".");
            else printf("%d", mines[i][j]);
        }
        printf("\n");
    }
    return 0;
}