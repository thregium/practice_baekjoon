#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

/*
문제 : 문제에 주어진 식(시간에 대한)을 통한 포물선 운동을 한다고 할 때, X좌표 X_1을 통과할 때,
높이가 H1 + 1 이상 H2 - 1 이하가 되는 지 구한다. 처음 주어지는 값은 위 값들과 v_0, theta이다.
v_0는 200 이하 양의 실수, H1과 H2, x_1은 1000 미만 양의 실수(H1 < H2), theta는 90 미만 양의 실수이다.
theta는 도 단위로 주어진다.

해결 방법 : 문제에 주어진 식을 풀어 x_1에 도달하는 시간을 구한 다음, 그 시간일 때 y좌표를 구한다.
이 값이 h1 + 1 이상 h2 - 1 이하인 지 아닌 지 구하면 된다.

주요 알고리즘 : 기하학, 물리학

출처 : VTH 2015 A번
*/

int main(void) {
    int t;
    double v, th, x, h1, h2, tm, y;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lf %lf %lf %lf %lf", &v, &th, &x, &h1, &h2);
        tm = x / v / cos(th * PI / 180);
        y = tm * v * sin(th * PI / 180) - 0.5 * tm * tm * 9.81;
        if (h1 + 1 <= y && y <= h2 - 1) printf("Safe\n");
        else printf("Not Safe\n");
    }
    return 0;
}
