#include <stdio.h>
#include <ctype.h>

/*
���� : N * N(N <= 1000) ũ���� ���ڿ� ������ ������ �־��� ��, �ֺ� ĭ�� �ִ� ������ ���� ����ϴ� ���α׷��� �����.

�ذ� ��� : ������ �־������ �����Ѵ�. ���� �迭�� �̿��ϸ� �ֺ� ĭ���� ������ Ž���� �� �ְ�,
�迭�� 1ĭ ���ΰ� �Է¹����� �迭 ������ ����� �ʰ� �ֺ� ĭ���� Ž���� �� �ִ�.

�ֿ� �˰��� : ����
*/

char mf[1024][1024];
int dxy[8][2] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };

int main(void) {
    int n, r;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", mf[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            r = 0;
            for (int d = 0; d < 8; d++) {
                if (isdigit(mf[i + dxy[d][0]][j + dxy[d][1]])) {
                    r += mf[i + dxy[d][0]][j + dxy[d][1]] - '0';
                }
            }
            if (isdigit(mf[i][j])) printf("*");
            else if (r >= 10) printf("M");
            else printf("%d", r);
        }
        printf("\n");
    }
    return 0;
}