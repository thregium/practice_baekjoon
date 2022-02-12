#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)명의 아이들이 각각 갖고 있는 돌 수(<= 10^9, 자연수)가 주어진다.
앞에 있는 아이 중 자신보다 돌 수가 많거나 자신과 돌 수가 같은 아이가 있으면 그 아이가 운다면,
우는 아이의 수가 최소일 때의 우는 아이 수를 구한다.

해결 방법 : 앞에서부터 돌 수가 적은 순서대로 아이를 줄세우는 것이 최적임을 알 수 있다.
따라서, 모든 아이들을 돌 수 순으로 정렬한 다음, 앞 아이의 돌 수가 자신과 같은 아이 수를 세면 답이 된다.
(앞에 자신보다 돌 수가 많은 아이는 없을 것이므로)

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : UTI 2019 D번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) r++;
    }
    printf("%d", r);
    return 0;
}