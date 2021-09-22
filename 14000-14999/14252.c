#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 50)개의 100000 이하의 자연수가 주어진다. 이때, 최소한의 자연수를 추가해 정렬했을 때의 인접한 수들끼리의 GCD가
전부 1이 되게 하려고 한다. 추가해야 하는 자연수의 개수를 구한다.

해결 방법 : 브루트 포스를 통해 10만 이하의 모든 자연수쌍을 조사해보면 단 7개의 쌍을 제외한 모든 쌍은
사이에 최대 1개의 자연수를 끼워넣으면 인접한 수들끼리의 GCD가 1이 된다. 따라서, N개의 자연수를 정렬한 다음,
인접한 수들끼리 GCD가 1인지 확인한다. 그러하다면 넘어가고, 아니라면 위의 7개 쌍에 해당하는지 확인한다.
7개 쌍중 하나라면 결괏값에 2를 더하고 아니라면 1을 더한다.

주요 알고리즘 : 수학, 정수론

출처 : SRM 577D2 3번
*/

int a[64];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

int main(void) {
    int n, r  = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 1; i < n; i++) {
        if (gcd(a[i], a[i - 1]) == 1) continue;
        else if (a[i] - a[i - 1] == 16 && (a[i] == 2200 || a[i] == 27846 || a[i] == 32230 || a[i] == 57876 || a[i] == 62260 || a[i] == 87906 || a[i] == 92290)) r += 2;
        else r++;
    }
    printf("%d", r);
    /*
    for (int i = 1; i <= 100000; i++) {
        for (int j = i + 2; j <= 100000; j++) {
            t = 1;
            for (int k = i + 1; k < j; k++) {
                if (gcd(i, k) == 1 && gcd(j, k) == 1) {
                    t = 0;
                    break;
                }
            }
            if (t) {
                printf("%d - %d\n", i, j);
            }
        }
        if (i % 100 == 0) printf("%d completed\n", i);
    }
    */
    return 0;
}