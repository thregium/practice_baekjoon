#include <stdio.h>

/*
문제 : 틱택토에서 한 수를 더 두면 이길 수 있는 판이 주어질 때, 한 수를 더 둔 결과를 출력한다.
단, 답은 유일하게 정해진다.

해결 방법 : 9칸 가운데 빈 칸에 각각 놓아본 다음 이길 수 있는 판을 찾으면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : UVaH 2013 E번
*/

char ttt[4][4];
int r = 0;

void printttt(int tt) {
    printf("Case %d:\n", tt);
    for (int i = 0; i < 3; i++) {
        printf("%s\n", ttt[i]);
    }
    r++;
}

int main(void) {
    int t, n;
    char c;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        for (int i = 0; i < 3; i++) {
            scanf("%s", ttt[i]);
        }
        scanf(" %c", &c);
        r = 0;
        for (int i = 0; i < 9; i++) {
            if (ttt[i / 3][i % 3] != '-') continue;
            ttt[i / 3][i % 3] = c;
            for (int j = 0; j < 3; j++) {
                if (ttt[j][0] == c && ttt[j][1] == c && ttt[j][2] == c) printttt(tt);
                if (ttt[0][j] == c && ttt[1][j] == c && ttt[2][j] == c) printttt(tt);
            }
            if (ttt[0][0] == c && ttt[1][1] == c && ttt[2][2] == c) printttt(tt);
            if (ttt[0][2] == c && ttt[1][1] == c && ttt[2][0] == c) printttt(tt);
            ttt[i / 3][i % 3] = '-';
        }
        if (r != 1) return 1;
    }
    return 0;
}