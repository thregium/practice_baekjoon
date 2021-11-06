#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 10)개의 카드에 한 자리 또는 두 자리 수가 쓰여 있다. 이때, K(2 <= K <= 4)개의 카드를 이어붙여서 만들 수 있는
서로 다른 수의 개수를 구한다. 만든 방법이 다르더라도 수가 같다면 같은 수이다.

해결 방법 : 카드의 모든 순열에 대해 만들 수 있는 수를 구한 다음, 정렬하여 중복을 제외한 수의 개수를 세면 된다.
브루트 포스를 하며 한 자리인 경우와 두 자리인 경우를 서로 나누어 확인해야 한다.

주요 알고리즘 : 브루트 포스

출처 : JOI 2010예 4번
*/

int card[16], chk[16], res[5120];
int rp = 0;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

void track(int n, int k, int l, int r) {
    if (k == l) {
        res[rp++] = r;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        if (card[i] < 10) track(n, k, l + 1, r * 10 + card[i]);
        else track(n, k, l + 1, r * 100 + card[i]);
        chk[i] = 0;
    }
}

int main(void) {
    int n, k, r = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &card[i]);
    }
    track(n, k, 0, 0);
    if (rp > 5120) return 1;
    qsort(res, rp, sizeof(int), cmp1);
    for (int i = 0; i < rp; i++) {
        if (i == 0 || res[i] != res[i - 1]) r++;
    }
    printf("%d", r);
    return 0;
}