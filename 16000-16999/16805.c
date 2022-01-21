#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 10000)개의 칸에 대해 M(M <= 100)가지 문화를 조사하여 서부식인 칸과 동부식인 칸을 기록했다.
각 칸들을 동서로 나누는 경계선을 칸 사이에 놓았을 때 오차(서쪽에 있는 동부식, 동쪽에 있는 서부식)가
가장 적은 경계선을 구한다. 그러한 경우가 여럿인 경우 가장 서쪽에 있는 것을 출력한다.

해결 방법 : 누적 합을 통해 해당 칸의 서쪽에 있는 동부식 문화의 수와 해당 칸의 동쪽에 있는 서부식 문화의
합을 구해둔 다음, 둘의 합이 가장 작아지는 칸 중 가장 서쪽에 있는 것을 구하면 된다.

주요 알고리즘 : 누적 합

출처 : JAG 2015P4 A번
*/

char s[10240];
int w[10240], e[10240];

int main(void) {
    int n, m, best = INF, r = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%s", s);
        for (int j = 0; j < n; j++) {
            if (s[j] == 'E') e[j + 1]++;
            else w[j]++;
        }
    }
    for (int i = 1; i <= n; i++) e[i] += e[i - 1];
    for (int i = n - 1; i >= 0; i--) w[i] += w[i + 1];
    for (int i = 0; i <= n; i++) {
        if (w[i] + e[i] < best) {
            best = w[i] + e[i];
            r = i;
        }
    }
    printf("%d %d", r, r + 1);
    return 0;
}