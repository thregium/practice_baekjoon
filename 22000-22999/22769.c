#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
문제 : N(N <= 50)명의 사람들이 각자 자신의 지도 조각을 갖고 있다. 각 사람이 일정이 비는 날이 주어지면
모든 지도 조각을 모으는 데 걸리는 시간을 구한다. 각 사람을 일정이 비는 날에 모여 한 사람에게
지도 조각들을 몰아주는 것이 가능하고, 받은 조각을 다시 몰아주는 것을 반복해 한 사람에게 전부 모아주면 된다.

해결 방법 : 각 날마다 각 사람이 가질 수 있는 지도 조각들을 확인한다. 이를 일정이 비는 사람의 쌍이 있다면
둘의 지도 조각들을 공유한다. 이를 각 날마다 반복하며 한 사람이 모든 지도 조각을 가지게 되는 날을 찾고,
그 날을 구하면 된다.

주요 알고리즘 : DP

출처 : JAG 2005D F번
*/

int day[32][64], mp[32][64][64];

int main(void) {
    int n, m, d, tc = 0;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2005D\\data\\F\\input\\F1", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2005D\\data\\F\\output\\F1_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &d);
                day[d][i] = 1;
            }
            for (int j = 1; j <= n; j++) mp[0][i][j] = 0;
            mp[0][i][i] = 1;
        }
        d = 0;
        for (int i = 1; i <= 30; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) mp[i][j][k] = mp[i - 1][j][k];
            }
            for (int j = 1; j <= n; j++) {
                for (int k = j + 1; k <= n; k++) {
                    if (day[i][j] && day[i][k]) {
                        for (int l = 1; l <= n; l++) {
                            mp[i][j][l] |= mp[i][k][l];
                            mp[i][k][l] |= mp[i][j][l];
                        }
                    }
                }
                d = 0;
                for (int k = 1; k <= n; k++) d += mp[i][j][k];
                if (d == n) {
                    printf("%d\n", i);
                    break;
                }
            }
            if (d == n) break;
        }
        if (d != n) printf("-1\n");

        for (int i = 1; i <= 30; i++) {
            for (int j = 1; j <= 50; j++) day[i][j] = 0;
        }
        tc++;
    }
    return 0;
}