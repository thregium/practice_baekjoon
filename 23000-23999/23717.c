#include <stdio.h>

/*
문제 : 길이 N(N <= 100000)의 각 칸에 원하는 색들이 주어질 때, 색을 최소 몇 번 칠해야 원하는 색이 나오는 지 구한다.
칠할 수 있는 색은 빨강, 노랑, 파랑이고, 한번에 연속한 칸들을 칠할 수 있다. 또한, 같은 칸에
여러 색을 칠하는 경우 색이 섞이게 되어 주황, 초록, 보라, 회색을 칠할 수 있다. 흰색은 색이 칠해지지 않은 경우이다.

해결 방법 : 각 칸의 각 색마다 칠해야 하는 빨강, 노랑, 파랑을 비트별로 저장한다.
그리고 각 색의 비트마다 칠하는 횟수를 확인한다. 칠할 때에는 같은 색의 덩어리를 최대한 넓게 칠하는 것이 좋다.
따라서, 그 덩어리의 개수를 세면 되는데, 이는 앞 칸은 칠하지 않고 해당 칸은 칠하는 경우의 개수를 세면 된다.
3가지 색에 대해 이를 합한 것이 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 비트마스킹

출처 : GKS 2021H B번
*/

char s[103000];
int tonum[26] = { 7, 4, -1, -1, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1, 3, 5, -1, 1, -1, -1, 0, -1, -1, -1, 2, -1 };

int main(void) {
    int t, n, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        r = 0;
        for (int i = 1; i <= n; i++) s[i] = tonum[s[i] - 'A'];
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= n; j++) {
                if ((s[j] & (1 << i)) && (~s[j - 1] & (1 << i))) r++;
            }
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}