#include <stdio.h>
#define SZ 1048576

/*
���� : ���� N(N <= 500000)�� �迭�� �־��� ��, �� �迭�� �����Ʈ�Ѵٸ� �� ȸ ��Ʈ �� ������ �Ϸ�Ǵ��� ���Ѵ�.

�ذ� ��� : �� ������ �ڽ��� �տ� �ִ� �ڽź��� ū ���� ���� �ڽ��� �ڷ� ���� ������ �Ϸ�ȴ�.
�׷���, �� ������ �� ��Ʈ���� 1������ �ڷ� ���� ������ �ڽ��� �տ� �ִ� �ڽź��� ū ���� ������ �ִ밪�� ���� �ȴ�.
�� ���� ���׸�Ʈ Ʈ���� �̿��� ã�Ƴ� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���, ���׸�Ʈ Ʈ��
*/

int a[524288], seg[SZ << 1];

int big(int a, int b) {
    return a > b ? a : b;
}

int find(int fl, int fr, int sl, int sr, int p) {
    if (fr < sl || fl > sr) return 0;
    if (fl <= sl && sr <= fr) return seg[p];
    return find(fl, fr, sl, (sl + sr) >> 1, p << 1) + find(fl, fr, ((sl + sr) >> 1) + 1, sr, (p << 1) + 1);
}

int upd(int x) {
    seg[x + SZ]++;
    for (int i = ((x + SZ) >> 1); i > 0; i >>= 1) seg[i] = seg[i << 1] + seg[(i << 1) + 1];
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        r = big(r, find(a[i] + 1, SZ - 1, 0, SZ - 1, 1));
        upd(a[i]);
    }
    printf("%d", r + 1);
    return 0;
}