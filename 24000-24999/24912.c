#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 카드가 일렬로 있다. 카드의 색은 3가지가 있고, 칠해진 카드와 칠해지지 않은 카드가 있다.
모든 카드를 양 옆의 색과 다르도록 칠하는 방법이 있는 지 구하고, 있다면 그러한 방법을 구한다.

해결 방법 : 양쪽의 카드가 어떻든 항상 1가지 이상의 배치가 가능하기 때문에 왼쪽에서부터
양쪽이 둘다 아닌 색으로 채워나가면 된다.
단, 연속으로 2개가 같은 색으로 칠해진 곳이 있다면 그렇게 칠하는 방법이 없다.

주요 알고리즘 : 애드 혹?, 구성적

출처 : 경곽 2022Q 1번
*/

int card[1048576];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &card[i]);
        if (i > 1 && card[i] == card[i - 1] && card[i] > 0) {
            printf("-1");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (card[i]) continue;
        if (card[i - 1] != 1 && card[i + 1] != 1) card[i] = 1;
        else if (card[i - 1] != 2 && card[i + 1] != 2) card[i] = 2;
        else if (card[i - 1] != 3 && card[i + 1] != 3) card[i] = 3;
        else return 1;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", card[i]);
    }
    return 0;
}