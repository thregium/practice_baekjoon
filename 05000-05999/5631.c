#include <stdio.h>
#include <stdlib.h>

/*
���� : N(N <= 200000)���� ���� ��ǥ��鿡 �ִ�. �� ���� ��ǥ�� 20000 ������ ���� �ƴ� �����̴�.
�̶�, �� ������ ��ǥ�� Q(Q <= 20000)���� �������� �־�����, �� ������ ������ ����
R1, R2(R1, R2 <= 13000)�� �� ��ȣ�屸�� ���� �� ���� ���� ���� ���� ���Ѵ�.
����1���� R1 ���Ϸ� ������ ��, ���� 2���� R2 ���Ϸ� ������ ���� ���� ��ȣ�屸�� 1���� �ش�.
�׸��� ��ȣ�屸�� 2���� ���� ��ȣ�屸�� ���� ���� 1���� ������ �� �ִ�.

�ذ� ��� : �� ���� ��ġ���� �ϳ��� ����1, �ٸ� �ϳ��� ���� 2���� �Ÿ��� �������� �Ͽ� �����Ѵ�.
�� ��, ������ ���� �� ���� �� ������ ���� �ȿ� �ִ� ���� ������ �̺� Ž���� ���� ���ش�.
��ȣ�屸�� ���� �� ���� ���� ���� ��ü ���� �� - (���� 1���� ���� �ȿ� �ִ� ���� ��) -
(���� 2���� ���� �ȿ� �ִ� ���� ��)�̰�, �� ���� ������ ��쿡�� 0�̴�.

�ֿ� �˰��� : ������, ����, �̺� Ž��

��ó : Hatyai 2012 A��
*/

typedef struct point {
    long long x, y;
} point;

point house[204800], distp1[204800], distp2[204800];
point npp1, npp2, comparing;

long long getdist(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int cmp1(const void* a, const void* b) {
    long long ai = getdist(*(point*)a, comparing);
    long long bi = getdist(*(point*)b, comparing);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int getcount(point* arr, int n, int d) {
    int lo = 0, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi + 1) >> 1;
        if (getdist(arr[mid - 1], comparing) <= d) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

int main(void) {
    int n, q, r1, r2, res;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &house[i].x, &house[i].y);
            distp1[i] = house[i];
            distp2[i] = house[i];
        }
        scanf("%lld %lld %lld %lld", &npp1.x, &npp1.y, &npp2.x, &npp2.y);
        comparing = npp1;
        qsort(distp1, n, sizeof(point), cmp1);
        comparing = npp2;
        qsort(distp2, n, sizeof(point), cmp1);
        scanf("%d", &q);
        printf("Case %d:\n", tt);
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &r1, &r2);
            comparing = npp1;
            res = getcount(distp1, n, r1 * r1);
            comparing = npp2;
            res += getcount(distp2, n, r2 * r2);
            if (res > n) printf("0\n");
            else printf("%d\n", n - res);
        }
    }
    return 0;
}