#include <stdio.h>
#include <string.h>

/*
문제 : M(2 <= M <= 50) 이상의 자연수 가운데 최초로 N(N <= 500000)개의 M 이상인 모든 자연수로
나누어 떨어지지 않는 가장 작은 수가 가장 크도록 각 자연수들을 설정했 때, 나누어 떨어지지 않는
가장 작은 수의 값을 구한다. 답은 7368791 이내이다.

해결 방법 : M부터 수를 올려가며 7368791까지 에라토스테네스의 체를 이용하면 된다.
체에 걸러지지 않은 수가 나오면 그 수의 배수를 거른다. 이를 반복하며 걸러지지 않은
N번째 수가 나오면 그 수를 출력하면 된다. 단, 시간 제한에 걸릴 수 있기 때문에 비트 집합을 이용해야 한다.

주요 알고리즘 : 수학, 에라토스테네스, 비트셋

출처 : JDC 2016 C번
*/

unsigned char sieve[1048576];

int main(void) {
    int n, m;
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0) break;
        memset(sieve, 0, 1048576);
        for (int i = m;; i++) {
            if (sieve[i >> 3] & (1 << (i & 7))) continue;
            if (!(n--)) {
                printf("%d\n", i);
                break;
            }
            for (int j = i; j <= 7368791; j += i) {
                sieve[j >> 3] |= (1 << (j & 7));
            }
        }
    }
    return 0;
}