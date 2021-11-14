#include <stdio.h>

/*
문제 : 20장의 카드 가운데 두 장을 뽑았다. 다른 사람이 나머지 카드 중 카드를 뽑는다면 문제에서 주어진 패가
이길 확률을 구한다. 이기는 방법은 카드 서열이 더 높으면 이긴 것으로 생각한다.

해결 방법 : 먼저 뽑은 카드를 제외한 나머지 카드들 중 2개를 뽑는 방법을 확인한다. 그 경우 각각에 대해서
원래 뽑은 카드가 이기는 경우의 수를 구하고, 전체 경우의 수를 구한 다음, 둘을 나누면 된다.

주요 알고리즘 : 브루트 포스

출처 : 충남대 1회 B번
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int comp(int a, int b, int c, int d) {
    //두 패를 비교한다. 앞쪽 패의 서열이 더 높으면 양수, 낮으면 음수를 반환한다.
    if (a > 10) a -= 10;
    if (b > 10) b -= 10;
    if (c > 10) c -= 10;
    if (d > 10) d -= 10;
    if (a > b) swap(&a, &b);
    if (c > d) swap(&c, &d);
    if (a == b) {
        if (c == d) {
            if (a > c) return 1;
            else if (a < c) return -1;
            else return 0;
        }
        else return 1;
    }
    else if (c == d) return -1;
    else {
        if ((a + b) % 10 > (c + d) % 10) return 1;
        else if ((a + b) % 10 < (c + d) % 10) return -1;
        else return 0;
    }
}

int main(void) {
    int a, b, w = 0, al = 0;
    scanf("%d %d", &a, &b);
    if (b == a) b += 10;
    for (int i = 1; i <= 20; i++) {
        if (i == a || i == b) continue;
        for (int j = 1; j <= 20; j++) {
            if (j == i || j == a || j == b) continue;
            al++;
            if (comp(a, b, i, j) > 0) w++;
        }
    }
    printf("%.3f", (double)w / al + 0.000001);
    return 0;
}