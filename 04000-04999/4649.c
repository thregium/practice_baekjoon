#include <stdio.h>

char cust[128];
char salon[32], vis[26];

/*
문제 : N(N <= 20)개의 자리가 있는 태닝숍에 고객들이 온다. 고객들은 'A'부터 'Z'까지의 알파벳으로
주어지며, 고객이 들어오는 것과 나가는 것이 한 쌍이고, 한 알파벳은 한 쌍까지만 주어진다.
이때, 고객들은 빈 자리가 없으면 그대로 돌아간다면, 돌아가는 고객의 수를 구한다.

해결 방법 : 각 고객이 올 때마다 그 고객이 들어올 자리를 찾고, 나갈 때 마다 그 고객을 찾아서
나가게 한다. 들어올 자리가 없었던 경우를 세서 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : MidC 2002 F번
*/

int main(void) {
    int n, r, ok;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s", cust);
        for (int i = 0; i < n; i++) salon[i] = '\0';
        for (int i = 0; i < 26; i++) vis[i] = 0;
        r = 0;

        for (int i = 0; cust[i]; i++) {
            if (vis[cust[i] - 'A']) {
                for (int j = 0; j < n; j++) {
                    if (salon[j] == cust[i]) salon[j] = '\0';
                }
            }
            else {
                ok = 0;
                for (int j = 0; j < n; j++) {
                    if (salon[j] == '\0') {
                        salon[j] = cust[i];
                        ok = 1;
                        break;
                    }
                }
                if (!ok) r++;
            }
            vis[cust[i] - 'A'] = 1;
        }
        
        if (!r) printf("All customers tanned successfully.\n");
        else printf("%d customer(s) walked away.\n", r);
    }
    return 0;
}