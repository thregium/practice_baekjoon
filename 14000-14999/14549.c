#include <stdio.h>

/*
문제 : 6개의 정삼각형의 각 변에 쓰인 수들이 주어진다. 각 삼각형들을 붙여서 육각형을 만들되,
안쪽에 있는 수들은 인접한 변끼리 서로 같도록 하고, 바깥쪽 수들의 합을 가장 크게 만든다면 가장 큰 합을 구한다.
불가능하다면 none을 출력한다.

해결 방법 : 각 삼각형들을 놓고 돌려보며 인접한 변이 모두 같을 때의 가장 큰 합을 구하면 된다.

주요 알고리즘 : 브루트 포스, 백트래킹

출처 : Benin 2016 G번
*/

int tri[6][3], hex[6][3], chk[6];
int best = -1;

void track(int x) {
    if (x == 6) {
        int sum = 0;
        for (int i = 0; i < 6; i++) sum += hex[i][2];
        if (hex[5][0] != hex[0][1]) return;
        if (sum > best) best = sum;
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) hex[x][k] = tri[i][(k + j) % 3];
            if (x == 0 || hex[x][1] == hex[x - 1][0]) track(x + 1);
        }
        chk[i] = 0;
    }
}

int main(void) {
    char c;
    while (1) {
        for (int i = 0; i < 6; i++) {
            scanf("%d %d %d", &tri[i][0], &tri[i][1], &tri[i][2]);
        }
        best = -1;
        track(0);
        if (best < 0) printf("none\n");
        else printf("%d\n", best);
        scanf(" %c", &c);
        if (c == '$') break;
    }
    return 0;
}