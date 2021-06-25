#include <stdio.h>

/*
문제 : N * N(N <= 50) 크기의 격자에서 모든 가로, 세로줄에 X가 한 개 이상 있도록 X를 추가하려 할 때, 필요한 X의 최소 개수를 구한다.

해결 방법 : 각 가로줄과 세로줄에 대해 X가 전혀 없는 줄의 수를 구한다. 해당하는 가로줄과 세로줄이 교차하는 지점에 각각 X를
놓는다고 생각하면 가로줄이나 세로줄 중 더 많은쪽 줄만 남을 것이다.(물론 같다면 남지 않는다.) 여기서 모든 해당 줄의
임의의 점에 각각 X를 놓으면 모들 줄에 X가 한 개 이상씩 있게 된다. 따라서, 필요한 X의 최소 개수는
X가 전혀 없는 가로줄 수와 세로줄 수 중 더 큰 것이 된다.

주요 알고리즘 : 그리디 알고리즘
*/

char s[64][64];

int main(void) {
    int n, m, rcnt = 0, ccnt = 0, cnt;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; i++) {
        cnt = 1;
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'X') cnt = 0;
        }
        rcnt += cnt;
    }
    for (int i = 0; i < m; i++) {
        cnt = 1;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == 'X') cnt = 0;
        }
        ccnt += cnt;
    }
    if (rcnt > ccnt) printf("%d", rcnt);
    else printf("%d", ccnt);
    return 0;
}