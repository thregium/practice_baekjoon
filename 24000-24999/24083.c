#include <stdio.h>

/*
문제 : A(1 <= A <= 12)시에서 B(1 <= B <= 100) 시간 뒤는 몇 시인지 구한다. 오전과 오후는 구별하지 않는다.

해결 방법 : 12시간마다 시가 반복되기 때문에 (A + B) mod 12를 구한 다음, 그 값이 0이면 12,
그 외에는 그 값을 출력하면 맞는다.

주요 알고리즘 : 수학

출처 : JOI 2022예1 2-2번
*/

int main(void) {
    int a, b, r;
    scanf("%d%d", &a, &b);
    r = (a + b) % 12;
    printf("%d", r == 0 ? 12 : r);
    return 0;
}