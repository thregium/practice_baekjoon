#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 500)개의 2^a_i 크기의 타일(a_i <= 30)을 M * M(max(2^a_i) <= M < 2^31) 크기의
타일을 잘라서 만들기 위해 필요한 M * M 크기 타일의 개수를 구한다.

해결 방법 : 가장 큰 타일부터 차례로 잘라 나가기 시작한다. 타일을 새로 사올 때 마다 우선
가장 적은 개수의 정사각형으로 자르고, 현재 보고 있는 정사각형보다 큰 정사각형들은
현재 보고 있는 크기로 잘라준다. 이를 반복하며 현재 크기의 타일이 없으면 새로 사오면
사온 횟수가 최소가 되도록 할 수 있고, 이 횟수를 구하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : GKS 2014A C2번
*/

int a[512];
long long cnt[32];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, n, m, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp1);
        r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 30; j > a[i]; j--) {
                cnt[j - 1] += cnt[j] * 4;
                cnt[j] = 0;
            }
            if (cnt[a[i]] == 0) {
                for (int j = 30; j >= 0; j--) {
                    if ((m >> j) & 1) cnt[j] += ((long long)m >> j) + (m >> j) - 1;
                }
                r++;
                for (int j = 30; j > a[i]; j--) {
                    cnt[j - 1] += cnt[j] * 4;
                    cnt[j] = 0;
                }
            }
            cnt[a[i]]--;
        }
        printf("Case #%d: %d\n", tt, r);
        for (int i = 0; i < 32; i++) cnt[i] = 0;
    }
    return 0;
}