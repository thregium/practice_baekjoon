#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200000)개의 점이 좌표평면상에 주어진다. 모든 점 쌍들의 맨해튼 거리 합을 구한다.
각 점의 좌표는 10^6 이하의 자연수로 주어진다.

해결 방법 : 각 점의 좌표를 X와 Y로 분해하여 각각 더하더라도 답은 일정함을 알 수 있다.
또한, 각 1차원 좌표들을 정렬한 다음 각 구간별 거리와 중복 횟수를 곱한 것을 전부 더하면 각 축의
거리 합이 된다. 중복 횟수는 더 좌표가 작은 점 수 + 큰 점 수이고 거리는 인접한 두 수의 차이다.
이를 계산해 전부 더해나가면 된다.

주요 알고리즘 : 수학, 조합론, 정렬, 기하학

출처 : Rocky 2020 G번
*/

int x[204800], y[204800];

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
        scanf("%d %d", &x[i], &y[i]);
    }
    qsort(x, n, sizeof(int), cmp1);
    qsort(y, n, sizeof(int), cmp1);
    for (long long i = 1; i < n; i++) {
        r += ((long long)x[i] - x[i - 1]) * i * (n - i);
        r += ((long long)y[i] - y[i - 1]) * i * (n - i);
    }
    printf("%lld", r);
    return 0;
}