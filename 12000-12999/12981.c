#include <stdio.h>
#define INF 1012345678

/*
���� : 3���� ������ ���� ���� 100�� ���Ϸ� �־�����. �̶�, ���� �� ���� 1��, 2��, 3���� ���� �� �ְ�,
�ѹ��� �ִ� ���� ������ ��� ���ų� ��� �޶�� �Ѵٸ� �ִ� Ƚ���� �ּڰ��� ���Ѵ�.

�ذ� ��� : ���̳��� ���α׷����� �̿��� �� ���� ������ ������ �ΰ� �̶��� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : DP

��ó : SRM 609 D2B
*/

int mem[128][128][128];

int small(int a, int b) {
    return a < b ? a : b;
}

int dp(int a, int b, int c) {
    if (mem[a][b][c] >= 0) return mem[a][b][c];
    if (a + b + c == 0) return mem[a][b][c] = 0;
    int r = INF;
    if (a >= 1) r = small(r, dp(a - 1, b, c)) + 1;
    if (b >= 1) r = small(r, dp(a, b - 1, c)) + 1;
    if (c >= 1) r = small(r, dp(a, b, c - 1)) + 1;
    if (a >= 2) r = small(r, dp(a - 2, b, c)) + 1;
    if (a >= 1 && b >= 1) r = small(r, dp(a - 1, b - 1, c)) + 1;
    if (a >= 1 && c >= 1) r = small(r, dp(a - 1, b, c - 1)) + 1;
    if (b >= 2) r = small(r, dp(a, b - 2, c)) + 1;
    if (b >= 1 && c >= 1) r = small(r, dp(a, b - 1, c - 1)) + 1;
    if (c >= 2) r = small(r, dp(a, b, c - 2)) + 1;
    if (a >= 3) r = small(r, dp(a - 3, b, c)) + 1;
    if (a >= 1 && b >= 1 && c >= 1) r = small(r, dp(a - 1, b - 1, c - 1)) + 1;
    if (b >= 3) r = small(r, dp(a, b - 3, c)) + 1;
    if (c >= 3) r = small(r, dp(a, b, c - 3)) + 1;
    return mem[a][b][c] = r;
}

int main(void) {
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);
    for (int i = 0; i < 128; i++) {
        for (int j = 0; j < 128; j++) {
            for (int k = 0; k < 128; k++) {
                mem[i][j][k] = -1;
            }
        }
    }
    printf("%d", dp(r, g, b));
    return 0;
}