#include <stdio.h>
#include <stdlib.h>

/*
문제 : (Xe, Ye)에서 (dX, dY)방향으로 이동하는 점의 (Xs, Ys)까지의 거리가 가장 짧아지는
지점에서의 위치를 구한다. 답이 정수인 경우만 주어지며, 모든 값은 절댓값 100 이하의 정수이다.

해결 방법 : 유클리드 호제법으로 dx와 dy의 gcd를 구한 후 dx, dy를 둘의 gcd로 나눈다.
그 후 좌표 범위가 작으므로 모든 점을 살펴보며 다음 점에서의 목적지와의 거리가 더 멀어지는 순간의
거리를 구해서 출력하면 된다.

주요 알고리즘 : 수학, 유클리드 호제법, 브루트 포스

출처 : xhark
*/

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int getdist(int xs, int ys, int xe, int ye) {
    return (ye - ys) * (ye - ys) + (xe - xs) * (xe - xs);
}

int main(void) {
    int xs, ys, xe, ye, dx, dy, g;
    scanf("%d %d%d %d %d %d", &xs, &ys, &xe, &ye, &dx, &dy);
    if (dx == 0 && dy == 0) {
        printf("%d %d", xe, ye);
        return 0;
    }
    g = gcd(abs(dx), abs(dy));
    dx /= g;
    dy /= g;
    for (int i = 0;; i++) {
        if (getdist(xs, ys, xe + dx * i, ye + dy * i) <=
            getdist(xs, ys, xe + dx * (i + 1), ye + dy * (i + 1))) {
            printf("%d %d", xe + dx * i, ye + dy * i);
            return 0;
        }
    }
    return 1;
}