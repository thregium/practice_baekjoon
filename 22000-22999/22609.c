#include <stdio.h>
#include <stdlib.h>

/*
문제 : 음이 아닌 정수 N(N <= 100000)과 자연수 P(P <= 100)가 주어질 때, N보다 큰 두 소수의 합(같은 소수 포함)으로
만들어지는 자연수 가운데 P번째로 작은 것의 값을 구한다.

해결 방법 : 100000 이후로 100개 이상이 되는 구간까지 미리 에라토스테네스의 체를 이용해 소수들을 구한다.
그리고 N과 P가 주어지면 N + 1부터 P개의 소수를 구해서 배열에 저장하고, 다시 2중 for문을 통해
모든 소수의 합을 구한다. 그 다음, 합을 구한 배열을 정렬하여 P번째 값을 구하면 그것이 답이 된다.

주요 알고리즘 : 구현, 수학, 에라토스테네스, 정렬

출처 : JAG 2009D B번
*/

char sieve[103000];
int prime[128], psum[16384];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, p, c;
    sieve[1] = 1;
    for (int i = 2; i <= 103000; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= 103000; j += i) sieve[j] = 1;
    }
    while (1) {
        scanf("%d %d", &n, &p);
        if (n < 0) break;
        c = 0;
        for (int i = n + 1; c < p; i++) {
            if (!sieve[i]) prime[c++] = i;
        }
        c = 0;
        for (int i = 0; i < p; i++) {
            for (int j = i; j < p; j++) psum[c++] = prime[i] + prime[j];
        }
        qsort(psum, c, sizeof(int), cmp1);
        printf("%d\n", psum[p - 1]);
    }
    return 0;
}