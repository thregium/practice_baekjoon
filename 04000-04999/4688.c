#include <stdio.h>
#include <string.h>

/*
���� : N * N(N <= 10) ũ���� ������ ���߾� ����Ѵ�. �� ���� ������ H * W(H, W <= 25) ũ���̴�.
�� ������ �� �𼭸��� ������ 5 ������ ������ �־����µ�, ���� 0�� �������� ���� �´� ����̰�, ������ 0���� �����Ѵ�.
���� �´� ������ �ݵ�� �����ϰ� �����Ѵ�.

�ذ� ��� : �� ������ ������ �Է¹��� ���� ���ʺ��� ���ʷ� ���糪���� �����Ѵ�.
���� ������� ���� ���� ��� �´� ������ ���´�. ������ �𼭸� �Ǵ� ������ �̹� ���� ���� ������ �´��� Ȯ���ؾ� �Ѵ�.
�̸� Ȯ���� ������ ������ ���� �� ���� ���߸� �ȴ�.

�ֿ� �˰��� : ����, ��Ʈ��ŷ

��ó : MidC 1996 G��?
*/

typedef struct piece {
    int used;
    int edge[4];
    char data[32][32];
} piece;

piece puz[128];
int res[16][16];
int dxy[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
int fin = 0;

void track(int n, int x, int y) {
    int nn = n * n, r;
    for (int i = 1; i <= nn; i++) {
        if (puz[i].used) continue;
        r = 1;
        for (int j = 0; j < 4; j++) {
            if (puz[res[x + dxy[j][0]][y + dxy[j][1]]].used) {
                if (puz[res[x + dxy[j][0]][y + dxy[j][1]]].edge[j ^ 2] + puz[i].edge[j] != 0) {
                    r = 0;
                    break;
                }
            }
        }
        if (!r) continue;
        puz[i].used = 1;
        res[x][y] = i;
        if (x == n && y == n) fin = 1;
        else track(n, y == n ? x + 1 : x, y == n ? 1 : y + 1);
        if (fin) return;
        puz[i].used = 0;
        res[x][y] = 127;
    }
}

int main(void) {
    int n, h, w;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM8\\GEMCERT.IN", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM8\\GEMCERT_T.OUT", "w", stdout);
    scanf("%d %d %d", &n, &h, &w);
    for (int i = 1; i <= n * n; i++) {
        for (int j = 0; j < h; j++) {
            fgets(puz[i].data[j], 30, stdin);
            if (strlen(puz[i].data[j]) < w) {
                j--;
                continue;
            }
            puz[i].data[j][w] = '\0';
        }
        for (int j = 0; j < 4; j++) {
            scanf("%d", &puz[i].edge[j]);
        }
    }
    puz[0].used = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) res[i][j] = 127;
    }
    track(n, 1, 1);
    if (!fin) return 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 1; k <= n; k++) {
                for (int l = 0; l < w; l++) {
                    printf("%c", puz[res[i][k]].data[j][l]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}