#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 25000)개의 장난감의 행복도와 가격이 주어질 때, 가격 대비 행복도가 가장 높은 장난감 3개를 사려고 한다.
이때, 필요한 돈과, 사야 할 장난감의 번호를 (가/행 비 순으로) 출력한다.

해결 방법 : 장난감들의 행복도와 가격을 입력받은 다음, 장난감의 번호를 같이 저장하고 가격 / 행복도 순으로 정렬한다.
이때, 실수 오차를 줄이기 위해 두 수를 통분한 다음, 분자의 값을 비교하는 것이 좋다.
정렬한 다음에는 앞쪽 3개의 가격 합을 출력한 다음, 앞쪽 3개의 번호를 차례로 출력한다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : USACO 2010F B3번
*/

long long toys[25600][3];

int cmp1(const void* a, const void* b) {
    long long ax = *(long long*)a;
    long long bx = *(long long*)b;
    long long ay = *((long long*)a + 1);
    long long by = *((long long*)b + 1);
    if (bx * ay - ax * by < 0) return -1;
    else if (bx * ay - ax * by == 0) return 0;
    else return 1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &toys[i][0], &toys[i][1]);
        if (toys[i][0] == 0 && toys[i][1] == 0) return 1;
        toys[i][2] = i + 1;
    }
    qsort(toys, n, sizeof(long long) * 3, cmp1);
    printf("%lld\n%lld\n%lld\n%lld", toys[0][1] + toys[1][1] + toys[2][1], toys[0][2], toys[1][2], toys[2][2]);
    return 0;
}