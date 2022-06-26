#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 1000)개의 점이 좌표평면상에 있다. 각 점은 가중치를 가지고 있다. 이때, A * B 크기의 직사각형 안에
있는 점의 가중치 최대 - 최솟값의 최댓값을 구한다. 주어진 모든 수는 2 * 10^6 이하의 자연수이다.

해결 방법 : 가장 작은 가중치인 점과 가장 큰 가중치인 점 2개를 고르고, 그 두 점을 포함하는 가장 작은 직사각형이
A * B 이하인지 확인하여 그러한 경우 가운데 가장 큰 차이를 구하면 된다.

주요 알고리즘 : 브루트 포스?
*/

int pt[1024][3];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 2);
    int bi = *((int*)b + 2);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, a, b, xlo, xhi, ylo, yhi, res = 0;
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &pt[i][0], &pt[i][1], &pt[i][2]);
    }
    qsort(pt, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            xlo = pt[i][0], xhi = pt[i][0];
            ylo = pt[i][1], yhi = pt[i][1];
            if (pt[j][0] < xlo) xlo = pt[j][0];
            if (pt[j][0] > xhi) xhi = pt[j][0];
            if (pt[j][1] < ylo) ylo = pt[j][1];
            if (pt[j][1] > yhi) yhi = pt[j][1];
            if (xhi - xlo >= a || yhi - ylo >= b) continue;
            if (pt[j][2] - pt[i][2] > res) {
                res = pt[j][2] - pt[i][2];
            }
        }
    }
    printf("%d", res);
    return 0;
}