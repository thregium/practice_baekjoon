#include <stdio.h>
#define SIZE 131072

/*
문제 : N(N <= 100000)개의 음이 아닌 정수(<= 100000)로 이루어진 수열이 있다.
이 수열의 연속한 값 가운데 최솟값 * 연속한 구간의 길이 가운데 가장 큰 수와 그러한 구간을 구한다.
단, 이러한 구간은 유일하게 정해진다.

해결 방법 : 전체 구간에서 최솟값의 위치를 구한 다음, 값을 구하고 최솟값 구간을 갱신한 다음,
구간을 양옆으로 쪼개고 구간의 크기가 0이 될 때 까지 이를 반복한 다음 답을 출력하면 된다.
이때, 최대 N회 재귀가 들어가므로 세그먼트 트리를 통해 최솟값의 위치를 구하는 과정을
O(NlogN)으로 최적화해야 한다.

주요 알고리즘 : 자료 구조, 세그먼트 트리, 분할 정복

출처 : ECNA 2021 J번
*/

int a[103000], stree[SIZE << 1];
long long sum[103000], bbest = -1;
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
    long long b = (r - l + 1) * (long long)a[m];
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
    printf("%d %d %lld", bl, br, bbest);
    return 0;
}