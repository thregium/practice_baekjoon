#include <stdio.h>

/*
문제 : 2명이 주사위 2개씩을 던졌을 때, 문제에 주어진 규칙대로면 누가 이기는 지 구한다.

해결 방법 : 각 경우에 따라 점수를 매기고 점수가 더 큰쪽을 찾으면 된다.

주요 알고리즘 : 구현

출처 : VTH 2014 A번
*/

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int score(int a, int b) {
    if (a == 2 && b == 1) return 103000;
    else if (a == b) return 100 + a;
    else return a * 10 + b;
}

int main(void) {
    int a, b, c, d;
    while (1) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a == 0) break;
        if (a < b) swap(&a, &b);
        if (c < d) swap(&c, &d);
        if (score(a, b) > score(c, d)) printf("Player 1 wins.\n");
        else if (score(a, b) < score(c, d)) printf("Player 2 wins.\n");
        else printf("Tie.\n");
    }
    return 0;
}