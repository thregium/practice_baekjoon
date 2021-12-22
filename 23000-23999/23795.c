#include <stdio.h>

/*
문제 : 2000개 이하의 자연수가 주어질 때, -1이 들어오기 전까지의 합을 구한다. 합은 2^31보다 작다.

해결 방법 : 반복문을 통해 자연수의 합을 구하면 된다. -1이 들어오면 반복을 탈출해 답을 출력한다.

주요 알고리즘 : 수학, 사칙연산

출처 : 성균관대 2021 A번
*/

int main(void) {
    int x;
    long long r = 0;
    while (1) {
        scanf("%d", &x);
        if (x < 0) break;
        r += x;
    }
    printf("%lld", r);
    return 0;
}