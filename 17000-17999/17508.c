#include <stdio.h>

/*
문제 : N * M(N, M <= 500) 크기의 격자에 '6', '7', '8', '9'가 쓰여 있다.
이때, 이 격자들 중 일부를 돌려 180도 회전 대칭이 되도록 만들려고 한다.
만들 수 있는 지 확인하고 가능한 경우 돌리는 격자의 최소 개수를 구한다. 불가능하다면 -1을 출력한다.

해결 방법 : 우선 한가운데 칸이 있다면 그 칸에 쓰인 수는 반드시 회전대칭인 8이어야 한다.
그리고 배열 전체를 확인하면서 반대쪽 칸과 회전 대칭을 만들 수 있는 지 확인한다.
만들 수 없다면(6 <-> 9가 아니면서 서로 다른 수인 경우) 회전 대칭이 될 수 없다.
그 다음 7인 경우와 6, 9지만 서로 같은 수가 쓰인 경우를 전부 체크한다.
배열 순회가 끝나면 체크한 횟수 / 2(반대쪽으로 중복 계산되었으므로)를 하면 답이 된다.

주요 알고리즘 : 구현?, 케이스 워크

출처 : KAIST 2019F A번 / OC 19/20_5 A번
*/

char card[512][512];

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", card[i]);
    }
    if (n & m & 1) {
        if (card[n >> 1][m >> 1] != '8') {
            printf("-1");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((card[i][j] == '6' && card[n - i - 1][m - j - 1] == '9') ||
                (card[i][j] == '9' && card[n - i - 1][m - j - 1] == '6'));
            else if (card[i][j] != card[n - i - 1][m - j - 1]) {
                printf("-1");
                return 0;
            }

            if (card[i][j] == '7') r++;
            else if (card[i][j] == '8') continue;
            else if (card[i][j] == card[n - i - 1][m - j - 1]) r++;
        }
    }
    if (r & 1) return 1;
    printf("%d", r >> 1);
    return 0;
}