#include <stdio.h>

/*
���� : H * W(H, W <= 200) ũ���� ���ڿ� �빮�ڵ��� ���� �ִ�. �빮�ڷ� �̷���� ���� L(L <= 100)��
���ڿ��� �־��� ��, �־��� ���ڿ��� �����¿�밢������ �̵��ذ��� �־��� ���ڿ��� �����
����� �������� ���Ѵ�.

�ذ� ��� : �� ������ ��°������ DP �迭�� ä�����鼭 ������ 8ĭ�� ���� ���¸� ���� ������.
�̸� �ݺ��Ͽ� ���� ������ ���¿� ���� ������ �������� ���� �ȴ�.

�ֿ� �˰��� : ���ڿ�, DP

��ó : BtOI 2010 P1��
*/

char grid[256][256], word[128];
long long mem[128][256][256];
const int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

int main(void) {
    int h, w, l, lx, ly;
    long long res = 0;
    scanf("%d %d %d", &h, &w, &l);
    for (int i = 0; i < h; i++) {
        scanf("%s", grid[i]);
    }
    scanf("%s", word);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == word[0]) mem[0][i][j] = 1;
        }
    }
    for (int i = 1; i < l; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (grid[j][k] != word[i]) continue;
                for (int d = 0; d < 8; d++) {
                    lx = j + dxy[d][0];
                    ly = k + dxy[d][1];
                    if (lx < 0 || ly < 0 || lx >= h || ly >= w) continue;
                    mem[i][j][k] += mem[i - 1][lx][ly];
                }
            }
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            res += mem[l - 1][i][j];
        }
    }
    printf("%lld", res);
    return 0;
}