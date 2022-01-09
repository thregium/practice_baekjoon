#include <stdio.h>
#include <string.h>

/*
���� : N * M(N, M <= 10) ũ���� �����ǿ��� �����¿�밢������ �̵��ϸ� �־��� K(K <= 1000)���� ���ڿ��� ����
������ ����� ����� �������� ����Ѵ�. ��� ���ڴ� ���ĺ��̸�, ���ڿ��� ���̴� 5 ���Ϸ� �־�����.
���� ���ڿ��� �־��� �� �ִ�. ����, ���ڴ� ȯ������ �̷���� �ִ�.

�ذ� ��� : �� �������� �̵��ϴ� ��츦 ��� ���캸�� ���ڿ��� ����� ����� �������� ����.
ȯ�� �̵��� ������ ������ ����, �̵� ������ ���� �迭�� ���� ������ ������ �� �ִ�.
��� ����� ���� ���� ������, ���ڿ��� ������ ���� ������ �ð� �ʰ��� �� �� �ִ�.
����, �� ���ڿ������� ����� ������ �ΰ�, �̹� ���� ���ڿ��� �ٽ� Ž������ �ʰ� ��Ͽ��� ������ ���� ���� ����.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ, DP?

��ó : ��ȣ���� 1ȸ 3��
*/

typedef struct record {
    char s[16];
    int r;
} record;

char grid[16][16], s[16];
int dxy[8][2] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
record rec[1024];
int n, m, l = 0;

int track(int x, int y, int c) {
    int r = 0, xx, yy;
    if (c == l) return 1;
    for (int i = 0; i < 8; i++) {
        xx = (x + dxy[i][0] + n) % n;
        yy = (y + dxy[i][1] + m) % m;
        if (grid[xx][yy] == s[c]) r += track(xx, yy, c + 1);
    }
    return r;
}

int main(void) {
    int k, r = 0, rc = 0;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
    }
    for (int i = 0; i < k; i++) {
        scanf("%s", s);
        for (int j = 0; j < rc; j++) {
            if (!strcmp(s, rec[j].s)) {
                printf("%d\n", rec[j].r);
                r = -1;
                break;
            }
        }
        if (r < 0) {
            r = 0;
            continue;
        }
        l = strlen(s);
        r = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (grid[x][y] == s[0]) r += track(x, y, 1);
            }
        }
        printf("%d\n", r);
        strcpy(rec[rc].s, s);
        rec[rc++].r = r;
    }
    return 0;
}