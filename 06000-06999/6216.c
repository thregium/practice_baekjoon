#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 일을 하는 동안 사용되는 자원 양의 최솟값을 구한다. 각 일들은 시작하기 전까지
자원을 시간당 D_i(D_i <= 100)만큼 소모하며, 소요 시간은 T_i(T_i <= 10^6)이다.

해결 방법 : 두 일의 순서를 바꿔가며 확인해보면 T_i / D_i가 작은 것이 먼저 오는 것이 더 좋음을 알 수 있다.
또한, 이 순서는 어느 번째에 있든 그 관계가 유지되기 때문에 정렬을 사용할 수 있다.
위 값을 기준으로 정렬한 다음, 사용되는 자원의 합을 계산하면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : USACO 2007J S1번
*/

int cow[103000][2];
long long correct = 1234567890987654321;

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int bx = *(int*)b;
    int ay = *((int*)a + 1);
    int by = *((int*)b + 1);
    if (ax == 0 && ay == 0) ay = 1;
    if (bx == 0 && by == 0) by = 1;
    int r = ax * by - ay * bx;
    return r;
}
int main(void) {
    int n;
    long long r = 0, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cow[i][0], &cow[i][1]);
    }
    qsort(cow, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        r += cow[i][1] * s * 2;
        s += cow[i][0];
    }
    printf("%lld", r);
    return 0;
}