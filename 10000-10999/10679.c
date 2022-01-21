#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 1000)개의 절댓값이 10^9 이하인 정수 또는 'x'로 이루어진 배열이 주어진다.
'x'의 값을 전부 같은 정수로 바꾸어 모든 홀수번째 정수는 인접한 정수보다 크고, 모든 짝수번째 정수는
인접한 정수보다 작도록 할 수 있는 값이 유일한지 구하고 유일하다면 그 값을 출력한다.
여럿이라면 "ambigious"를, 없다면 "none"을 출력한다.

해결 방법 : x의 범위를 -무한대에서 +무한대부터 시작해 좁혀나간다. 'x'가 홀수번째인 경우
양 옆 수 중 작은 수 - 1을 최댓값과 비교하여 좁히고, 짝수번째인 경우 양 옆 수 중 큰 수 + 1을
최솟값과 비교하여 좁힌다. 이를 반복하여 남은 구간이 크기 1인 경우 그 값을 출력하고,
2 이상이면 ambigious, 0이면 none을 출력하면 된다. 단, 'x'가 연이어 있거나 이미 인접한 수 2개가
규칙을 어기고 있다면 none을 출력해야 한다. 'x'의 값은 절댓값 10^9를 넘어갈 수 있음에 유의한다.

주요 알고리즘 : 그리디 알고리즘, 케이스 워크

출처 : JAG 2013P A번
*/

int a[1024], b[1024];
char buff[16];

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, hi, lo;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2013P\\regional-2013-data\\regional-2013-data\\A.in", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2013P\\regional-2013-data\\regional-2013-data\\A_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        a[0] = INF;
        for (int i = 1; i <= n; i++) {
            scanf("%s", buff);
            if (buff[0] == 'x') b[i] = 1;
            else a[i] = strtoll(buff, NULL, 10);
        }
        a[n + 1] = (n & 1 ? INF : -INF);
        lo = -INF, hi = INF;
        for (int i = 1; i <= n; i++) {
            if (!b[i]) {
                if (i & 1) {
                    if ((!b[i - 1] && a[i] >= a[i - 1]) || (!b[i + 1] && a[i] >= a[i + 1])) lo = INF + 1;
                }
                else {
                    if ((!b[i - 1] && a[i] <= a[i - 1]) || (!b[i + 1] && a[i] <= a[i + 1])) hi = -INF - 1;
                }
                continue;
            }
            if (i & 1) hi = small(hi, small(a[i - 1], a[i + 1]) - 1);
            else lo = big(lo, big(a[i - 1], a[i + 1]) + 1);
            if (b[i - 1] || b[i + 1]) {
                lo = INF + 1;
                hi = -INF - 1;
            }
        }

        if (lo > hi) printf("none\n");
        else if (lo != hi) printf("ambiguous\n");
        else printf("%d\n", lo);

        for (int i = 1; i <= n; i++) {
            a[i] = 0, b[i] = 0;
        }
    }
    return 0;
}