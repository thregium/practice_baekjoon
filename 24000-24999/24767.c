#include <stdio.h>
#include <math.h>

/*
문제 : 좌표평면상에 N(N <= 100)개의 점이 주어질 때, 가장 가까운 점과의 거리가 D(D <= 1000) 이하인
점의 개수를 구한다. 각 점의 좌표는 절댓값 1000 이하다.

해결 방법 : N이 작으므로 모든 점 쌍 사이 거리를 확인해 나가면서 거리가 D 이내인 쌍을 모두 체크하고
하나라도 포함되는 점의 개수를 세면 된다.

주요 알고리즘 : 브루트 포스, 기하학

출처 : VTH 2014 C번
*/

double pos[128][2];
int sour[128];

double getdist(int a, int b) {
    return sqrt(pow(pos[a][0] - pos[b][0], 2) + pow(pos[a][1] - pos[b][1], 2));
}

int main(void) {
    int n, sw, su;
    double d;
    while (1) {
        scanf("%lf %d", &d, &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &pos[i][0], &pos[i][1]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (getdist(i, j) < d) {
                    sour[i] = 1;
                    sour[j] = 1;
                }
            }
        }
        sw = 0, su = 0;
        for (int i = 0; i < n; i++) {
            if (sour[i]) su++;
            else sw++;
            sour[i] = 0;
        }
        printf("%d sour, %d sweet\n", su, sw);
    }
    return 0;
}
