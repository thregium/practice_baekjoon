#include <stdio.h>

/*
���� : N * N * N(N <= 20) ũ���� ��ϵ��� �ִ�. �� ����� ���� ��, ��, ������ �� ������� �־��� ��,
�� ��ϵ��� ���ӵǰ� �׾Ƽ� �̷��� ����� ���� �� �ִ��� ���Ѵ�.

�ذ� ��� : ����, �� ������� � ������ ���ϰ� �ִ��� �� �� ���� ������ 4���� ���⿡ ���� ���� ���� ������� �̸� ����� ���´�.
�� ����, �� ���⸶�� 4������ 64���� ���� ���տ� ���� ����� �״´�. �̶�, ��, ��, ������ ��� ����� ���� �� �ִ� ��쿡�� ����� ����,
�ϳ��� ���� ��쿡�� ����� ���� �ʴ´�. �� �������� ����� ����� �������� �ٽ� ��, ��, ������ �� ����� �־��� ����� ���غ���.
���� �ٸ��ٸ� �ٽ� ���� ������ ���캸��, ���ٸ� ���� ���ӵǰ� �׿����� Ȯ���ϱ� ���� �÷������� ���� ����� ���� ����� ������ ���ϸ� �ȴ�.
���� 1���� ��� ���ӵǰ� �׾Ƽ� ���� �� �ִ� ����̰�, 1���� �ƴ϶�� ���ӵǰ� �׾Ƽ� ���� �� ���� ��찡 �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����, �÷�����, �׸��� �˰���

��ó : GNY 2001 C��
*/

char top[4][32][32], front[4][32][32], side[4][32][32], blocks[32][32][32], vis[32][32][32];
int dxyz[6][3] = { {0,0,1}, {0,0,-1}, {0,1,0}, {0,-1,0}, {1,0,0}, {-1,0,0} };
int n;

void build_blocks(int dir) {
    //�־��� ������ ������ �°� ����� �״´�.
    int td = dir / 16;
    int fd = dir / 4 % 4;
    int sd = dir % 4;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (top[td][j][k] == 'X' && front[fd][i][j] == 'X' && side[sd][i][k] == 'X') blocks[i][j][k] = 'X';
                else blocks[i][j][k] = '-';
            }
        }
    }
}

void rotate(void) {
    //�־��� ������� 4���� �������� ������.
    for (int d = 0; d < 3; d++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                top[d + 1][i][j] = top[d][n - j - 1][i];
                front[d + 1][i][j] = front[d][n - j - 1][i];
                side[d + 1][i][j] = side[d][n - j - 1][i];
            }
        }
    }
}

int matches(int dir) {
    //���� ���� ����� ������ �־��� ����� �´��� Ȯ���غ���.
    int td = dir / 16;
    int fd = dir / 4 % 4;
    int sd = dir % 4;

    char topt[32][32], frontt[32][32], sidet[32][32];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            topt[i][j] = '-';
            frontt[i][j] = '-';
            sidet[i][j] = '-';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (blocks[i][j][k] == 'X') {
                    topt[j][k] = 'X';
                    frontt[i][j] = 'X';
                    sidet[i][k] = 'X';
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (topt[i][j] != top[td][i][j] || frontt[i][j] != front[fd][i][j] || sidet[i][j] != side[sd][i][j]) return 0;
        }
    }
    return 1;
}

int isvalid(int x, int y, int z) {
    //���� ��ġ�� �� �� �ִ� ��ġ���� Ȯ���Ѵ�.
    if (x < 0 || y < 0 || z < 0 || x >= n || y >= n || z >= n) return 0;
    if (vis[x][y][z] || blocks[x][y][z] == '-') return 0;
    return 1;
}

void dfs(int x, int y, int z) {
    //DFS�� ���� �ش� ��ġ���� �� �� �ִ� ��� ��ϵ��� Ȯ���Ѵ�.
    vis[x][y][z] = 1;
    for (int i = 0; i < 6; i++) {
        if (isvalid(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2])) {
            dfs(x + dxyz[i][0], y + dxyz[i][1], z + dxyz[i][2]);
        }
    }
}

int main(void) {
    int cnt, r;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) scanf("%s", top[0][i]);
        for (int i = 0; i < n; i++) scanf("%s", front[0][i]);
        for (int i = 0; i < n; i++) scanf("%s", side[0][i]);

        rotate();
        r = 0;
        for (int i = 0; i < 64; i++) {
            build_blocks(i);
            if (!matches(i)) continue;
            cnt = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    for (int z = 0; z < n; z++) {
                        if (blocks[x][y][z] == 'X' && !vis[x][y][z]) {
                            dfs(x, y, z);
                            cnt++;
                        }
                    }
                }
            }
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    for (int z = 0; z < n; z++) vis[x][y][z] = 0;
                }
            }
            if (cnt == 1) {
                r = 1;
                break;
            }
        }
        if (r) printf("Data set %d: Valid set of patterns\n", tt);
        else printf("Data set %d: Impossible combination\n", tt);
    }
    return 0;
}