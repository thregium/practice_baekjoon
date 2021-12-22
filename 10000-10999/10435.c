#include <stdio.h>

/*
문제 : N(N <= 1000)개의 구슬이 있는 Tchoukaillon 보드에서 이길 수 있는 경우를 출력한다. 이러한 경우는 유일하다.

해결 방법 : 1일 때 부터 역순으로 올라가며 구슬을 놓아보면 된다. 어떠한 곳에서 구슬을 움직이면 그 칸의 구슬들은 사라지고,
앞쪽 칸에 구슬이 1개씩 늘어나게 된다. 따라서, 이를 역순으로 하면 빈 칸에 구슬을 놓고 그 앞의 구슬들을 1개씩 지우면 된다.
이때, 빈 칸에서는 구슬을 뺄 수 없기 때문에 가장 앞쪽 빈 칸에 구슬을 놓아야 한다. 이를 N번 반복하면 원하는 상태를 구할 수 있다.

주요 알고리즘 : 애드 혹?

출처 : GNY 2014 E번
*/

int res[128];

int main(void) {
    int t, tn, n, b;
    //freopen("E:\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2014\\e.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Greater New York\\acmgnyr.org-master\\year2014\\e_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &tn, &n);
        b = 0;
        for (int i = 0; i < 128; i++) res[i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= b; j++) {
                if (res[j] == 0) {
                    res[j] = j + 1;
                    for (int k = 0; k < j; k++) res[k]--;
                    if (j == b) b++;
                    break;
                }
            }
        }
        printf("%d %d\n", tn, b);
        for (int i = 0; i < b; i++) {
            printf("%d", res[i]);
            if (i < b - 1) printf("%c", (i + 1) % 10 ? ' ' : '\n');
        }
        printf("\n");
    }
    return 0;
}