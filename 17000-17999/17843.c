#include <stdio.h>

/*
문제 : 12시간 시계의 시, 분, 초가 주어질 때, 세 침 중 두 침이 이루는 각 가운데 가장 작은 것을 구한다.

해결 방법 : 시, 분, 초마다 12시에 대한 각을 구한 다음, 세 경우에 대해 각각이 이루는 각을 다시 구해서
가장 작은 것을 찾으면 된다.

주요 알고리즘 : 기하학, 브루트 포스

출처 : UNIST 1회 F번
*/

double getangle(double x, double y) {
    double r = 0.0;
    if (x > y) {
        r = x - y;
        if (y + 360 - x < r) r = y + 360 - x;
        return r;
    }
    else {
        r = y - x;
        if (x + 360 - y < r) r = x + 360 - y;
        return r;
    }
}

int main(void) {
    int t, h, m, s;
    double a, b, c, r = 0;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &h, &m, &s);
        c = s * 6.0;
        b = m * 6.0 + s * 0.1;
        a = h * 30.0 + m * 0.5 + s * 0.5 / 60.0;
        r = getangle(a, b);
        if (getangle(a, c) < r) r = getangle(a, c);
        if (getangle(b, c) < r) r = getangle(b, c);
        printf("%.9f\n", r);
    }
    return 0;
}