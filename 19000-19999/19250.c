#include <stdio.h>

/*
문제 : (X, Y, Z)가 중심이고 반지름이 R인 구의 ax + by + cz + d = 0 위의 정사영의 넓이를 구한다.
평면과 구가 겹치는 경우에도 정사영의 넓이를 구하면 된다.

해결 방법 : 구는 어느 방향으로 보든 원형으로 보이기 때문에 반지름이 R인 원의 넓이를 구하면 된다.

주요 알고리즘 : 수학, 기하학

출처 : Petro 2018W1 F번
*/

int main(void) {
    int t;
    double x, y, z, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 2; i++) {
            scanf("%lf %lf %lf %lf", &x, &y, &z, &r);
            if (tt == 0) break;
        }
        printf("%.9f\n", r * r * 3.141592653589793);
    }
    return 0;
}