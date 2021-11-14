#include <stdio.h>

/*
문제 : 1부터 N(N <= 1000)까지의 자연수 가운데 M(M <= N)개의 자연수(<= 1000) 가운데 하나 이상의 배수인 수의 합을 구한다.

해결 방법 : 각 수들을 입력받은 다음, 1부터 N까지 각각에 대해 각 수들 가운데 하나 이상의 배수인지 확인하고
그렇다면 결괏값에 해당 수를 더한다. 이를 반복한 결괏값을 출력하면 된다.

주요 알고리즘 : 브루트 포스

출처 : 충남대 3회 A번
*/

int k[1024];

int main(void) {
    int n, m, r = 0, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &k[i]);
    }
    for (int i = 1; i <= n; i++) {
        t = 0;
        for (int j = 0; j < m; j++) {
            if (i % k[j] == 0) {
                t = 1;
                break;
            }
        }
        if (t) r += i;
    }
    printf("%d", r);
    return 0;
}