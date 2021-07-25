#include <stdio.h>
#include <math.h>

/*
문제 : 각 면이 나올 확률이 균등하지 않은 주사위가 주어질 때, 각 면의 수들을 적절히 바꾸어(무리수나 음수도 상관 없음)
주사위의 기댓값을 3.5로 만들려고 한다. 이때, 원래 주사위와 각 면의 차이를 최소로 한다면 그때의 각 면의 차이 합을 구한다.

해결 방법 : 각 면의 수들을 마음대로 바꿀 수 있기 때문에 가장 확률이 큰 면의 수를 바꾸는 것이 이득이다.
따라서, 가장 확률이 큰 면의 수를 바꾸어 기댓값이 3.5로 만들었을 때의 해당 면의 원래 수와의 차이를 구하면 된다.

주요 알고리즘 : 수학, 그리디 알고리즘

출처 : PacNW 2017 U번 // SEUSA 2017D2 B번
*/

int main(void) {
    double sum = 0.0, highest = 0.0, x;
    for (int i = 1; i <= 6; i++) {
        scanf("%lf", &x);
        sum += x * i;
        if (x > highest) highest = x;
    }
    printf("%.3f", fabs(sum - 3.5) / highest);
    return 0;
}