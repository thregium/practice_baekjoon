#include <stdio.h>
#include <stdlib.h>

/*
문제 : 카드 N(N <= 1000)개가 있고, 각 카드들을 붙이면 두 카드의 합과 같은 점수를 얻고, 둘 중 하나의 수로 바뀐다.
이때, 얻을 수 있는 최대 점수를 구한다.

해결 방법 : 각 카드들을 가장 높은 수가 쓰인 카드와 붙이는 것이 최적이다. 가장 큰 수와 다른 수의 합을 전부 더하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : 숭실대 2016 G번
*/

int l[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }
    qsort(l, n, sizeof(int), cmp1);
    for (int i = 1; i < n; i++) {
        r += l[0] + l[i];
    }
    printf("%lld", r);
    return 0;
}