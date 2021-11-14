#include <stdio.h>

/*
���� : N * M(N, M <= 20) ũ���� �ٵ��ǿ� �� �� 2���� �߰��ؼ� ���� �� �ִ� ���� ���� �ִ� ������ ���Ѵ�.
�� ĭ�̸� ���� ���� ���� �� �ְ�, ���� �� �������� �����¿�� �̵��Ͽ� �� ���� ������ �ʰ� �� �� �ִ�
�� ĭ�� ���ٸ� ���� ���̴�.

�ذ� ��� : �� �� 2���� ���� �� �ִ� ��� �������� ���ƺ���. �� ����, �湮���� ���� ���� ���� ���� �� ����
�� ������ �÷������� ������ ���� ���� ��� �� ������ ���� �� ���� �߰��Ѵ�. �� ���� ���� ū ���� ã���� �ȴ�.
���� ���� �ƴ� ��쿡�� ���� �߰����� �ʰ� �湮 ó���� �Ѵ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ���Ʈ ����
*/

int baduk[32][32], vis[32][32];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int n, m;

int isvalid(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    if (vis[x][y] || baduk[x][y] == 1) return 0;
    if (baduk[x][y] == 0) return -1;
    return 1;
}

int dfs1(int x, int y) {
    //���� �� �������� ��� �� ���� ��ȯ, ������ ���� �� �������� ��� 0 ��ȯ
    int r = 1, t = 0, rb = 1;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        t = isvalid(x + dxy[i][0], y + dxy[i][1]);
        if (t == 0) continue; //���� ���� ���
        else if (t < 0) rb = 0; //�� ĭ�� �ֺ��� ���� ���
        else {
            //���� ���� �ֺ��� ���� ���
            t = dfs1(x + dxy[i][0], y + dxy[i][1]);
            if (t == 0) rb = 0; //�� �� ���Ŀ��� �� ĭ�� ã�� ���
            else r += t; //�� ĭ�� ���� ��� ���� �߰�
        }
    }
    if (rb == 0) return 0; //�� ĭ�� �ִ� ���
    else return r; //�� ĭ�� ���� ���
}

int main(void) {
    int r = -1, rt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &baduk[i][j]);
        }
    }

    for (int i1 = 0; i1 < n; i1++) {
        for (int j1 = 0; j1 < m; j1++) {
            if (baduk[i1][j1] != 0) continue;
            baduk[i1][j1] = 1;
            for (int i2 = 0; i2 < n; i2++) {
                for (int j2 = 0; j2 < m; j2++) {
                    if (baduk[i2][j2] != 0) continue;
                    baduk[i2][j2] = 1;
                    //������ ��� ���� Ȯ��
                    rt = 0;
                    for (int ii = 0; ii < n; ii++) {
                        for (int jj = 0; jj < m; jj++) {
                            if (!vis[ii][jj] && baduk[ii][jj] == 2) {
                                rt += dfs1(ii, jj); //�湮���� ���� ��� ���� ������ ���� �� ���� Ȯ��
                            }
                        }
                    }
                    for (int ii = 0; ii < n; ii++) {
                        for (int jj = 0; jj < m; jj++) {
                            vis[ii][jj] = 0; //�湮 �迭 �ʱ�ȭ
                        }
                    }
                    if (rt > r) r = rt;
                    baduk[i2][j2] = 0;
                }
            }
            baduk[i1][j1] = 0;
        }
    }
    printf("%d", r);
    return 0;
}