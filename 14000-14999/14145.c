#include <stdio.h>

/*
���� : R * S(R, S <= 50) ũ���� �й翡 �е��� �ִ�. �����¿�� ������ ������� ũ�Ⱑ ���� �� ����
���ʷ� �й��� ����� ��ȣ�� ���� ��, ��ȣ�� ���� ������ ����Ѵ�.
�� ����� ��� ũ�Ⱑ �ٸ���, ����� �ִ� 9����.

�ذ� ��� : �÷������� ���� �� ����� ũ�⸦ ���ϰ�, �ٽ� ������� Ȯ���ϸ鼭
����� ��ȣ�� ����� ����, �� ������� �ش� ��ȣ�� �ٲ۴�. �̸� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����

��ó : CPC 2009 I��
*/

char wheat[64][64], vis[64][64];
int size[64];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int h, w;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= h || y >= w) return 0;
    if (vis[x][y] || wheat[x][y] == '0') return 0;
    return 1;
}

int dfs(int x, int y, int dig) {
    int res = 1;
    vis[x][y] = 1;
    if (dig > 0) wheat[x][y] = '0' + dig;
    for (int i = 0; i < 4; i++) {
        if (isvalid(x + dxy[i][0], y + dxy[i][1])) res += dfs(x + dxy[i][0], y + dxy[i][1], dig);
    }
    return res;
}

int main(void) {
    int wcnt = 0, wnum = 0, wdigit;
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", wheat[i]);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (vis[i][j] || wheat[i][j] == '0') continue;
            size[wcnt++] = dfs(i, j, 0);
        }
    }
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 64; j++) vis[i][j] = 0;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (vis[i][j] || wheat[i][j] == '0') continue;
            wdigit = 0;
            for (int k = 0; k < wcnt; k++) wdigit += (size[k] <= size[wnum]);
            dfs(i, j, wdigit);
            wnum++;
        }
    }

    for (int i = 0; i < h; i++) {
        printf("%s\n", wheat[i]);
    }
    return 0;
}