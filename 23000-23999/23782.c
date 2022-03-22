#include <stdio.h>
#include <stdlib.h>

/*
문제 : 자연수 N(N <= 10^12)이 주어질 때, N 이하의 모든 자연수를
N의 서로 다른 약수의 합으로 나타낼 수 있는 지 구한다.

해결 방법 : N의 모든 약수들을 찾은 다음 오름차순으로 정렬한다.
모든 자연수를 합으로 나타내기 위해서는 현재까지의 합 + 1보다 큰 약수가 나와서는 안 된다.
현재까지의 합을 갱신해 나가면서 그러한 경우가 있는 지 오름차순으로 확인하면 된다.

주요 알고리즘 : 수학, 정수론

출처 : CTU 2021 F번
*/

long long dv[103000];

int cmp1(const void* a, const void* b) {
    long long ai = *(long long*)a;
    long long bi = *(long long*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t, cnt, res;
    long long n, sum;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%lld", &n);
        cnt = 0;
        for (long long i = 1; i * i <= n; i++) {
            if (n % i) continue;
            dv[cnt++] = i;
            if (i * i != n) dv[cnt++] = n / i;
        }
        qsort(dv, cnt, sizeof(long long), cmp1);
        res = 1, sum = 0;
        for (int i = 0; i < cnt; i++) {
            if (dv[i] > sum + 1) res = 0;
            sum += dv[i];
        }
        printf("%s\n", res ? "Yes" : "No");
    }
    return 0;
}
