#include <stdio.h>

/*
문제 : 절댓값이 1000보다 작은 네 정수 A, B, A^2B, AB^2이 주어진다. 이때, 0으로 주어진 수를 적절히 바꾸어
나머지 수들이 성립하도록 하는 방법 가운데 사전순으로 가장 빠른 것을 찾는다. 바꾼 수는 0이 되어서는 안 되고,
A >= B여야 한다.

해결 방법 : A, B를 -999부터 999까지 각 범위에 대해 찾아보며 조건을 만족하는지 매번 확인한다.
조건이 매우 많기 때문에 조건 확인에 유의한다.

주요 알고리즘 : 수학, 브루트 포스

출처 : LtOI 11II 2번
*/

int main(void) {
    int a, b, a2b, ab2;
    scanf("%d %d %d %d", &a, &b, &a2b, &ab2);
    for (int i = -999; i < 1000; i++) {
        if (i == 0 || (a != 0 && i != a)) continue;
        for (int j = -999; j <= i; j++) {
            if (j == 0 || (b != 0 && j != b)) continue;
            if (a2b != 0 && i * i * j != a2b) continue;
            if (ab2 != 0 && i * j * j != ab2) continue;
            printf("%d %d %d %d", i, j, i * i * j, i * j * j);
            return 0;
        }
    }
    return 1;
}