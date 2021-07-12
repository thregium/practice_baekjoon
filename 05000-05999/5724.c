#include <stdio.h>

/*
문제 : N * N(N <= 100) 크기의 격자 형태의 정사각형에서 찾을 수 있는 정사각형의 개수를 구한다.

해결 방법 : 한 변의 길이가 N인 직사각형 1개, N - 1인 직사각형 4개, N - 2인 직사각형 9개 ... 1인 직사각형 N * N개를 찾을 수 있다.
따라서 1부터 N * N까지 각 수의 제곱의 합을 구하면 된다.

주요 알고리즘 : 수학, 조합론

출처 : Latin 2008 F번
*/

int mem[128];

int main(void) {
    int n;
    mem[1] = 1;
    for (int i = 2; i <= 100; i++) {
        mem[i] = mem[i - 1] + i * i;
    }
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        printf("%d\n", mem[n]);
    }
    return 0;
}