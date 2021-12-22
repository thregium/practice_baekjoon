#include <stdio.h>

/*
문제 : (0, 0)에서 시작하여 반원모양으로 물이 시간당 50m^2씩 채워져 나간다.
이때, 주어지는 실수 좌표 (X, Y)(|X| <= 1000, 0 <= Y <= 1000)에 물이 채워지는 시각을 구한다.

해결 방법 : 피타고라스의 정리를 응용하면 X * X + Y * Y * pi / 2 / 50을 올림한 값으로 계산 가능하다.

주요 알고리즘 : 기하학, 피타고라스 정리

출처 : CTUO 2002 W번
*/

int main(void) {
    double x, y;
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2002\\water.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2002\\water_t.out", "w", stdout);
    while (1) {
        scanf("%lf %lf", &x, &y);
        if (x == 0 && y == 0) break;
        printf("The property will be flooded in hour %d.\n", (int)((x * x + y * y) * 1.5707963 / 50) + 1);
    }
    return 0;
}