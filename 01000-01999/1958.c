#include <stdio.h>

/*
���� : ���̰� 100 ������ �� ���ڿ��� �־��� ��, �� ���ڿ��� LCS�� ���Ѵ�.

�ذ� ��� : �Ϲ����� LCS�� ���� ���� ��������� 3�������� �����Ѵ�.

�ֿ� �˰��� : DP, ���ڿ�, LCS
*/

int mem[128][128][128];
char s[3][128];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    scanf("%s%s%s", s[0] + 1, s[1] + 1, s[2] + 1);
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 1; k <= 100; k++) {
                if (s[0][i] == s[1][j] && s[0][i] == s[2][k] && s[0][i]) mem[i][j][k] = mem[i - 1][j - 1][k - 1] + 1;
                else mem[i][j][k] = big(big(mem[i - 1][j][k], mem[i][j - 1][k]), mem[i][j][k - 1]);
            }
        }
    }
    printf("%d", mem[100][100][100]);
    return 0;
}