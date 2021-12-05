#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : N(N <= 26)���� ��(���� �ƴ� ����, <= 50)�� �־��� ��, �� ����� ���� �� �ִ� ��ǥ�࿡ ������ ���簢���� ��� ����Ѵ�.
������ ���� ������ �ð�������� �̵��ϵ��� �Ѵ�. ���� ��ġ�� �ִ� ���� ����.
���簢���� ����� ������ ���������� ����Ѵ�.

�ذ� ��� : �� ������ �ش� ������ �����Ͽ� �����ʿ� �ִ� ������ ã�´�. �ٽ� �Ʒ�, ����, ���� �ִ� ������ ã�ư���,
�� ���� ��ο��� ù ���� ������ ��θ� �߰��Ѵ�. ��� ���簢���� ã���� ã�� ���簢������ �����Ͽ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ������

��ó : MidC 1998 B��
*/

typedef struct point {
    int x;
    int y;
    char c;
} point;

point pt[32];
char rect[16384][8];
int rcnt;

void track(int n, int p, int d, int mv) {
    if (d == 4) {
        if (pt[p].c - 'A' == (mv >> 20)) {
            rect[rcnt][0] = pt[p].c;
            rect[rcnt][1] = ((mv >> 15) & 31) + 'A';
            rect[rcnt][2] = ((mv >> 10) & 31) + 'A';
            rect[rcnt][3] = ((mv >> 5) & 31) + 'A';
            rcnt++;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i == p) continue;
        if (d == 0 && pt[i].x > pt[p].x && pt[i].y == pt[p].y) track(n, i, d + 1, (mv << 5) + (pt[i].c - 'A'));
        if (d == 1 && pt[i].y < pt[p].y && pt[i].x == pt[p].x) track(n, i, d + 1, (mv << 5) + (pt[i].c - 'A'));
        if (d == 2 && pt[i].x < pt[p].x && pt[i].y == pt[p].y) track(n, i, d + 1, (mv << 5) + (pt[i].c - 'A'));
        if (d == 3 && pt[i].y > pt[p].y && pt[i].x == pt[p].x) track(n, i, d + 1, (mv << 5) + (pt[i].c - 'A'));
    }
}

int main(void) {
    int n;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1998\\rect\\rect.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1998\\rect\\rect_t.out", "w", stdout);
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf(" %c %d %d", &pt[i].c, &pt[i].x, &pt[i].y);
        }
        rcnt = 0;
        for (int i = 0; i < n; i++) {
            track(n, i, 0, pt[i].c - 'A');
        }
        if (rcnt == 0) {
            printf("Point set %d: No rectangles\n", tt);
            continue;
        }
        qsort(rect, rcnt, sizeof(char) * 8, strcmp);
        printf("Point set %d:", tt);
        for (int i = 0; i < rcnt; i++) {
            if (i % 10 == 0) printf("\n ");
            printf("%s ", rect[i]);
        }
        printf("\n");
    }
    return 0;
}