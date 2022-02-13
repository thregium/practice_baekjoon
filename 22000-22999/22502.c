#include <stdio.h>

/*
문제 : 길이 L(L <= 10000)의 길이 있고, N(N <= 200)개의 당근이 있다.
당근을 먹으면 T(T <= 10000)초 동안 초속 V(V <= 10000)의 속도로 이동하고, 그 외의 시간에는
초속 U(1 <= U < V)의 속도로 이동한다. 한번에 당근을 K(K <= N)개까지만 들고 있을 수 있다면
길을 전부 지나는 데 걸리는 최소 시간을 구한다.

해결 방법 : 속도가 빨라진 상태가 아니라면 당근을 바로 쓰는 것이 최적이다.
당근을 추가로 저장해두면 나중에 저장할 당근을 쓸 수 없게 되거나 부스트가 늦게 끝나
손해가 되기 때문이다. 따라서, 속도가 빨라진 상태가 아니고 당근이 남았다면 곧바로 당근을 쓰고,
당근이 있는 곳에 올 때 마다 당근을 하나씩 가져온다. 더이상 가져올 수 없는 경우에는
그자리에서 당근을 먹는다. 이 방법이 최적이므로 이 방법으로 부스트된 거리를 구한 다음,
시간을 구하는 식에 대입해 답을 구하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : JAG 2011S2 I번
*/

int main(void) {
    int n, k, t, u, v, l, d, boost = 0, pos = 0, tbst = 0, carrot = 0;
    scanf("%d %d %d %d %d %d", &n, &k, &t, &u, &v, &l);
    for (int i = 0; i <= n; i++) {
        if (i == n) d = l;
        else scanf("%d", &d);
        while (pos < d) {
            if (boost == 0 && carrot > 0) {
                carrot--;
                boost = t * v;
            }
            if (boost > 0) {
                boost--;
                tbst++;
            }
            pos++;
        }
        if (carrot == k) boost = t * v;
        else carrot++;
    }
    printf("%.9f\n", (double)tbst / v + (double)(l - tbst) / u);
    return 0;
}