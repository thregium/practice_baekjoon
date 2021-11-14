#include <stdio.h>

/*
���� : R * C(R, C <= 1000) ũ���� �ǿ��� �κ��� �̵� ����� ��ֹ��� ��ġ ���� �־����� �κ��� ���߰� �Ǵ� ���� ��ġ�� ���Ѵ�.

�ذ� ��� : ������ �־������ �ùķ��̼��Ѵ�. �ڼ��� ������ �߰� ����

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : ������ 12ȸC B��
*/

char vis[1024][1024];
int inst[4];
const int dxy[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int r, c;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (vis[x][y]) return 0;
    return 1;
}

int main(void) {
    int k, br, bc, sr, sc, chk;
    scanf("%d %d%d", &r, &c, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &br, &bc);
        vis[br][bc] = 1;
    }
    scanf("%d %d", &sr, &sc);
    vis[sr][sc] = 1;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &inst[i]);
    }
    while (1) {
        chk = 0;
        for (int i = 0; i < 4; i++) {
            if (isvalid(sr + dxy[inst[i]][0], sc + dxy[inst[i]][1])) {
                sr += dxy[inst[i]][0];
                sc += dxy[inst[i]][1];
                vis[sr][sc] = 1;
                chk = 1;
            }
        }
        if (!chk) break;
    }
    printf("%d %d", sr, sc);
    return 0;
}