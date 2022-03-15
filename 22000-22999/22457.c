#include <stdio.h>
#include <math.h>
#define INF 103000.0
#define PI 3.14159265358979323846

/*
문제 : N(N <= 100)개의 별이 좌표평면상에 주어진다. 각 별의 좌표와 크기, 각도가 주어질 때,
M번째 별에서 L번째 별로 이동하는데 걸리는 비용을 구한다. 별은 오망성의 선분으로 이루어져 있고,
같은 별의 선분들 사이를 자유롭게 이동 가능하다. 다른 별 사이는 가장 가까운 점 사이의 거리만큼
비용이 든다. 좌표와 크기는 1000 이하의 범위이고, 각도는 72 이하의 자연수이다.
각도는 반시계방향으로 돌아간다.

해결 방법 : 우선 각 별의 꼭짓점마다의 좌표를 전부 구해둔다. 그런 다음, 모든 별의 쌍에 대해
별들 사이 거리를 구한다. 거리는 두 별의 각 선분 쌍마다의 거리 가운데 최솟값으로 구하고,
선분 사이의 거리는 교차하는 경우 0, 그 외에는 점과 선분 사이의 모든 쌍에 대한 최솟값으로 구한다.
점과 선분 사이 거리는 점에서 내린 수선의 발이 선분 위에 있는 경우 점과 직선 사이 거리 공식을 쓰고,
그 외에는 점과 가까운 끝점 사이 거리를 구해내면 된다.
모든 별 쌍에 대해 거리를 구했으면 플로이드-워셜 알고리즘을 이용해 최단거리를 갱신한 다음,
M번째에서 L번째로의 거리를 출력하면 된다.

주요 알고리즘 : 그래프 이론, 기하학, 선분 교차, 브루트 포스, 플로이드-워셜

출처 : JAG 2012D D번
*/

typedef struct point {
    double x, y;
} point;

point star[128][5];
double dist[128][128];

double torad(double x) {
    return x * PI / 180.0;
}

point getstarpoint(double x, double y, double a, double r) {
    point res = { x, y };
    res.x += r * -sin(torad(a));
    res.y += r * cos(torad(a));
    return res;
}

double ccw(point p1, point p2, point p3) {
    return (p1.x * p2.y + p2.x * p3.y + p3.x * p1.y) - (p1.y * p2.x + p2.y * p3.x + p3.y * p1.x);
}

double crossproduct(point v1s, point v1e, point v2s, point v2e) {
    return (v1e.x - v1s.x) * (v2e.x - v2s.x) + (v1e.y - v1s.y)* (v2e.y - v2s.y);
}

int linecross(point p1s, point p1e, point p2s, point p2e) {
    if (ccw(p1s, p1e, p2s) * ccw(p1s, p1e, p2e) < 0 &&
        ccw(p2s, p2e, p1s) * ccw(p2s, p2e, p1e) < 0) return 1;
    else return 0;
}

double linepointdist(point ls, point le, point p) {
    if (crossproduct(ls, le, ls, p) < 0) {
        return sqrt((ls.x - p.x) * (ls.x - p.x) + (ls.y - p.y) * (ls.y - p.y));
    }
    else if (crossproduct(le, ls, le, p) < 0) {
        return sqrt((le.x - p.x) * (le.x - p.x) + (le.y - p.y) * (le.y - p.y));
    }
    else {
        double a = le.y - ls.y, b = ls.x - le.x;
        double c = -(ls.x * a + ls.y * b);
        return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }
}

double getlinedist(point p1s, point p1e, point p2s, point p2e) {
    double res = INF;
    if (linecross(p1s, p1e, p2s, p2e)) return 0.0;
    if (linepointdist(p1s, p1e, p2s) < res) res = linepointdist(p1s, p1e, p2s);
    if (linepointdist(p1s, p1e, p2e) < res) res = linepointdist(p1s, p1e, p2e);
    if (linepointdist(p2s, p2e, p1s) < res) res = linepointdist(p2s, p2e, p1s);
    if (linepointdist(p2s, p2e, p1e) < res) res = linepointdist(p2s, p2e, p1e);
    return res;
}

double getstardist(int a, int b) {
    double res = INF, tmp;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            tmp = getlinedist(star[a][i], star[a][(i + 1) % 5], star[b][j], star[b][(j + 1) % 5]);
            if (tmp < res) res = tmp;
        }
    }
    return res;
}

int main(void) {
    int n, m, l;
    double x, y, a, r;
    while (1) {
        scanf("%d %d %d", &n, &m, &l);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf %lf %lf", &x, &y, &a, &r);
            for (int j = 0; j < 5; j++) {
                star[i][j] = getstarpoint(x, y, a + 144.0 * j, r);
            }
        }

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0.0;
            for (int j = i + 1; j < n; j++) {
                dist[i][j] = getstardist(i, j);
                dist[j][i] = dist[i][j];
            }
        }
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        printf("%.9lf\n", dist[m - 1][l - 1]);
    }
    return 0;
}