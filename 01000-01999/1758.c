#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)명이 가져온 팁의 양이 주어진다. 각 사람이 실제로 주는 팁은 가져온 팁 - (받은 순위 - 1)이다.
단, 음수인 경우에는 0으로 처리한다. 이때, 받을 수 있는 최대 팁을 구한다.

해결 방법 : 팁을 적게 가져온 사람은 늦게 주더라도 돈을 뺏지 않기 때문에 늦게 주는 것이 이득이다.
따라서, 팁을 가져온 양에 대해 내림차순으로 정렬한 후 받을 수 있는 팁의 양을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬
*/

int t[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, tip;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    qsort(t, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        tip = t[i] - i;
        if (tip > 0) r += tip;
    }
    printf("%lld", r);
    return 0;
}