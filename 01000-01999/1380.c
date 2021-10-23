#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 100)명의 이름과 N * 2 - 1개의 귀걸이 압수, 회수 기록이 주어질 때, 귀걸이를 돌려받지 못한 사람의 이름을 출력한다.
단, 한번 압수된 귀걸이는 다시 압수되지 않고, 압수된 후에 귀걸이를 돌려받는다.

해결 방법 : 정상적으로 돌려받았다면 귀걸이를 압수당하고 돌려받은 2개의 기록이 있을 것이다. 하지만, 돌려받지 못한 경우에는
압수만 당했으므로 1개의 기록만 있을 것이다. 따라서, 기록의 개수를 확인하고 1번만 기록이 있는 사람을 찾아
그 사람의 이름을 출력하면 된다.

주요 알고리즘 : 구현

출처 : NZPC 2006 E번
*/

char name[128][64];
int cnt[128];

int main(void) {
    int n, x, r;
    char c;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            fgets(name[i], 63, stdin);
            if (name[i][0] == '\n') {
                i--;
                continue;
            }
            if (name[i][strlen(name[i]) - 1] == '\n') name[i][strlen(name[i]) - 1] = '\0';
            cnt[i] = 0;
        }
        for (int i = 1; i < n * 2; i++) {
            scanf("%d %c", &x, &c);
            cnt[x]++;
        }
        r = -1;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 1) {
                if (r >= 0) return 1;
                r = i;
            }
        }
        if (r < 0) return 2;
        printf("%d %s\n", tt, name[r]);
    }
    return 0;
}