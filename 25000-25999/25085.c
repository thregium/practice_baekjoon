#include <stdio.h>
#include <string.h>

/*
문제 : 자연수 N(N <= 10^10)의 소인수 가운데 회문수인 것의 개수를 구한다.

해결 방법 : 주어진 수의 모든 소인수를 O(sqrt(N))에 구한 후 각 소인수들을 sprintf()로 문자열로 바꾸고
각 소인수들 가운데 소수인 것을 세면 된다.

주요 알고리즘 : 수학, 소수 판정, 문자열

출처 : GKS 2022B B번
*/

char buff[1024];

int ispal(char* s) {
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        if (s[i] != s[j]) return 0;
    }
    return 1;
}

int main(void) {
    int t, r;
    long long n;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%lld", &n);
        r = 0;
        for (long long i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                sprintf(buff, "%lld", i);
                if (ispal(buff)) r++;
                if (i * i == n) break;
                sprintf(buff, "%lld", n / i);
                if (ispal(buff)) r++;
            }
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}