#include <stdio.h>
#define SZ 65536
#define INF 1012345678

/*
문제 : N(N <= 50000)개의 자연수(<= 10^6)가 주어진다. 이때, Q(Q <= 180000)개의 쿼리가 주어지면,
각 쿼리에 대해 배열의 구간 [S, E] 사이 가장 작은 자연수와 가장 큰 자연수의 차를 출력한다.

해결 방법 : 세그먼트 트리 2개를 이용한다. 하나에는 최댓값, 다른 하나에는 최솟값을 저장해둔 다음,
[S, E] 구간의 최댓값과 최솟값을 각각 구해서 차를 구하면 된다.

주요 알고리즘 : 자료구조, 세그먼트 트리

출처 : USACO 2007J G1번
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