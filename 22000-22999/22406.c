#include <stdio.h>
#define INF 1012345678

/*
문제 : 두 명의 플레이어가 N, M(N, M <= 50)장의 카드로 카드 게임을 한다. (규칙 생략)
이 카드로 두 명이 최선의 전략으로 게임을 한다면 첫 번째 플레이어의 점수와
두 번째 플레이어의 점수 차이를 구한다.

해결 방법 : 두 명의 스택에 있는 카드와 사용이 끝난 지점의 경계선, 그리고 턴과 패스한 횟수를
저장한 다음, 다이나믹 프로그래밍을 돌리면 된다. 자세한 내용은 코드를 참조한다.

주요 알고리즘 : DP, 게임 이론

출처 : JAG 2016DA D번
*/

int a[64], b[64], mem[54][54][54][54][2][2]; //(in stack, unused)(a, b), turn, passes
char vis[54][54][54][54][2][2];

int getsum(int* arr, int st, int ed) {
    int res = 0;
    for (int i = st; i <= ed; i++) {
        if (arr[i] < 0) continue;
        res += arr[i];
    }
    return res;
}

int dp(int as, int au, int bs, int bu, int n, int m, int t, int l) {
    if (vis[as][au][bs][bu][t][l]) return mem[as][au][bs][bu][t][l];
    int res = 0, tdp;
    if (t) {
        if (l == 0) {
            res = dp(au, au, bu, bu, n, m, !t, l + (as == au && bs == bu)) +
                getsum(a, as, au - 1) - getsum(b, bs, bu - 1);
        }
        else res = 0;
        tdp = INF;
        if (bu <= m) {
            if (b[bu] < 0) tdp = dp(au, au, bs, bu + 1, n, m, !t, 0);
            else tdp = dp(as, au, bs, bu + 1, n, m, !t, 0);
        }
        if (tdp < res) res = tdp;
    }
    else {
        if (l == 0) {
            res = dp(au, au, bu, bu, n, m, !t, l + (as == au && bs == bu)) +
                getsum(a, as, au - 1) - getsum(b, bs, bu - 1);
        }
        else res = 0;
        tdp = -INF;
        if (au <= n) {
            if (a[au] < 0) tdp = dp(as, au + 1, bu, bu, n, m, !t, 0);
            else tdp = dp(as, au + 1, bs, bu, n, m, !t, 0);
        }
        if (tdp > res) res = tdp;
    }

    vis[as][au][bs][bu][t][l] = 1;
    return mem[as][au][bs][bu][t][l] = res;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }
    printf("%d\n", dp(1, 1, 1, 1, n, m, 0, 0));
    return 0;
}