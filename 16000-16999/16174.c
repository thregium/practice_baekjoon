#include <stdio.h>

/*
���� : N * N(N <= 64) ũ���� �迭���� �� ĭ���� ������ �Ǵ� �Ʒ������� �̵� ������ ĭ ���� �־��� ��,
���� ������ �Ʒ� ĭ���� �̵� �������� ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� ���� �� ĭ���� �̵� ������ ĭ���� �÷� ���� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : DP

��ó : ����/�߾� 2018 J��
*/

int game[64][64], mem[64][64];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &game[i][j]);
        }
    }
    if (game[n - 1][n - 1] >= 0) return 1;
    mem[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + game[i][j] < n) mem[i + game[i][j]][j] |= mem[i][j];
            if (j + game[i][j] < n) mem[i][j + game[i][j]] |= mem[i][j];
        }
    }
    printf("%s", mem[n - 1][n - 1] ? "HaruHaru" : "Hing");
    return 0;
}