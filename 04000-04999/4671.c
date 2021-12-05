#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 26)개의 점(음이 아닌 정수, <= 50)이 주어질 때, 각 점들로 만들 수 있는 좌표축에 평행한 직사각형을 모두 출력한다.
순서는 왼쪽 위부터 시계방향으로 이동하도록 한다. 같은 위치에 있는 점은 없다.
직사각형을 출력할 때에는 사전순으로 출력한다.

해결 방법 : 각 점마다 해당 점에서 시작하여 오른쪽에 있는 점들을 찾는다. 다시 아래, 왼쪽, 위에 있는 점들을 찾아가고,
그 점이 경로에서 첫 점과 같으면 경로를 추가한다. 모든 직사각형을 찾으면 찾은 직사각형들을 정렬하여 출력하면 된다.

주요 알고리즘 : 브루트 포스, 기하학

출처 : MidC 1998 B번
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