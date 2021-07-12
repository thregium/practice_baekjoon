#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 15000)개의 서로 다른 자연수가 주어질 때, 합이 M(M <= 10^7)이 되는 쌍의 개수를 구한다. 각 수는 100000 이하이다.

해결 방법 : 수들을 정렬한 후 양쪽 끝에서부터 수들을 확인해 나간다. 만약 두 수의 합이 M과 같다면 결괏값을 1 올린 다음
확인할 위치를 안쪽으로 1칸씩 당겨오며, M보다 크다면 오른쪽 수를, 작다면 왼쪽 수를 1칸 당겨온다.
만약 두 위치가 겹치거나 역전된 경우 탐색을 종료하고 결괏값을 출력하면 된다.

주요 알고리즘 : 정렬, 투 포인터
*/

int a[15360];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, lt, rt, res = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    lt = 0;
    rt = n - 1;
    while (lt < rt) {
        if (a[lt] + a[rt] == m) {
            lt++;
            rt--;
            res++;
        }
        else if (a[lt] + a[rt] < m) lt++;
        else rt--;
    }
    printf("%d", res);
    return 0;
}