#include <stdio.h>

/*
문제 : 1부터 N(N <= 80000)까지의 수들 가운데 3의 배수 또는 7의 배수의 합을 T(T <= 100000)번 구한다.

해결 방법 : 미리 80000까지의 답을 구해놓은 다음, N이 입력될 때 마다 답을 출력하면 된다.

주요 알고리즘 : 수학

출처 : 중앙대 2019N F번
*/

long long mem[81920];

int main(void) {
    for (int i = 1; i <= 80000; i++) {
        mem[i] = mem[i - 1];
        if (i % 3 == 0 || i % 7 == 0) mem[i] += i;
    }
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        printf("%lld\n", mem[n]);
    }
    return 0;
}