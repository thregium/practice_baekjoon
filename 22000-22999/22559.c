#include <stdio.h>
#include <math.h>
#define INF 1E39

/*
문제 : 좌표평면상의 N(N <= 20)개의 지점(|| <= 10000, 정수)이 있다. 1번째 지점에서 출발하여
거리 R(R <= 10000)이하고, 각 회전이 theta(< 180) 이하로 돌아가는 가장 많은 지점을 지나는 경로의
지나는 지점 개수를 구한다. 시작점은 제외한다.

해결 방법 : 우선 거리와 각을 전처리한 다음, 각 이동 횟수, 최근 2개의 지점에 대한 최단 거리를 구한다.
최단 거리가 R 이하인 가장 많은 이동 횟수를 구하면 답이 된다.

주요 알고리즘 : DP, 기하학

출처 : JAG 2010S3 B번
*/

int pos[32][2];
double angle[24][24][24], dist[24][24], mem[10240][24][24];

double todeg(double x) {
    return x / acos(-1) * 180;
}

int getdist(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main(void) {
    int n, res = 0;
    double xdist, th, angle1, angle2;
    scanf("%d%lf %lf", &n, &xdist, &th);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            angle1 = todeg(atan2(pos[j][1] - pos[i][1], pos[j][0] - pos[i][0]));
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                angle2 = todeg(atan2(pos[k][1] - pos[j][1], pos[k][0] - pos[j][0]));
                angle[i][j][k] = fabs(angle2 - angle1);
                angle[i][j][k] = 180 - fabs(angle[i][j][k] - 180);
            }
            dist[i][j] = sqrt(getdist(pos[i][0], pos[i][1], pos[j][0], pos[j][1]));
        }
    }
    for (int i = 0; i < 10240; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) mem[i][j][k] = INF;
        }
    }

    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            mem[1][i][j] = dist[i][j];
        }
    }
    for (int i = 1; i <= 10000; i++) {
        for (int p1 = 0; p1 < n; p1++) {
            for (int p2 = 0; p2 < n; p2++) {
                if (p1 == p2) continue;
                if (mem[i][p1][p2] > xdist) continue;
                else res = i;
                for (int p3 = 0; p3 < n; p3++) {
                    if (p2 == p3) continue;
                    if (angle[p1][p2][p3] < th && mem[i][p1][p2] + dist[p2][p3] < mem[i + 1][p2][p3]) {
                        mem[i + 1][p2][p3] = dist[p2][p3] + mem[i][p1][p2];
                    }
                }
            }
        }
        if (res < i) break;
    }
    printf("%d\n", res);
    return 0;
}