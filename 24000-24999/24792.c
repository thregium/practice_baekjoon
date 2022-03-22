#include <stdio.h>
#define INF 1012345678

/*
���� : R * C(R, C <= 15) ũ���� ������ �־�����. �� ������ ĭ�� ���� �� �Ҵ� ü���� ��(|| <= 9)��
������ �־�����. �̶�, ������ �� ���� �����ϴ� �� �ʿ��� ü���� �ּ� ���� ���Ѵ�.
���� ĭ�� �󸶵��� �ٽ� �� �� �ִ�.

�ذ� ��� : ���� ĭ�� �ݺ��ؼ� �� �� �ֱ� ������ ���� ����Ŭ�� ����� ��� �� ���� �����ϸ�
�� ����Ŭ�� ������ ���鼭 ü���� ������ ������ �� �־� ��ǻ� ������ ���̳� ���������� �ȴ�.
����, ���� ����Ŭ�� �ִ� ��� ���� �������� ü�°��� 0���� �ٲ� ����, �÷��̵�-���� �˰�������
���� ������ ���� �Ÿ��� ������ �Ǵ� �� Ȯ���Ѵ�. ������ �ȴٸ� �װ��� ���ԵǴ� �� �� ������ ����
0���� �ٲٰ�, �ش� ������ ���������� üũ�Ѵ�. ���� �ʴ� ĭ���� �ٽ� ������ �ٲ��ش�.

�� ������ ������ �̴�� �ٽ� �÷��̵�-���� �˰����� ���� ������ ��� ĭ���� ��� ĭ�� �����ϴ�
�Ÿ��� ���� ����, ��� ��� ĭ���� ��� ���� ĭ���� �̵��ϴ� ��� ��� ���� ���� ü���� ����ϴ�
ĭ�� ���� ������ �ȴ�. ���� ����Ŭ�� ��� ���������Ƿ� ���� ������ ���� �ʴ´�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����

��ó : VTH 2016 J��
*/

char dir[256];
int cliff[32][16], vis[32][16], dist[384][384], neg[384], fin[384];
int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int small(int a, int b) {
    return a < b ? a : b;
}

int isvalid(int r, int c, int x, int y) {
    if (x < 0 || y < 1 || x > r + 1 || y > c) return 0;
    return 1;
}

void floyd(int r, int c) {
    for (int i = 0; i < 384; i++) {
        for (int j = 0; j < 384; j++) dist[i][j] = INF;
    }
    for (int i = 0; i <= r + 1; i++) {
        for (int j = 1; j <= c; j++) {
            for (int k = 0; k < 4; k++) {
                if (isvalid(r, c, i + dxy[k][0], j + dxy[k][1])) {
                    dist[(i + dxy[k][0]) * 16 + (j + dxy[k][1])][i * 16 + j] = cliff[i][j];
                }
            }
        }
    }
    for (int k = 0; k < 384; k++) {
        for (int i = 0; i < 384; i++) {
            for (int j = 0; j < 384; j++) dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

int main(void) {
    int r, c, t, res = INF, ans;
    char trash;
    for (int tt = 1; tt <= 1; tt++) {
        sprintf(dir, "E:\\PS\\High School\\VTH\\2016\\rockclimbing\\data\\secret\\%d.in", tt);
        //freopen(dir, "r", stdin);
        res = INF;
        scanf("%d %d", &r, &c);
        for (int i = 1; i <= c; i++) {
            scanf(" %c", &trash);
            fin[i + 16] = 1;
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                scanf("%d", &cliff[i][j]);
                if (cliff[i][j] < 0) {
                    neg[i * 16 + j] = -cliff[i][j];
                    cliff[i][j] = 0;
                }
            }
        }
        floyd(r, c);

        for (int i = 0; i < 384; i++) {
            if (neg[i]) cliff[i >> 4][i & 15] = -neg[i];
        }
        for (int i = 0; i < 384; i++) {
            if (!neg[i]) continue;
            for (int j = 0; j < 384; j++) {
                if (!neg[j]) continue;
                if (dist[i][j] - neg[i] < 0) {
                    fin[i] = 1, fin[j] = 1;
                    cliff[i >> 4][i & 15] = 0;
                    cliff[j >> 4][j & 15] = 0;
                }
            }
        }

        floyd(r, c);
        for (int i = 1; i <= c; i++) {
            for (int j = 0; j < 384; j++) {
                if (!fin[j]) continue;
                if (dist[16 * (r + 1) + i][j] < res) res = dist[16 * (r + 1) + i][j];
            }
        }
        if (res == INF) return 1;
        sprintf(dir, "E:\\PS\\High School\\VTH\\2016\\rockclimbing\\data\\secret\\%d.ans", tt);
        //freopen(dir, "r", stdin);
        printf("%d", res);
        //scanf("%d", &ans);
        //if (res == ans) printf(" == %d\n", ans);
        //else printf(" != %d\n", ans);

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 16; j++) {
                cliff[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        for (int i = 0; i < 384; i++) {
            fin[i] = 0;
            neg[i] = 0;
        }
    }
    return 0;
}