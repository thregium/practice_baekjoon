#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)명이 오는 동안 난로를 켜두려고 한다. 각 사람은 10^9 이하의 자연수 시간부터
1 동안만 있다가 간다. 불을 최대 K(1 <= K <= N)번 붙여둘 수 있다면 난로를 켜두는 시간의 최솟값을 구한다.
단, 2명 이상이 동시에 오는 경우는 없다.

해결 방법 : 각 사람이 간 다음 다음 사람이 오기까지의 시간을 전부 기록한 다음 내림차순으로 정렬한다.
첫 사람이 올 때 부터 마지막 사람이 갈 때 까지의 시간이 불을 1번만 켰을 때의 시간이고,
불을 1번 더 킬 수 있다면 다음 빈 시간대를 뺄 수 있으므로,
배열의 앞 (K - 1)개의 값을 앞에서 말한 값에서 빼면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : JOI 2018 1번
*/

int t[103000], itv[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, s;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    s = t[n - 1] - t[0] + 1;
    for (int i = 0; i < n - 1; i++) {
        itv[i] = t[i + 1] - t[i] - 1;
    }
    qsort(itv, n, sizeof(int), cmp1);
    for (int i = 0; i < k - 1; i++) {
        s -= itv[i];
    }
    printf("%d\n", s);
    return 0;
}