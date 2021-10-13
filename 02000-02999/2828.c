#include <stdio.h>

/*
문제 : N(N <= 10)칸으로 이루어진 게임 화면에서 처음에 M(M < N)칸 길이의 바구니가 화면 가장 왼쪽에 있다.
하늘에서 J(J <= 20)개의 과일이 주어진 게임 화면의 위치로 떨어진다. 이때 모든 과일을 받기 위해
움직여야 하는 거리의 최솟값을 구한다.

해결 방법 : 현재 바구니 위치의 오른쪽에 과일이 떨어진다면 바구니로 그 과일을 받을 수 있는 위치까지 움직인다.
단, 왼쪽에서 다시 과일이 떨어질 수 있으므로 더 많이 움직여서는 안 된다. 왼쪽에서 떨어지는 경우 역시 마찬가지로
움직이면 J번의 과일을 받는 동안 움직인 거리의 최솟값이 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : COCI 11/12#1 1번
*/

int main(void) {
    int n, m, j, x, pl, pr, r = 0; //X : 과일이 떨어진 위치, PL : 바구니의 왼쪽 위치, PR : 바구니의 오른쪽 위치, R : 결괏값
    scanf("%d %d", &n, &m);
    pl = 1;
    pr = m;
    scanf("%d", &j);
    for (int i = 0; i < j; i++) {
        scanf("%d", &x);
        if (x < pl) {
            r += pl - x;
            pr -= pl - x;
            pl = x;
        }
        else if (x > pr) {
            r += x - pr;
            pl += x - pr;
            pr = x;
        }
    }
    printf("%d", r);
    return 0;
}