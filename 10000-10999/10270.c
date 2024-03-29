#include <stdio.h>
#define MOD 1000000007

/*
문제 : N(N <= 100000)개의 원소로 이루어진 집합에서 자기 자신으로의 함수 가운데
항등 함수가 아닌 것의 개수를 10^9 + 7로 나눈 나머지를 구한다.

해결 방법 : 자기 자신으로의 함수는 N!개이다. (X * Y) % M = ((X % M) * (Y % M)) % M과 같으므로 1부터 N까지 곱해나가며
10^9 + 7으로 계속 나눈 나머지를 갖고 있는다. 항등 함수는 항상 1개이므로 1을 빼주면 되는데, 이때 음수가 될 수 있으므로
10^9 + 6을 더한 후 10^9 + 7로 나눈 나머지를 취하면 된다.

주요 알고리즘 : 수학, 조합론

출처 : GCPC 2014 A번
*/

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        r = 1;
        for (long long i = 1; i <= n; i++) {
            r = (r * i) % MOD;
        }
        printf("%d\n", (r + MOD - 1) % MOD);
    }
    return 0;
}