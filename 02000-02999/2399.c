#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10000)개의 자연수(<= 10^9)가 주어질 때, 모든 수 쌍의 차의 합(절댓값)을 구한다.

해결 방법 : 먼저, 각 수들을 정렬한다. 각 구간별로 수 쌍의 차를 구한 다음 겹치는 횟수만큼 곱해서 더하면 답을 구할 수 있다.
각 구간에서 겹치는 횟수를 보면 해당 구간의 왼쪽에 있는 수의 개수 * 오른쪽에 있는 수의 개수 * 2이다.
이 값들은 모두 간단히 계산이 가능하고, 수 쌍의 차이도 절댓값 함수를 통해 간단히 계산 가능하므로 이를 계산하면 된다.

주요 알고리즘 : 수학, 조합론, 정렬
*/

int x[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    qsort(x, n, sizeof(int), cmp1);
    for (int i = 1; i < n; i++) {
        r += llabs(x[i] - x[i - 1]) * i * ((long long)n - i);
    }
    printf("%lld", r * 2);
    return 0;
}