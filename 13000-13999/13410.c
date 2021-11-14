#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)단의 1번째부터 K(K <= 1000)번째 까지의 수 가운데 뒤집어서 가장 큰 수를 구한다.

해결 방법 : N단의 각 수를 구한 다음, 일의 자리부터 역순으로 수들을 써 나간다. 그 다음, 이 값들을
strtoll 함수를 통해 정수로 바꾼 다음, 이 정수들 가운데 가장 큰 것을 찾으면 된다.

주요 알고리즘 : 수학

출처 : 국민대 2016 PA번
*/

char a[16];

int main(void) {
    int n, k, m, r = 0, j;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        m = n * i;
        for (j = 0; m; m /= 10, j++) {
            a[j] = m % 10 + '0';
        }
        a[j] = '\0';
        m = strtoll(a, NULL, 10);
        if (m > r) r = m;
    }
    printf("%d", r);
    return 0;
}