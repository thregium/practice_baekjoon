#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 100000)개의 구간(<= 100000, 자연수)이 주어질 때, 모든 구간과 겹치기 위한 구간의 최소 길이를 구한다.

해결 방법 : 모든 구간 가운데 가장 늦은 시작점과 가장 빠른 끝점을 찾는다. 만약 시작점이 더 앞인 경우에는
모두가 서로 겹치므로 한 지점만 있으면 되고, 길이는 0이다. 끝점이 앞이라면 시작점과의 거리만큼이 필요하다.

주요 알고리즘 : 그리디 알고리즘

출처 : 숭실대 2019O F번
*/

int main(void) {
    int n, s, e, sb = -1, es = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s, &e);
        if (s > sb) sb = s;
        if (e < es) es = e;
    }
    if (sb < es) printf("0");
    else printf("%d", sb - es);
    return 0;
}