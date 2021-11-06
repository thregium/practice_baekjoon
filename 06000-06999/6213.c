#include <stdio.h>
#define SZ 65536
#define INF 1012345678

/*
���� : N(N <= 50000)���� �ڿ���(<= 10^6)�� �־�����. �̶�, Q(Q <= 180000)���� ������ �־�����,
�� ������ ���� �迭�� ���� [S, E] ���� ���� ���� �ڿ����� ���� ū �ڿ����� ���� ����Ѵ�.

�ذ� ��� : ���׸�Ʈ Ʈ�� 2���� �̿��Ѵ�. �ϳ����� �ִ�, �ٸ� �ϳ����� �ּڰ��� �����ص� ����,
[S, E] ������ �ִ񰪰� �ּڰ��� ���� ���ؼ� ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ���׸�Ʈ Ʈ��

��ó : USACO 2007J G1��
*/

int tall[SZ * 2], shor[SZ * 2];

int big(int a, int b) {
    return a > b ? a : b;
}

int small(int a, int b) {
    return a < b ? a : b;
}

int getbig(int s, int e, int ns, int ne, int p) {
    if (e < ns || ne < s) return 0;
    else if (s <= ns && ne <= e) return tall[p];
    else return big(getbig(s, e, ns, (ns + ne) >> 1, p << 1), getbig(s, e, ((ns + ne) >> 1) + 1, ne, (p << 1) + 1));
}

int getsmall(int s, int e, int ns, int ne, int p) {
    if (e < ns || ne < s) return INF;
    else if (s <= ns && ne <= e) return shor[p];
    else return small(getsmall(s, e, ns, (ns + ne) >> 1, p << 1), getsmall(s, e, ((ns + ne) >> 1) + 1, ne, (p << 1) + 1));
}

int main(void) {
    int n, q, s, e;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < SZ * 2; i++) shor[i] = INF;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tall[SZ + i]);
        shor[SZ + i] = tall[SZ + i];
    }
    for (int i = SZ - 1; i > 0; i--) {
        tall[i] = big(tall[i << 1], tall[(i << 1) + 1]);
        shor[i] = small(shor[i << 1], shor[(i << 1) + 1]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", getbig(s, e, 0, SZ - 1, 1) - getsmall(s, e, 0, SZ - 1, 1));
    }
    return 0;
}