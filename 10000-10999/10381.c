#include <stdio.h>
#include <math.h>

/*
문제 : K(K <= 10000)초동안의 바람벡터가 주어질 때, 시작점에서 도착점까지 제한속도 이내로 추진하며 드론을 날릴 수 있는지 구하고,
가능하다면 각 초마다의 움직임을 출력한다.

해결 방법 : K초동안의 모든 바람벡터를 더한 값을 도착점에서 빼준다. 그 다음, 시작점과 도착점 사이의 거리가 제한속도 * K 이하인지
확인한다. 넘는 경우에는 불가능하고, 넘지 않는 경우에는 그 방향으로 직선으로 계속 이동하면 된다.
시작점에서 보정된 도착점까지의 벡터를 K로 나눈 것을 각 초마다 바람벡터에 더해주면 각 초마다 그렇게 이동한 곳의 좌표가 된다.

주요 알고리즘 : 기하학

출처 : NWRRC 2014 J번
*/

int winddiff[10240][3], windtime[10240][2];

long long getdist(long long sx, long long sy, long long fx, long long fy) {
    return (fx - sx) * (fx - sx) + (fy - sy) * (fy - sy);
}

int main(void) {
    int sx, sy, fx, fy, fpx, fpy, n, k, vm;
    double x, y, movex, movey;
    scanf("%d %d %d %d", &sx, &sy, &fx, &fy);
    fpx = fx, fpy = fy;
    scanf("%d %d %d", &n, &k, &vm);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &winddiff[i][0], &winddiff[i][1], &winddiff[i][2]);
        if (i > 0) {
            for (int j = winddiff[i - 1][0]; j < winddiff[i][0]; j++) {
                windtime[j][0] = winddiff[i - 1][1];
                windtime[j][1] = winddiff[i - 1][2];
                fpx -= windtime[j][0];
                fpy -= windtime[j][1];
            }
        }
    }
    for (int j = winddiff[n - 1][0]; j < k; j++) {
        windtime[j][0] = winddiff[n - 1][1];
        windtime[j][1] = winddiff[n - 1][2];
        fpx -= windtime[j][0];
        fpy -= windtime[j][1];
    }
    if (getdist(sx, sy, fpx, fpy) > (long long)vm * k * vm * k) {
        printf("No");
        return 0;
    }
    printf("Yes\n");
    movex = ((double)fpx - sx) / k;
    movey = ((double)fpy - sy) / k;
    x = sx, y = sy;
    for (int i = 0; i < k; i++) {
        x += movex + windtime[i][0];
        y += movey + windtime[i][1];
        printf("%.9f %.9f\n", x, y);
    }
    return 0;
}