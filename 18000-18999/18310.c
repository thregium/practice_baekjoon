#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200000)개의 100000 이하의 자연수가 있다. N개의 자연수와의 차의 합이 가장 작은 자연수 가운데 가장 작은 자연수를 구한다.

해결 방법 : 각 자연수를 왼쪽으로 1 움직이면 해당 자연수의 왼쪽에 있던 자연수와는 가까워지고 해당 자연수와 같거나 오른쪽에 있던 자연수와는 멀어진다.
반대로 오른쪽으로 움직이면 오른쪽과는 가까워지고 왼쪽이나 같은 수와는 멀어진다. 따라서, 왼쪽의 자연수와 오른쪽의 자연수 개수가 서로 같은
자연수에서 가장 거리가 가까워진다. 이러한 경우는 N이 홀수일 때에는 (N + 1) / 2번째 원소의 값과 같고, 짝수일 때에는
N / 2번째 원소와 N / 2 + 1번째 원소 사이의 모든 원소지만 가장 작은 자연수이므로 N / 2번째 원소이다.

주요 알고리즘 : 그리디 알고리즘, 정렬
*/

int homes[204800];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &homes[i]);
    }
    qsort(homes, n, sizeof(int), cmp1);
    printf("%d", homes[(n - 1) >> 1]);
    return 0;
}