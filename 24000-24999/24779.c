#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 100)개의 삼각형의 각 변의 길이가 주어질 때, 각 삼각형의 매달린 X좌표가 겹치지 않기 위한
X좌표의 최소 범위를 구한다.

해결 방법 : 각 삼각형은 무게 중심이 매달린 Y좌표와 같도록 매달리게 된다. 따라서, 무게 중심을 계산한 다음,
줄에 매달리지 않은 두 점의 무게 중심선과의 거리를 구해서 전부 더하면 된다.
무게 중심선은 제2코사인 법칙을 이용해 구하고, 이를 이용해 점과 직선상의 거리 공식에 대입하여 답을 찾으면 된다.

주요 알고리즘 : 기하학, 물리학

출처 : VTH 2015 E번
*/

int main(void) {
    int n, a, b, c;
    double r = 0.0, x, y, xx, yy;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        x = (a * a + b * b - c * c) / (a * b * 2.0);
        y = sqrt(1.0 - x * x);
        xx = (x * b + a) / 3;
        yy = y * b / 3;
        r += fabs(a * yy) / sqrt(xx * xx + yy * yy);
        r += fabs(x * b * yy - y * b * xx) / sqrt(xx * xx + yy * yy);
    }
    printf("%f", r);
    return 0;
}
