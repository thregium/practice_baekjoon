#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)그루의 나무를 심어야 하는데, 하루에 한 그루만 심을 수 있다.
각 나무가 자라는 기간이 주어지면 심기 시작해서 모든 나무가 자라기까지 걸리는 시간을 구한다.

해결 방법 : 자라는데 오래 걸리는 나무부터 심는 것이 최적이다.(이후에 심으면 더 오래 걸릴 것이므로)
따라서, 기간을 기준으로 내림차순 정렬한 다음, 순서 + 기간이 가장 긴 것의 시간을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : NCPC 2013 A번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (i + a[i] > r) r = i + a[i];
    }
    printf("%d", r + 2); //날짜 보정
    return 0;
}