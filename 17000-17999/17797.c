#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
문제 : 3차원 좌표 N(N <= 100000)개가 주어질 때, 중심이 원점인 구로 점 K개 이상을 포함하기 위해서는
반지름이 최소한 얼마가 되어야 하는지 구한다.

해결 방법 : 원점에서 각 좌표까지의 거리를 피타고라스의 정리를 이용해 구한 후, 모든 점의 거리를 정렬하여 K번째 거리를 출력하면 된다.

주요 알고리즘 : 기하학, 3차원, 피타고라스 정리, 정렬

출처 : UKIEPC 2019 D번
*/

double dist[103000];

int cmp1(const void* a, const void* b) {
    double ai = *(double*)a;
    double bi = *(double*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k;
    double x, y, z;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf %lf", &x, &y, &z);
        dist[i] = sqrt(x * x + y * y + z * z);
    }
    qsort(dist, n, sizeof(double), cmp1);
    printf("%.9f", dist[k - 1]);
    return 0;
}