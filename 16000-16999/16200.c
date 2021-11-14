#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)명에 대해 팀을 짜려고 한다. 각 사람은 X_i(1 <= X_i <= N)명 이하인 팀에 들어갈 수 있다면,
만들어야 하는 팀의 최소 개수를 구한다.

해결 방법 : 각 사람을 X_i 기준 오름차순으로 정렬하고 순서대로 봅면, 해당 사람부터 X_i명으로 이루어진 팀을
만들 수 있음을 알 수 있다. 이를 반복하여 모두에게 팀이 짜여질 때 까지 팀의 개수를 구하면 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬
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
    for (int i = 0; i < n;) {
        r++;
        i += a[i];
    }
    printf("%d", r);
    return 0;
}