#include <stdio.h>
#define INF 1012345678

/*
���� : H * W(H, W <= 25) ũ���� ���ڿ� 10^6 ������ ���� �ٸ� �ڿ������� �����ִ�. �� ���ڿ��� �� ������ ������ �ٲپ��
������ �ִ�� ������ ����� ����Ѵ�. ���� ���� ������ ���� ������ ���ʷ� ã�ư��� �� ���� ������ �ǵ帮�� �ʰ�
�ٲ� �� �ִ� ���� ���� �ڸ��� �ٲٴ� ���̴�.

�ذ� ��� : ������ �־������ �����Ѵ�. ��� ���� ���� �ٸ��� ������ ���� ���� ������ ���ʷ� Ȯ���ϸ�
���� �� ��� ���� ������ ���� �������� ���� ���� ã�� �ٲٴ� ���� �ݺ��ϸ� �ȴ�. �ѹ� ���� ���� �ִ� ���� �����صΰ�
������ �� �������� ���ϵ��� �Ѵ�. ����, �������� �ʴ� ��찡 �����̴� �� ���� �� ���� ��쵵 ������ �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : USACO 2011F B2��
*/

int merit[32][32], visr[32], visc[32];

int main(void) {
    int h, w, prev = INF, best, bx, by, br, bc, t;
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &merit[i][j]);
        }
    }

    for (int i = 0; i < h * w; i++) {
        best = 0;
        bx = -1;
        by = -1;
        //��������� ���� ��� �ְ��� ĭ�� ã�´�.
        for (int x = 0; x < h; x++) {
            for (int y = 0; y < w; y++) {
                if (merit[x][y] < prev && merit[x][y] > best) {
                    best = merit[x][y];
                    bx = x;
                    by = y;
                }
            }
        }
        if (bx < 0) return 1;

        prev = best;
        br = bx;
        bc = by;
        //���� Ž������ ���� ���� ���� ���� ã�´�. �ش� �� ������ ��� ���� Ž���ߴٸ� �ش� �� �״�� ����.
        for (int x = bx - 1; x >= 0; x--) {
            if (!visr[x]) br = x;
        }
        for (int y = by - 1; y >= 0; y--) {
            if (!visc[y]) bc = y;
        }

        //ã�� �ٵ��� �ٲ۴�.
        if (br != bx) {
            for (int j = 0; j < w; j++) {
                t = merit[bx][j];
                merit[bx][j] = merit[br][j];
                merit[br][j] = t;
            }
        }
        if (bc != by) {
            for (int j = 0; j < h; j++) {
                t = merit[j][by];
                merit[j][by] = merit[j][bc];
                merit[j][bc] = t;
            }
        }
        visr[br] = 1;
        visc[bc] = 1;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("%d ", merit[i][j]);
        }
        printf("\n");
    }
    return 0;
}