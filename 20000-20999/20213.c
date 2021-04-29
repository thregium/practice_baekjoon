#include <stdio.h>

/*
문제 : 상대가 최적의 방법으로 모든 카드들을 뒤집어서 짝을 맞추려고 할 때,
뒤집는 카드들의 순서를 조작할 수 있다면 어떻게 해야 항상 최악의 경우((N * 2 - 1) * 2회 뒤집기)를 만들 수 있는지를 프로그래밍한다.

해결 방법 : 첫 번째로 뒤집는 수인 경우, 이미 모든 수를 보여준 경우가 아닌 이상, 지금까지 보여주지 않은 수를 보여주어야 한다.
이미 모든 수를 보여줬다면 1번만 보여줬던 수 가운데 하나를 보여준다. 물론 이미 뒤집은 카드가 나온 경우에는 그 카드에 있던 수를 보여줘야 한다.
두 번째로 뒤집는 수에는 한 번만 보여준 수가 있다면, 그 수를 보여주고, 아닌 경우에는 새로운 수를 보여주면 된다.
역시 이때도 이미 뒤집은 카드가 나온 경우에는 그 카드에 있던 수를 보여줘야 한다.

주요 알고리즘 : 그리디 알고리즘, 구현

출처 : BAPC 2020P A번
*/

int cards[20480], cc[10240];

int main(void) {
    int n, x, y, cnt = 1, toshow = 1;
    scanf("%d", &n);
    for (int i = 0; i < n * 2 - 1; i++) {
        scanf("%d", &x);
        if (cards[x]) printf("%d\n", cards[x]);
        else {
            if (cnt > n) {
                cards[x] = toshow++;
                printf("%d\n", cards[x]);
            }
            else {
                cards[x] = cnt++;
                printf("%d\n", cards[x]);
            }
            cc[cards[x]]++;
        }
        fflush(stdout);
        scanf("%d", &y);
        if (cards[y]) printf("%d\n", cards[y]);
        else {
            if (toshow + 1 >= cnt && cnt <= n) {
                cards[y] = cnt++;
                printf("%d\n", cards[y]);
            }
            else {
                cards[y] = toshow++;
                printf("%d\n", cards[y]);
            }
            cc[cards[y]]++;
        }
        fflush(stdout);
        //while (cards[x] > n || cards[x] < 0) n = n;
        //while (cards[y] > n || cards[y] < 0) n = n;
        //while (cc[cards[x]] > 2 || cc[cards[y]] > 2) n = n;
    }
    return 0;
}