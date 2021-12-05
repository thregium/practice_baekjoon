#include <stdio.h>
#define SZ 262144

/*
문제 : 1부터 N(N <= 100000)까지의 자연수가 차례로 있는 목록이 주어질 때,
M(M <= 100000)개의 수를 차례로 맨 앞으로 옮기는 과정에서 해당하는 수의 앞에 있는 수들을 차례로 출력한다.

해결 방법 : 세그먼트 트리를 이용해서 리프 노드에는 각 위치별로 수가 있는지 여부를 저장한다.
그러면 0번 노드부터 p - 1(p는 해당 수의 위치)번 노드까지 살피는 것으로 앞의 수 개수를 알 수 있다.
개수를 확인한 다음에는 p번 노드의 값을 0으로 바꾸고 f - 1(f는 맨 앞 수의 위치)번 노드의 값을 1로 바꾼다.
그러면 맨 앞으로 옮기는 것과 같은 상태가 된다.
이를 위해서 각 수의 p값을 저장해두고 있어야 하고, 초기 상태에서 f는 m 이상이 되어야 한다.
또한, 초기화에 유의한다.

주요 알고리즘 : 자료 구조, 세그먼트 트리

출처 : NWERC 2011 C번
*/

int seg[SZ * 2], pos[103000];

int getupper(int s, int e, int p, int ss, int se) {
    if (s > se || e < ss) return 0;
    if (s <= ss && se <= e) return seg[p];
    return getupper(s, e, p << 1, ss, (ss + se) >> 1) + getupper(s, e, (p << 1) + 1, ((ss + se) >> 1) + 1, se);
}

void upd(int p, int x) {
    seg[SZ + p] = x;
    for (int i = (SZ + p) >> 1; i >= 1; i >>= 1) {
        seg[i] = seg[i << 1] + seg[(i << 1) + 1];
    }
}

int main(void) {
    int t, n, m, x;
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2011\\testdata\\C.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2011\\testdata\\C_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < SZ; i++) {
            if (m <= i && i < n + m) seg[SZ + i] = 1;
            else seg[SZ + i] = 0;
        }
        for (int i = SZ - 1; i >= 1; i--) seg[i] = seg[i << 1] + seg[(i << 1) + 1];
        for (int i = 1; i <= n; i++) pos[i] = m + i - 1;

        for (int i = 1; i <= m; i++) {
            scanf("%d", &x);
            printf("%d ", getupper(0, pos[x] - 1, 1, 0, SZ - 1));
            upd(pos[x], 0);
            upd(m - i, 1);
            pos[x] = m - i;
        }
        printf("\n");
    }
    return 0;
}