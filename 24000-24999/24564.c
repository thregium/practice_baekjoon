#include <stdio.h>
#define SIZE 131072

/*
���� : N(N <= 100000)���� ���� �ƴ� ����(<= 100000)�� �̷���� ������ �ִ�.
�� ������ ������ �� ��� �ּڰ� * ������ ������ ���� ��� ���� ū ���� �׷��� ������ ���Ѵ�.
��, �̷��� ������ �����ϰ� ��������.

�ذ� ��� : ��ü �������� �ּڰ��� ��ġ�� ���� ����, ���� ���ϰ� �ּڰ� ������ ������ ����,
������ �翷���� �ɰ��� ������ ũ�Ⱑ 0�� �� �� ���� �̸� �ݺ��� ���� ���� ����ϸ� �ȴ�.
�̶�, �ִ� Nȸ ��Ͱ� ���Ƿ� ���׸�Ʈ Ʈ���� ���� �ּڰ��� ��ġ�� ���ϴ� ������
O(NlogN)���� ����ȭ�ؾ� �Ѵ�.

�ֿ� �˰��� : �ڷ� ����, ���׸�Ʈ Ʈ��, ���� ����

��ó : ECNA 2021 J��
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