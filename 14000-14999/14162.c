#include <stdio.h>

/*
문제 : [L, R](1 <= L <= R <= 10^6) 범위 있는 모든 수의 약수의 합의 합을 구한다.

해결 방법 : 1부터 R까지 해당 수의 배수마다 그 수의 약수의 합에 더한다.
이를 반복한 다음, L부터 R까지 약수의 합을 전부 더하면 답이 된다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스

출처 : CPC 2007 H번
*/

int f[1048576];

int main(void) {
    int l, r;
    long long res = 0;
    scanf("%d %d", &l, &r);
    for (int i = 1; i <= r; i++) {
        for (int j = i; j <= r; j += i) f[j] += i;
    }
    for (int i = l; i <= r; i++) res += f[i];
    printf("%lld", res);
    return 0;
}