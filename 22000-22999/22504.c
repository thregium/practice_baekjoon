#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 20)개의 색상 가운데 M개를 뽑아 각 색상 쌍 별로 색상 거리 합이 가장 큰 것을 찾으려고 한다.
그때의 색상 거리 합을 구한다. 각 색상 쌍의 색상 거리는 색상의 요소별 차이의 제곱의 합과 같다.

해결 방법 : N이 작기 때문에 브루트 포스를 통해 모든 색상을 뽑는 경우에 대해 시도해본다.
각 경우마다 모든 색상 쌍에 대해 색상 거리를 구하고 그 중 가장 큰 것을 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : JAG 2011S3 A번
*/

int picked[32];
double color[32][3];
double r = 0.0;

double getdist(double* x, double* y) {
    return pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2) + pow(x[2] - y[2], 2);
}

void track(int n, int m, int k, int l) {
    if (m == k) {
        double d = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                d += getdist(color[picked[i]], color[picked[j]]);
            }
        }
        if (d > r) r = d;
        return;
    }

    for (int i = l + 1; i < n; i++) {
        picked[k] = i;
        track(n, m, k + 1, i);
    }
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &color[i][0], &color[i][1], &color[i][2]);
    }
    track(n, m, 0, -1);
    printf("%f", r);
    return 0;
}