#include <stdio.h>
#define SIZE 131072

/*
문제 : N(N <= 100000)개의 수로 이루어진 수열에서 수열의 특정 구간[i, j]를 골라 min(i, j) * sum(i, j)가 가장 큰 값이 될 때의
해당 값과 그 구간을 구한다.

해결 방법 : 세그먼트 트리에 가장 작은 값의 위치를 저장해 풀 수 있다. 처음에는 전체 범위를 확인한 다음에
가장 작은 값을 기준으로 왼쪽과 오른쪽 범위를 확인한다. 만약 범위가 맞지 않거나 1칸만 남으면 해당 부분의 탐색을 종료한다.
범위를 확인할 때에는 합 배열을 전처리를 통해 합을 빠르게 구하고 해당 범위의 가장 작은 값의 위치를 확인하고 원래 배열에서
해당 위치를 찾으면 가장 작은 값도 구할 수 있다. 모든 부분의 탐색이 완료되면 지금까지 구한 가장 큰 수의 값을 출력한다.

주요 알고리즘 : 자료구조, 세그먼트 트리, 분할 정복

출처 : NEERC 2005 F번
*/

int a[103000], stree[SIZE << 1];
long long sum[103000], bbest;
int bl = 1, br = 1;

int small(int a, int b) {
    return a < b ? a : b;
}

long long big(long long a, long long b) {
    return a > b ? a : b;
}

long long sums(int l, int r) {
    return sum[r] - sum[l - 1];
}

int findsmallest(int l, int r, int sl, int sr, int p) {
    if (l > sr || r < sl) return 0;
    else if (l <= sl && r >= sr) return stree[p];

    int ls = findsmallest(l, r, sl, (sl + sr) >> 1, p << 1);
    int rs = findsmallest(l, r, ((sl + sr) >> 1) + 1, sr, (p << 1) + 1);
    if (a[ls] < a[rs]) return ls;
    else return rs;
}

void find(int l, int r) {
    if (l > r) return 0;
    int m = findsmallest(l, r, 0, SIZE - 1, 1);
    long long b = sums(l, r) * a[m];
    if (b > bbest) {
        bbest = b;
        bl = l;
        br = r;
    }
    find(l, m - 1);
    find(m + 1, r);
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        stree[SIZE + i] = i;
        sum[i] = a[i] + sum[i - 1];
    }
    a[0] = 1234567;
    for (int i = SIZE - 1; i >= 1; i--) {
        if (a[stree[i << 1]] < a[stree[(i << 1) + 1]]) stree[i] = stree[i << 1];
        else stree[i] = stree[(i << 1) + 1];
    }
    find(1, n);
    printf("%lld\n%d %d", bbest, bl, br);
    return 0;
}