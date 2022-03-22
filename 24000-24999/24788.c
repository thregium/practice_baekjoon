#include <stdio.h>
#include <math.h>

/*
문제 : N(N <= 50)개의 점으로 이루어진 다각형이 주어진다. 이 다각형의 크기를 조정하여 넓이가
A(A <= 10^8)가 되게 할 때, 각 점들을 위치시켜야 하는 좌표를 각각 구한다.
각 점의 좌표는 절댓값 500 이하의 실수이고, 위치시켜야 하는 좌표는 모두 음이 아닌 실수여야 한다.
그리고 최소 하나의 점은 각각 X축과 Y축 위에 위치해야 한다.

해결 방법 : 우선 다각형을 필요한 장소로 옮긴다. 그 다음 다각형의 넓이를 구해서 배율을 조정하여
점들의 위치를 출력하면 된다. 다각형의 넓이는 공식을 사용하고, 배율은 sqrt(A / 현재 넓이)로 한다.
각 점들의 좌표에 그만큼을 곱하면 조건을 만족함을 알 수 있다.

주요 알고리즘 : 기하학, 다각형의 넓이

출처 : VTH 2016 F번
*/

double pos[64][2];

double getarea(int n) {
    double res = 0.0;
    for (int i = 1; i < n; i++) {
        res += pos[i][0] * pos[i - 1][1];
        res -= pos[i][1] * pos[i - 1][0];
    }
    res += pos[0][0] * pos[n - 1][1];
    res -= pos[0][1] * pos[n - 1][0];
    if (res < 0) res *= -1;
    return res / 2.0;
}

int main(void) {
    int n;
    double xl = 103000.0, yl = 103000.0, na, a;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &pos[i][0], &pos[i][1]);
        if (pos[i][0] < xl) xl = pos[i][0];
        if (pos[i][1] < yl) yl = pos[i][1];
    }
    for (int i = 0; i < n; i++) {
        pos[i][0] -= xl;
        pos[i][1] -= yl;
    }
    na = getarea(n);
    scanf("%lf", &a);
    for (int i = 0; i < n; i++) {
        printf("%.9f %.9f\n", pos[i][0] * sqrt(a / na), pos[i][1] * sqrt(a / na));
    }
    return 0;
}