#include <stdio.h>

/*
문제 : 정사각형을 최소한의 분할로 둘레와 면적이 동일한 N(N <= 10^18)개의 집합으로 나눈다. 이때의 분할 횟수를 구한다.
분할할 때에는 정사각형의 한쪽 끝에서 직선으로 잘라야 한다. 집합은 여러 조각으로 구성될 수 있다.

해결 방법 : N이 짝수인 경우에는 N / 2회의 칼질로 동일한 N개의 조각으로 나눌 수 있다.
N이 홀수인 경우에는 (N + 1) / 2회의 칼질로 N - 1개의 동일한 조각과 2개의 절반 크기 조각으로 나누는 것이 가능하고,
이것이 최선의 방법이다. 단, N = 1인 경우 칼질을 하지 않아도 된다.

주요 알고리즘 : 기하학
*/

int main(void) {
    long long n;
    scanf("%lld", &n);
    if (n == 1) printf("0");
    else printf("%lld", (n + 1) >> 1);
    return 0;
}