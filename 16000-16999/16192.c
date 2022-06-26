#include <stdio.h>
#define INF 12345678987654321

/*
문제 : N(N <= 2000)개의 점이 좌표평면상에 있다. Q(Q <= 250000)개의 쿼리에 대해
각 점이 보로노이 다이어그램의 어디에 해당하는 지 응답한다. (제한시간 10초)

해결 방법 : 제한시간이 충분히 길기 때문에 모든 점에 대해 거리를 구한 다음
가장 가까운 점의 개수에 따라 경우를 나누어 출력하면 된다.

주요 알고리즘 : 기하학, 브루트 포스

출처 : KAIST 2018F L번
*/

typedef struct point {
    long long x, y;
} point;

point p[2048];
long long dt[2048];

long long dist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main(void) {
    int n, q, bcnt;
    long long best;
    point pp;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &p[i].x, &p[i].y);
    }
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld", &pp.x, &pp.y);
        best = INF, bcnt = 0;
        for (int j = 0; j < n; j++) {
            dt[j] = dist(pp, p[j]);
            if (dt[j] < best) {
                best = dt[j];
                bcnt = 1;
            }
            else if (dt[j] == best) bcnt++;
        }

        if (bcnt == 0) return 1;
        else if (bcnt >= 3) {
            printf("POINT\n");
            continue;
        }
        else if (bcnt == 1) printf("REGION ");
        else printf("LINE ");
        for (int j = 0; j < n; j++) {
            if (dt[j] == best) printf("%d ", j + 1);
        }
        printf("\n");
    }
    return 0;
}