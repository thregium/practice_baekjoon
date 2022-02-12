#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)명의 참가자 가운데 K(K <= N)명과, K위와 같은 점수인 사람을 합격시키려고 한다.
각 사람의 점수(<= 1000, 자연수)가 주어질 때, 합격자 수를 구한다.

해결 방법 : 모든 사람의 점수를 내림차순으로 정렬한 후, K번째와 같은 점수인 마지막 사람까지의
인원수를 구하면 답이 된다.

주요 알고리즘 : 구현, 정렬

출처 : Brasil 2017 F번
*/

int a[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, r;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    r = k - 1;
    while (r < n - 1 && a[r] == a[r + 1]) r++;
    printf("%d", r + 1);
    return 0;
}