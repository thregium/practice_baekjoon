#include <stdio.h>

/*
문제 : 휴대폰 배터리가 100%인 상태에서 T분 사용한 결과 P%의 배터리가 남았다.
배터리가 20% 이하인 경우 배터리 효율이 2배가 된다고 할 때 방전될 때 까지 몇 분 더 쓸 수 있는지 구한다.

해결 방법 : 배터리가 20% 이하일 때를 배터리가 실제로 2배가 늘어난 것으로 생각하고 배터리의 양을 바꾼다.
그 다음 현재 상태가 될 때 까지 사용한 시간당 배터리 양을 구하고 이 값을 남은 배터리의 양에 곱하면 남은 시간이 된다.

주요 알고리즘 : 구현, 사칙연산

출처 : NEERC North 2018 A번
*/

int main(void) {
    int t, p;
    double s;
    scanf("%d %d", &t, &p);
    if (p < 20) p *= 2;
    else p += 20;
    s = t / (120.0 - p);
    printf("%lf", s * p);
    return 0;
}