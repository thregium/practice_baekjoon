#include <stdio.h>
#define SIZE 131072

/*
���� : N(N <= 100000)���� ���� �̷���� �������� ������ Ư�� ����[i, j]�� ��� min(i, j) * sum(i, j)�� ���� ū ���� �� ����
�ش� ���� �� ������ ���Ѵ�.

�ذ� ��� : ���׸�Ʈ Ʈ���� ���� ���� ���� ��ġ�� ������ Ǯ �� �ִ�. ó������ ��ü ������ Ȯ���� ������
���� ���� ���� �������� ���ʰ� ������ ������ Ȯ���Ѵ�. ���� ������ ���� �ʰų� 1ĭ�� ������ �ش� �κ��� Ž���� �����Ѵ�.
������ Ȯ���� ������ �� �迭�� ��ó���� ���� ���� ������ ���ϰ� �ش� ������ ���� ���� ���� ��ġ�� Ȯ���ϰ� ���� �迭����
�ش� ��ġ�� ã���� ���� ���� ���� ���� �� �ִ�. ��� �κ��� Ž���� �Ϸ�Ǹ� ���ݱ��� ���� ���� ū ���� ���� ����Ѵ�.

�ֿ� �˰��� : �ڷᱸ��, ���׸�Ʈ Ʈ��, ���� ����

��ó : NEERC 2005 F��
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