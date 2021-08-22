#include <stdio.h>

/*
문제 : N(N <= 123)개의 원판이 올려져있는 하노이 탑이 있다. 일반적인 하노이 탑의 규칙에서 작은 원반 위에 큰 원반이
올라갈 수 있다면 이 탑의 왼쪽에 있는 모든 원판들을 오른쪽으로 옮기는 방법을 구한다.
단, 주어지는 처음 상태 역시 작은 원판 위에 큰 원판이 올라간 상태일 수 있다. 또한, 옮기는 횟수는 최대 12345회까지만 가능하다.

해결 방법 : 첫 번째 또는 두 번째 탑에 쌓인 원판들 가운데 세 번째 탑에 올라갈 원판들은 세 번째 원판에 옮기고,
나머지 원판들은 반대쪽으로 옮긴다. 이를 반복하여 모든 원판들을 몲기면 된다. 많아야 N^2 / 2회 안에 옮길 수 있기 때문에
12345회 이내에 충분히 옮기는 것이 가능하다.

주요 알고리즘 : 그리디 알고리즘, 스택, 구성적
*/

int tower[3][128], move[16384][2];

int main(void) {
    int n, turn = 0, ntow = 0;
    scanf("%d", &n);
    tower[0][0] = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tower[0][i]);
    }
    while (tower[2][0] < n) {
        for (int i = tower[ntow][0]; i > 0; i--) {
            move[turn][0] = ntow + 1;
            if (tower[ntow][i] == n - tower[2][0]) {
                move[turn++][1] = 3;
                tower[2][++tower[2][0]] = tower[ntow][i];
            }
            else {
                move[turn++][1] = (!ntow) + 1;
                tower[!ntow][++tower[!ntow][0]] = tower[ntow][i];
            }
            tower[ntow][i] = 0;
            tower[ntow][0]--;
        }
        ntow = !ntow;
    }
    if (turn > 12345) return 1;
    printf("%d\n", turn);
    for (int i = 0; i < turn; i++) {
        printf("%d %d\n", move[i][0], move[i][1]);
    }
    return 0;
}