#include <stdio.h>

/*
문제 : N(1 < N < 100)개의 점이 좌표평면상에 있다. 이때, 가장 많은 점을 지나는 직선이 지나는
점의 개수를 구한다. 같은 위치의 점은 주어지지 않는다.

해결 방법 : 모든 점의 쌍에 대해 해당 두 점을 지나는 직선상에 있는 점의 개수를 CCW를 이용해 센다.
그 중 가장 큰 값을 구하면 된다.

주요 알고리즘 : 기하학, CCW, 브루트 포스

출처 : Khwarizmi 2012 D번
*/

typedef struct point {
    long long x, y;
} point;

point p[128];

int ccw(point p1, point p2, point p3) {
    long long int tri = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y -
        (p2.x * p1.y + p3.x * p2.y + p1.x * p3.y);
    if (tri > 0) return 1;
    else if (tri == 0) return 0;
    else return -1;
}

int main(void) {
    int t, n, r, c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
        }
        r = 2;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                c = 0;
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) {
                        c++;
                        continue;
                    }
                    else if (ccw(p[i], p[j], p[k]) == 0) c++;
                }
                if (c > r) r = c;
            }
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}