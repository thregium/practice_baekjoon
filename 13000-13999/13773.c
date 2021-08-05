#include <stdio.h>

/*
문제 : 1860년부터 2030년 사이의 연도가 주어질 때, 이 해의 올림픽이 열렸는지/열릴 것인지 또는 취소되었는지 또는 열리지 않는지 구한다.
이는 전부 2016년 기준이다.

해결 방법 : 1896년 이전 또는 4의 배수가 아닌 해에는 올림픽이 열리지 않는다. 또한, 2016년 기준으로 2020년 이후는 아직 도시가
정해지지 않았으며, 1916, 1940, 1944년도에는 올림픽이 취소되었다. 그 외의 모든 4의 배수인 해에는 올림픽이 열렸다.
(물론 2020년에는 열리지 않았지만 2016년 기준으로는 알 수 없는 일이다.)

주요 알고리즘 : 구현

출처 : NZPC 2016 C번
*/

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        if (n < 1896 || (n & 3)) printf("%d No summer games\n", n);
        else if (n > 2020) printf("%d No city yet chosen\n", n);
        else if (n == 1916 || n == 1940 || n == 1944) printf("%d Games cancelled\n", n);
        else printf("%d Summer Olympics\n", n);
    }
    return 0;
}
