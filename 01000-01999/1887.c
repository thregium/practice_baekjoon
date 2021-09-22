#include <stdio.h>

/*
문제 : T(T <= 20)개의 토핑을 가진 피자를 만들려고 한다. 그런데, N(N <= 52)가지 가운데 한 가지 조합이라도 포함하는 피자는
만들 수 없다고 하면 만들 수 있는 피자의 가짓수를 구한다.

해결 방법 : 비트마스킹을 통해 모든 종류의 토핑을 올리는 경우와 올리지 않는 경우에 대해 전부 살펴본다.
각 조합을 포함하는지는 그대로 구해도 되지만 비트마스킹과 and 연산을 통해 조금 더 빠르게 구할 수 있다.

주요 알고리즘 : 브루트 포스, 비트마스킹

출처 : USACO 2006O B3번
*/

int cont[64];

int main(void) {
    int t, n, z, p, r = 0;
    scanf("%d %d", &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &z);
        for (int j = 0; j < z; j++) {
            scanf("%d", &p);
            cont[i] += (1 << (p - 1));
        }
    }
    for (int i = 0; i < (1 << t); i++) {
        p = 1;
        for (int j = 0; j < n; j++) {
            if ((cont[j] & i) == cont[j]) {
                p = 0;
                break;
            }
        }
        r += p;
    }
    printf("%d", r);
    return 0;
}