#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)마리의 소들은 각각 유행에 대한 역치 R_i(R_i <= 10^6)를 갖는다.
유행의 매력이 역치 이상이 된 소들은 유행에 참가한다. 어떤 유행의 매력이 L(L <= 50000)이고,
한 마리의 소가 참가할 때 마다 K(K <= 2500)씩 매력이 오른다면, 참가하게 되는 소의 마릿수를 구한다.

해결 방법 : 역치가 낮은 소들부터 살펴보면 된다. 그 소가 참가하지 않는다면 역치가 더 높은 소도 참가하지 않을 것이기 때문이다.
역치가 낮은 순으로 정렬한 다음, K + L * i의 값이 역치 이상이 되는 첫 지점이 그 소가 참가하지 않는 지점이므로
그 전까지 참가한 소의 수를 구하면 된다. 소 전체가 참여한다면 N을 출력한다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : USACO 2009O B2번
*/

int resi[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, l, k, r = 0;
    scanf("%d %d %d", &n, &l, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &resi[i]);
    }
    qsort(resi, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        if (resi[i] > l + k * i) {
            printf("%d", i);
            return;
        }
    }
    printf("%d", n);
    return 0;
}