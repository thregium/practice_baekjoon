#include <stdio.h>

/*
문제 : 각 선수의 속도, 몸무게, 힘이 주어질 때, 해당 선수가 볼 수 있는 포지션을 모두 출력한다.(조건 생략)
볼 수 있는 포지션이 없다면 "No positions"를 출력한다.

해결 방법 : 세 값을 입력받고 조건을 비교해 포지션을 전부 출력하면 된다. 포지션을 출력하지 못했다면
"No positions"를 출력한다. 이때, 속도가 실수형이므로 비교에 유의한다.

주요 알고리즘 : 구현

출처 : MidAtl 2004 A번
*/

int main(void) {
    int wei, str, r;
    double spd;
    while (1) {
        scanf("%lf %d %d", &spd, &wei, &str);
        if (wei == 0) break;
        spd -= 0.001;
        r = 0;
        if (spd <= 4.5 && wei >= 150 && str >= 200) {
            printf("Wide Receiver ");
            r++;
        }
        if (spd <= 6.0 && wei >= 300 && str >= 500) {
            printf("Lineman ");
            r++;
        }
        if (spd <= 5.0 && wei >= 200 && str >= 300) {
            printf("Quarterback");
            r++;
        }
        if (r == 0) printf("No positions");
        printf("\n");
    }
    return 0;
}