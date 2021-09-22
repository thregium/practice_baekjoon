#include <stdio.h>

/*
문제 : 길이 N(N <= 10000)의 0으로 초기화된 배열이 있을 때, Q(Q <= 1000)개의 쿼리에 응답한다.
1. P번째 수에 X를 더한다.
2. P부터 Q까지의 누적합을 출력한다.

해결 방법 : N과 Q가 크지 않기 때문에 직접 수를 업데이트하고 누적합을 구해도 된다.

주요 알고리즘 : 구현
*/

long long days[10240];

int main(void) {
    int n, q, o, p, x;
    long long s = 0;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d %d", &o, &p, &x);
        if (o == 1) days[p] += x;
        else {
            s = 0;
            for (int j = p; j <= x; j++) s += days[j];
            printf("%lld\n", s);
        }
    }
    return 0;
}