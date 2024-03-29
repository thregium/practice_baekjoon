#include <stdio.h>
#define MOD 1000000007

/*
문제 : H(H <= 10^6) 높이의 산에서 각 높이별로 눈덩이의 개수가 주어진다. 눈덩이는 높이 1만큼 내려올 때 마다 X(X <= 100)배로
크기가 증가한다. 높이 0에서의 모든 눈덩이들의 크기 합을 10^9 + 7로 나눈 나머지를 구한다.

해결 방법 : 위에서부터 눈덩이의 개수를 더하고 X를 곱하면서 내려오면 해당 높이 이상의 모든 눈덩이들의 크기 합을 구할 수 있다.
또한, 중간에 나머지를 구하더라도 나머지는 보존되기 때문에 수가 커지지 않도록 하면서 나머지를 구할 수 있다.

주요 알고리즘 : 수학, 정수론

출처 : 한양대 6회 AB/BJ번
*/

int c[1048576];

int main(void) {
    int h, x, r = 0;
    scanf("%d %d", &h, &x);
    for (int i = 1; i <= h; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = h; i > 0; i--) {
        r += c[i];
        r = ((long long)r * x) % MOD;
    }
    printf("%d", r);
    return 0;
}