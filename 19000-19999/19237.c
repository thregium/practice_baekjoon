#include <stdio.h>

/*
���� : N * N(N <= 20) ũ���� ������ M(M <= 400)������ ������ �ִ�. ������ �� ĭ�� ������ �� ���� K(K <= 1000)�ʵ���
���ӵǴ� ������ �Ѹ���. �� ������ �� �ʸ��� �ֺ� ĭ�� ��� ������ ���� ĭ, ���ٸ� �ڽ��� ������ �ִ� ĭ���� �̵��Ѵ�.
�̵��� ĭ�� ������ ��� �� �ʿ� ���� �ִ� ������ �켱������ ������. �� �� ĭ�� ���� ������ �����ϸ�
���� ��ȣ�� ���� ��� �ܿ��� ���� �Ѱܳ��ٰ� �� ��, �� 1������ ���� �� �� ���� �ɸ��� �ð��� ���Ѵ�.
1000�� �̻��� ��� -1�� ����Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�. �� ������ ����� ���꿡 �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�
*/

typedef struct shark {
    int x, y; //��ǥ
    int d, n; //����, ��ȣ
    int pri[5][5]; //�켱����(���⺰)
} shark;

int space[32][32], stmp[32][32]; //����(��ȣ * 65536 + �ð�), �ӽ� �迭
const int dxy[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; //�̵��ϴ� ����
shark shk[512];

int isvalid(int n, int x, int y) {
    //��ġ�� ��ȿ���� �˻�
    if (x <= 0 || y <= 0 || x > n || y > n) return 0;
    return 1;
}

int main(void) {
    int n, m, k, p, sce;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &p);
            if (p) {
                space[i][j] = (p << 16) + 1;
                shk[p].x = i;
                shk[p].y = j;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &shk[i].d);
        shk[i].n = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                scanf("%d", &shk[i].pri[j][k]);
            }
        }
    }
    for (int tm = 1; tm <= 1000; tm++) {
        for (int i = 1; i <= m; i++) {
            p = 0;
            for (int j = 1; j <= 4; j++) {
                if (!isvalid(n, shk[i].x + dxy[shk[i].pri[shk[i].d][j]][0],
                    shk[i].y + dxy[shk[i].pri[shk[i].d][j]][1])) continue;
                sce = (space[shk[i].x + dxy[shk[i].pri[shk[i].d][j]][0]][shk[i].y + dxy[shk[i].pri[shk[i].d][j]][1]] & 65535);
                if (sce <= tm - k || sce == 0) {
                    //������ ��ȿ�Ⱓ�� ���߰ų� ���� ĭ�� ���
                    shk[i].x += dxy[shk[i].pri[shk[i].d][j]][0];
                    shk[i].y += dxy[shk[i].pri[shk[i].d][j]][1];
                    shk[i].d = shk[i].pri[shk[i].d][j];
                    p = 1;
                    break;
                }
            }
            if (p) continue;
            for (int j = 1; j <= 4; j++) {
                if (!isvalid(n, shk[i].x + dxy[shk[i].pri[shk[i].d][j]][0],
                    shk[i].y + dxy[shk[i].pri[shk[i].d][j]][1])) continue;
                if ((space[shk[i].x + dxy[shk[i].pri[shk[i].d][j]][0]][shk[i].y + dxy[shk[i].pri[shk[i].d][j]][1]] >> 16)
                    == shk[i].n) {
                    //�ڽ��� ĭ�� �ִ� ���
                    shk[i].x += dxy[shk[i].pri[shk[i].d][j]][0];
                    shk[i].y += dxy[shk[i].pri[shk[i].d][j]][1];
                    shk[i].d = shk[i].pri[shk[i].d][j];
                    p = 1;
                    break;
                }
            }
            if (!p) {
                while (k <= 3);
                return 3;
            }
        }
        for (int i = 1; i <= m; i++) {
            if (stmp[shk[i].x][shk[i].y]) {
                //�Ѱܳ��� �Ǵ� ���
                m--;
                for (int j = i; j <= m; j++) shk[j] = shk[j + 1];
                if (m == 1) {
                    printf("%d", tm);
                    return 0;
                }
                i--;
                continue;
            }
            stmp[shk[i].x][shk[i].y] = shk[i].n;
            space[shk[i].x][shk[i].y] = (shk[i].n << 16) + tm + 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) stmp[i][j] = 0;
        }
    }
    printf("-1");
    return 0;
}