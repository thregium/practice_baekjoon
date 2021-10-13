#include <stdio.h>

/*
문제 : N(N <= 1000)개의 팀의 M(M <= 1000)개의 경기에 대한 양 팀의 득점이 주어진다. 이때, 각 팀의 피타고리안 승률 가운데
가장 높은 것과 가장 낮은 것에 대해 1000을 곱한 정수 부분을 구한다. 단, 0득점 0실점은 피타고리안 승률 0으로 정의한다.

해결 방법 : 모든 경기의 결과를 확인하며 각 팀의 득점과 실점을 배열로 저장한다.
모든 결과의 확인이 끝나면 각 팀 별 득점과 실점을 통해 피타고리안 승률을 정수형으로 계산한다. 0득점 0실점인 경우에 대해
예외처리를 해줘야 하고, 실수 오차를 방지하기 위해 매우 작은 값을 더해주는 것을 잊지 않는다.
각각을 계산한 다음, 가장 큰 것과 가장 작은 것의 값을 구하면 된다.

주요 알고리즘 : 수학, 구현

출처 : Daejeon 2015I J번
*/

int s[1024], sa[1024];

int pyt(double s, double a) {
    if (s == 0 && a == 0) return 0;
    double r = (s * s) / (s * s + a * a);
    r = r * 1000 + 0.0000001;
    return (int)r;
}

int main(void) {
    int t, n, m, a, b, p, q, rh, rl;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            s[i] = 0;
            sa[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d %d", &a, &b, &p, &q);
            s[a] += p;
            s[b] += q;
            sa[a] += q;
            sa[b] += p;
        }
        rh = -1, rl = 1001;
        for (int i = 1; i <= n; i++) {
            if (pyt(s[i], sa[i]) > rh) rh = pyt(s[i], sa[i]);
            if (pyt(s[i], sa[i]) < rl) rl = pyt(s[i], sa[i]);
        }
        if (rh < 0 || rl > 1000) return 1;
        printf("%d\n%d\n", rh, rl);
    }
    return 0;
}