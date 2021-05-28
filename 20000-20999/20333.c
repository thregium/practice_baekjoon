#include <stdio.h>
#include <stdlib.h>

/*
���� : H * W(H, W <= 500) ũ���� ���ڿ� �ǹ����� ���̰� �־�����. ���⼭ ���������͸� ��ġ�� �ǹ��� �ö��� �ʰ�
��� �ǹ��� ��� ���� ������ �� �ֵ��� �� ��, �ʿ��� ������������ �ּ� ������ ���Ѵ�. ��, 1���� ��� ���������� ���� �̵� �����ϴ�.

�ذ� ��� : � �ǹ��� �ֻ����� ���� �����ϴٸ� �� ������ �������鼭 ��� ���� ���� �����ϴ�.
����, �ֻ����� ���� �ǹ����� ���ʷ� �������� �÷������� ���� ���� ������ �ǹ����� üũ�ϸ� �ȴ�.
�ֺ��� �ǹ��� ���� �ǹ����� ���� �ʴٸ� �̵� ������ �ǹ��̴�. �ǹ��� ���̰� 1 ���ϱ��� �������� ���̻� �� �ʿ䰡 �����Ƿ� Ž���� �����Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, �׸��� �˰���

��ó : UKIEPC 2020 E�� // BAPC 2020 E��
*/

int grid[512][512], vis[512][512], heights[262144][3];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int isvalid(int x, int y, int ht) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || grid[x][y] > ht || grid[x][y] == 0) return 0;
    return 1;
}

void dfs(int x, int y, int h) {
    vis[x][y] = 1;
    if (grid[x][y] < h) h = grid[x][y];
    for (int i = 0; i < 4; i++) {
        if (!isvalid(x + dxy[i][0], y + dxy[i][1], h)) continue;
        dfs(x + dxy[i][0], y + dxy[i][1], h);
    }
}

int main(void) {
    int cnt = 0;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            scanf("%d", &grid[i][j]);
            heights[i * w + j][0] = grid[i][j];
            heights[i * w + j][1] = i;
            heights[i * w + j][2] = j;
        }
    }

    qsort(heights, h * w, sizeof(int) * 3, cmp1);
    for (int i = 0; i < h * w; i++) {
        if (heights[i][0] <= 1) break;
        if (vis[heights[i][1]][heights[i][2]]) continue;
        cnt++;
        dfs(heights[i][1], heights[i][2], heights[i][0]);
    }
    printf("%d", cnt);
    return 0;
}