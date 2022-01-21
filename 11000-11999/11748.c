#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 500)개의 반지름이 R_i(R_i <= 10000, 자연수)인 원이 있다. 각 원의 순서를 바꾸지 않고
모든 원을 직선 하나에 접하도록 할 때 차지하는 직선의 길이를 구한다. 차지하는 직선의 길이는
직선에서 수선을 그었을 때 모든 원이 안에 포함되는 구간이다.

해결 방법 : 각 원을 차례로 직선 위에 놓는다. 각 원은 왼쪽의 원과 접할 때 까지 이동 가능하다.
그때의 두 원의 접점 사이 거리는 피타고라스 정리를 이용해 계산하면 2 * sqrt(두 원의 반지름의 곱)이다.
이 거리보다 가까워지면 두 원이 겹치므로 불가능하다. 따라서, 이를 각 원마다 앞의 모든 원에 대해 계산하고
그 중 가장 큰 값을 고르면 된다. 이때 이 위치에 원을 놓을 시 왼쪽으로 구간을 밀어야 하는 경우에는
가장 왼쪽 원과 이 원의 왼쪽 점이 같은 선상에 오도록 해야 한다.
이를 반복한 다음 가장 오른쪽 점 가운데 가장 오른쪽에 있는 것을 고르면 된다.

주요 알고리즘 : 기하학

출처 : Tsukuba 2015 B번
*/

int cyl[512];
double bottom[512];

double big(double a, double b) {
    return a > b ? a : b;
}

int main(void) {
    int n;
    double right = 0.0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cyl[i]);
    }
    for (int i = 0; i < n; i++) {
        bottom[i] = cyl[i];
        for (int j = 0; j < i; j++) {
            bottom[i] = big(bottom[i], bottom[j] + 2 * sqrt(cyl[i] * cyl[j]));
        }
        right = big(right, bottom[i] + cyl[i]);
    }
    printf("%f\n", right);
    return 0;
}