#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 20000)개의 선분(<= 2^60, 정수)이 주어질 때, 3개의 선분을 이어 넓이가 0이 아닌 삼각형을 만들 수 있는지 구한다. 

해결 방법 : 각 선분의 길이를 정렬한 다음, 인접한 3개씩의 선분을 살피며 삼각형을 만들 수 있는지 확인하면 된다.
삼각형을 만들 수 있는 경우는 짧은 두 변의 길이의 합이 긴 변의 길이보다 큰 경우이다. 따라서 차이를 최대한 줄이기 위해
정렬을 하고 인접한 것 끼리 비교하면 되는 것이다.

주요 알고리즘 : 그리디 알고리즘, 기하학, 정렬

출처 : BAPC 2016 L번
*/

long long tri[20480];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &tri[i]);
    }
    qsort(tri, n, sizeof(long long), cmp1);
    for (int i = 2; i < n; i++) {
        if (tri[i - 2] + tri[i - 1] > tri[i]) r = 1;
    }
    printf("%s", r ? "possible" : "impossible");
    return 0;
}