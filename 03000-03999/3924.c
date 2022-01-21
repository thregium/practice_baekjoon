#include <stdio.h>

/*
���� : N * N(3 <= N <= 7)�� ĭ�� ���� N�� ��װ� �ִ�. �� ���̼� �������� ��� ������ �����ư���
���ϴ� ��׿� �ȴ´�. ���� ������ ����� ������ �� �� ���ڸ��� ���� �ȴ�. � �����ε�
M(3 <= M <= N)���� ���� ���� ������ �����ϸ� �� ���� ���� ����� �̱�ٰ� �� ��,
��׿� ������ �ȴ� ��ġ���� P(P <= N^3)�� �־����� �̱�� ����� ��ȣ�� �� ����� ���� ���� ���Ѵ�.
�̱�� ����� ���ٸ� Draw�� ����Ѵ�. ������ �ȴ� �������� �� ��׿� N�� �Ѱ� �ȴ� ���� ����.
�����ϴ� ���� ������ �����¿�����, 6������ �밢��, 4������ 3���� �밢���̴�.

�ذ� ��� : ���� ������ ��� ����鿡 ���� ��ó���� ���� ���� �迭�� ������ش�.
�׸��� �� ��׵��� �������� �ΰ� ������ �ȾƳ�����. ������ ���� �� ���� M���� ������ ����� �� Ȯ���ϰ�,
����ٸ� �׶� ������ ���� ����� �׶��� �� ��ȣ�� ����ϸ� �ȴ�.
������ ����� �� ���δ� �� �������� �� �������� �̵��ϸ� ������ ����� ������ ������ ����
M�� �̻� �ִ� �� ���� Ȯ���ϸ� �ȴ�. N�� ũ�� �ʱ� ������ �׷��� �ϴ��� �ð� �ʰ��� �Ͼ�� �ʴ´�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : Ehime 2004 B��
*/

int peg[8][8][8];
int dxyz[26][3];

int isvalid(int n, int x, int y, int z) {
    if (x < 1 || y < 1 || z < 1 || x > n || y > n || z > n) return 0;
    else return 1;
}

int pegwin(int n, int m) {
    int cnt, x, y, z;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (peg[i][j][k] == 0) continue;
                for (int d = 0; d < 26; d++) {
                    cnt = 1;
                    for (int l = 1;; l++) {
                        x = i + dxyz[d][0] * l, y = j + dxyz[d][1] * l, z = k + dxyz[d][2] * l;
                        if (isvalid(n, x, y, z)) cnt++;
                        else break;
                        if (peg[x][y][z] != peg[i][j][k]) break;
                        if (cnt == m) {
                            return peg[i][j][k];
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(void) {
    int n, m, p = 0, x, y, r;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2004\\B\\tests\\01.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2004\\B\\tests\\01_t.out", "w", stdout);
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                if (i == 0 && j == 0 && k == 0) continue;
                dxyz[p][0] = i, dxyz[p][1] = j, dxyz[p][2] = k;
                p++;
            }
        }
    }

    while (1) {
        scanf("%d %d %d", &n, &m, &p);
        if (n == 0) break;
        r = 0;
        for (int i = 0; i < p; i++) {
            scanf("%d %d", &x, &y);
            if (r) continue;
            peg[x][y][++peg[x][y][0]] = (i & 1) + 1;
            r = pegwin(n, m);
            if (r == 1) printf("Black %d\n", i + 1);
            else if (r == 2) printf("White %d\n", i + 1);
        }
        if (r == 0) printf("Draw\n");

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k <= n; k++) peg[i][j][k] = 0;
            }
        }
    }
    return 0;
}