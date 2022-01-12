#include <stdio.h>

/*
문제 : N(N <= 100)명이 알고 있는 각각 다른 사람의 개인정보와, 개인정보가 유출된 사람의 목록이 주어질 때,
이 중 개인정보를 유출한 사람이 유일한지 확인하고 유일하다면 그 사람의 번호를 출력한다.
자신의 개인정보는 유출하지 않았고, 알고 있는 다른 사람의 개인정보들 중 일부 또는 전부를 유출한다.

해결 방법 : 각 사람이 개인 정보를 알고 있는 지 여부를 배열에 저장한다. 각 사람마다 유출된 개인정보 모두를
알고 있는 지 확인하고 그러한 사람의 수를 구한다. 1명인 경우에는 그 사람의 번호를 출력하고, 그 외에는 -1을 출력한다.

주요 알고리즘 : 브루트 포스

출처 : JAG 2012D A번
*/

int know[128][128], leak[128];

int main(void) {
    int n, m, x, t;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2012D\\domestic-2012-judge-data\\judge\\A\\A1", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &x);
                know[i][x] = 1;
            }
        }
        scanf("%d", &m);
        x = -1;
        for (int i = 0; i < m; i++) {
            scanf("%d", &leak[i]);
        }
        for (int i = 1; i <= n; i++) {
            t = 1;
            for (int j = 0; j < m; j++) {
                if (!know[i][leak[j]]) t = 0;
            }
            if (t) {
                if (x < 0) x = i;
                else x = 0;
            }
        }
        printf("%d\n", x ? x : -1);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) know[i][j] = 0;
        }
    }
    return 0;
}