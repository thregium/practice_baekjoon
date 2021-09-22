#include <stdio.h>

/*
문제 : 10진수 N(N <= 10^6)이 주어질 때, M(M <= 16)진법으로 표현한 결과를 출력한다.

해결 방법 : 마지막 자릿수부터 역순으로 저장한 후, 다시 역순으로 꺼내서 출력하면 된다.

주요 알고리즘 : 수학

출처 : 한양대E 2017A G번
*/

int res[32];

int main(void) {
    int m, n, p = 0;
    scanf("%d %d", &m, &n);
    if (m == 0) {
        printf("0");
        return 0;
    }
    while (m) {
        res[p++] = m % n;
        m /= n;
    }
    for (int i = p - 1; i >= 0; i--) {
        if (res[i] < 10) printf("%d", res[i]);
        else printf("%c", res[i] - 10 + 'A');
    }
    return 0;
}