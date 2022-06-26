#include <stdio.h>
#include <string.h>

/*
���� : H * W(H, W <= 20) ũ���� ���簢������ Xǥ ������ ���� ĭ�� ���� �� ĭ����
�����¿�� �������� ���� ���ӵ� ĭ���� �����.
2���� �̸� �ݺ��Ͽ� ���̻� ĭ�� ������ �� ���� ����� ���ٰ� �� ��, ���� �̱�� �Ǵ� �� ���Ѵ�.

�ذ� ��� : ��ü �������� ������ �������� ���� ���簢�� ������� �������鼭 ���̳��� ���α׷����� �Ѵ�.
�������-�׷��� ������ �̿��Ͽ� �� ������ ���� �׷��� ���� �����ϸ鼭 ����������
��ü ������ �׷��� ���� ���Ǹ� ���� ���� �� �ִ�.

�ֿ� �˰��� : DP, ���� �̷�, �������-�׷���

��ó : JAG 2015SC L��
*/

char board[24][24];
int mem[24][24][24][24];
int tmx;

int dp(int xl, int yl, int xh, int yh) {
    if (xl > xh || yl > yh) return 0;
    if (mem[xl][yl][xh][yh] >= 0) return mem[xl][yl][xh][yh];
    int res = -1, mx = -1, g;
    int grnd[1024] = { 0, };
    for (int i = xl; i <= xh; i++) {
        for (int j = yl; j <= yh; j++) {
            if (board[i][j] == 'X') continue;
            g = dp(xl, yl, i - 1, j - 1) ^ dp(xl, j + 1, i - 1, yh) ^
                dp(i + 1, yl, xh, j - 1) ^ dp(i + 1, j + 1, xh, yh);
            grnd[g] = 1;
            if (g > mx) mx = g;
        }
    }

    if (mx > tmx) tmx = mx;
    for (int i = 0; i <= mx + 1; i++) {
        if (grnd[i] == 0) {
            res = i;
            break;
        }
    }
    return mem[xl][yl][xh][yh] = res;
}

int main(void) {
    int h, w, res;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", board[i]);
    }
    memset(mem, -1, sizeof(mem));
    res = dp(0, 0, h - 1, w - 1);
    printf("%s\n", res ? "First" : "Second");
    //printf("%d", tmx);
    return 0;
}