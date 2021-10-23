#include <stdio.h>
#include <stdlib.h>

/*
문제 : 두 자연수 N, M(N, M <= 10^9)이 주어질 때, 두 수를 자릿수끼리 비교해서 더 작은 자릿수를 전부 지웠다.
해당 연산이 끝나고 두 수의 값을 구한다. 단, 자릿수가 하나도 남지 않았다면 "YODA"를 출력하고,
비교할 자릿수가 없는 경우에는 0으로 간주한다.

해결 방법 : 뒷 자리부터 차례로 자릿수를 써 나간다. 만약 자릿수가 0이라면 YODA를 출력하고,
아니면 그 수를 거꾸로 돌린 다음 strtoll 함수를 통해 나온 수를 출력하면 된다.

주요 알고리즘 : 수학, 구현

출처 : COCI 15/16#4 1번
*/

char a[16], b[16], ar[16], br[16];

int main(void) {
    int n, m, ap = 0, bp = 0;
    scanf("%d %d", &n, &m);
    while (n > 0 || m > 0) {
        if (n % 10 > m % 10) a[ap++] = n % 10 + '0';
        else if (n % 10 < m % 10) b[bp++] = m % 10 + '0';
        else {
            a[ap++] = n % 10 + '0';
            b[bp++] = m % 10 + '0';
        }
        n /= 10;
        m /= 10;
    }
    if (ap == 0) printf("YODA\n");
    else {
        for (int i = 0; i < ap; i++) ar[14 - i] = a[i];
        printf("%lld\n", strtoll(ar + 15 - ap, NULL, 10));
    }
    if (bp == 0) printf("YODA");
    else {
        for (int i = 0; i < bp; i++) br[14 - i] = b[i];
        printf("%lld", strtoll(br + 15 - bp, NULL, 10));
    }
    return 0;
}