#include <stdio.h>
#include <stdlib.h>

/*
문제 : N_i(N_i <= 1000)가지 부품이 3개의 부위에 대해 있다. 각 부위의 계수(<= 10^9)와,
각 부품의 성능(<= 10^9)이 주어지면 전체 제품의 계수 * 성능 합이 최댓값의 절반보다 큰 것의
가짓수를 구한다.

해결 방법 : 앞 두 부품의 계수 * 성능 값 합을 전부 계산해둔 다음, 정렬하고 마지막 부품들에 대해
앞 두 부품을 조립하여 최댓값의 절반 이상이 되는 것의 개수를 투 포인터를 이용해 센 다음 전부 더하면 된다.

주요 알고리즘 : 정렬, 투 포인터, 밋 인 더 미들

출처 : JPOI 2008 2-2번
*/

long long n[3], factory[3][1024], bk[1048576];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int b, k, z, bkcnt = 0, r = 0, pt = 0;
    long long best;
    scanf("%d %d %d", &b, &k, &z);
    for (int i = 0; i < 3; i++) {
        scanf("%lld", &n[i]);
        for (int j = 0; j < n[i]; j++) {
            scanf("%lld", &factory[i][j]);
            if (i == 0) factory[i][j] *= b;
            else if (i == 1) factory[i][j] *= k;
            else factory[i][j] *= z;
        }
    }

    for (int i = 0; i < n[0]; i++) {
        for (int j = 0; j < n[1]; j++) {
            bk[bkcnt++] = factory[0][i] + factory[1][j];
        }
    }
    qsort(bk, bkcnt, sizeof(long long), cmp2);
    qsort(factory[2], n[2], sizeof(long long), cmp1);
    best = bk[0] + factory[2][n[2] - 1];
    for (int i = 0; i < n[2]; i++) {
        while (pt < bkcnt && (factory[2][i] + bk[pt]) * 2 > best) pt++;
        r += pt;
    }
    printf("%d", r);
    return 0;
}