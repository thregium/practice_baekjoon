#include <stdio.h>
#include <stdlib.h>

/*
문제 : K(K <= 100000)개의 너비가 L(L <= 100)cm인 판자가 있다. 이 판자를 한 줄에 최대 2개씩 연결해 N * M(N, M <= 10000)m
크기의 방을 판자를 자르지 않고 채우는 방법이 있는지 확인하고 있다면 판자를 가장 적게 사용할 때 사용하는 판자의 수를 구한다.

해결 방법 : 먼저, 판자의 너비가 양쪽 방향으로 놓았을 때 방의 너비와 나누어 떨어지는지 확인한다. 불가능하다면
이후로는 확인할 것도 없이 채울 수 없다. 가능하다면 판자들을 길이 순으로 정렬한 후, 길이가 방의 길이와 같은 판자의 수를 센다.
이 판자들로 방을 채울 수 있다면 반대 방향을 살펴보고 없다면 투 포인터를 이용해 판자 2개를 합쳐 사용하는 방법을 세본다.
두 가지 방법으로 채울 수 있는지 확인하고 있다면 그 때의 판자의 수를 확인한 후 반대 방향을 살펴보고, 없다면 채울 수 없다.
반대 방향도 마찬가지로 한 다음 채울 수 있는 방향 가운데 더 적게 사용하는 쪽을 출력하면 된다.

주요 알고리즘 : 정렬, 투 포인터

출처 : Brasil 2008 C번
*/

int a[103000];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, l, k, r1, r2, cnt, lo, hi;
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2008\\C.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Latin America\\Brasil\\2008\\C.out", "w", stdout);
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        scanf("%d%d", &l, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, k, sizeof(int), cmp1);
        r1 = 0, r2 = 0;
        if ((n * 100) % l == 0) {
            cnt = 0;
            lo = 0, hi = k - 1;
            while (a[hi] > m && hi >= 0) hi--;
            while (a[hi] == m && hi >= 0 && cnt * l < (n * 100)) {
                hi--;
                cnt++, r1++;
            }
            while (lo < hi && cnt * l < (n * 100)) {
                if (a[lo] + a[hi] == m) {
                    lo++, hi--;
                    cnt++, r1 += 2;
                }
                else if (a[lo] + a[hi] < m) lo++;
                else hi--;
            }
            if (cnt < (n * 100) / l) r1 = -1;
        }
        else r1 = -1;
        if ((m * 100) % l == 0) {
            cnt = 0;
            lo = 0, hi = k - 1;
            while (a[hi] > n && hi >= 0) hi--;
            while (a[hi] == n && hi >= 0 && cnt * l < (m * 100)) {
                hi--;
                cnt++, r2++;
            }
            while (lo < hi && cnt * l < (m * 100)) {
                if (a[lo] + a[hi] == n) {
                    lo++, hi--;
                    cnt++, r2 += 2;
                }
                else if (a[lo] + a[hi] < n) lo++;
                else hi--;
            }
            if (cnt < (m * 100) / l) r2 = -1;
        }
        else r2 = -1;

        if (r1 < 0 && r2 < 0) printf("impossivel\n");
        else if (r1 < 0) printf("%d\n", r2);
        else if (r2 < 0) printf("%d\n", r1);
        else if (r1 < r2) printf("%d\n", r1);
        else printf("%d\n", r2);
    }
    return 0;
}