#include <stdio.h>
#include <string.h>

/*
문제 : N * N(N <= 10) 크기의 퍼즐을 맞추어 출력한다. 각 퍼즐 조각은 H * W(H, W <= 25) 크기이다.
각 조각의 네 모서리는 절댓값이 5 이하인 정수로 주어지는데, 합이 0인 수끼리는 서로 맞는 상대이고, 직선은 0으로 생각한다.
답이 맞는 퍼즐은 반드시 유일하게 존재한다.

해결 방법 : 각 퍼즐의 정보를 입력받은 다음 한쪽부터 차례로 맞춰나가기 시작한다.
아직 사용하지 않은 조각 가운데 맞는 조각을 놓는다. 퍼즐의 모서리 또는 인접한 이미 놓은 퍼즐 조각과 맞는지 확인해야 한다.
이를 확인해 나가며 퍼즐이 맞을 때 까지 맞추면 된다.

주요 알고리즘 : 구현, 백트래킹

출처 : MidC 1996 G번?
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