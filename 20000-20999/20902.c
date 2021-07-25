#include <stdio.h>
#include <stdlib.h>

/*
문제 : H * W(H, W <= 10000) 크기의 책장에 책을 N(N <= 10000)권 꽂으려고 한다. 각 책은 높이와 너비가 있으며,
책 위에 다른 책을 놓거나 책을 눕히는 것은 불가능하다. 여기서 책장 중간에 선반을 하나 더 만들 수 있다면
모든 책을 꽂을 수 있는 선반의 높이를 구한다. 불가능하다면 impossible을, 선반을 추가하지 않아도 된다면 -1을 출력한다.

해결 방법 : 책들을 높이 순으로 정렬한 다음, 냅색을 이용해 해당 책까지 보았을 때 가능한 모든 너비를 구한다.
먼저 선반을 추가하지 않아도 되는지 확인한다. 그러한 경우는 모든 책의 너비 합이 책장의 너비 이하이며
가장 높은 책이 책장의 높이 이하인 경우이다. 이에 해당하면 -1을 출력하고 프로그램을 종료한다.
아니라면 그 다음으로는 모든 가능한 선반의 높이에 대해 윗 칸에 들어갈 수 없는 높이의 모든 책 너비의 합을 구해준다.
이 값이 책장의 너비보다 크다면 다음 높이를 살펴본다. 이하인 경우에는 윗 칸에 들어갈 수 있는 모든 책을 살피며
남은 칸들을 최대한 채운다. 만약 채우고 남은 책들의 너비가 책장의 너비 이하인 경우에는 그 높이가
가능한 선반의 높이이므로 출력하고 프로그램을 종료하면 된다.
만약 모든 선반의 높이에 대해 불가능하다면 어떻게 하더라도 불가능한 것이므로 impossible을 출력한다.

주요 알고리즘 : DP, 정렬

출처 : GCPC 2020 B번
*/

int books[10240][2], widths[10240][2], heights[10240][2], mem[10240][10240];

int cmp1(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, x, y, tx;
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &books[i][0], &books[i][1]);
        widths[books[i][1]][0] += books[i][0];
        heights[books[i][1]][0]++;
    }
    for (int i = 10000; i > 0; i--) {
        widths[i][1] = widths[i + 1][1] + widths[i][0];
    }
    for (int i = 1; i <= 10000; i++) {
        heights[i][1] = heights[i - 1][1] + heights[i][0];
    }
    if (widths[1][1] <= x && widths[y + 1][1] == 0) {
        printf("-1");
        return 0;
    }
    qsort(books, n, sizeof(int) * 2, cmp1);
    mem[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (mem[i - 1][j]) mem[i][j] = 1;
            if (j >= books[i - 1][0]) mem[i][j] |= mem[i - 1][j - books[i - 1][0]];
        }
    }
    for (int i = 1; i < y; i++) {
        if (widths[y - i + 1][1] > x || widths[i + 1][1]) continue;
        tx = x - widths[y - i + 1][1];
        for (int j = tx; j >= 0; j--) {
            if (mem[heights[y - i][1]][j]) {
                tx -= j;
                break;
            }
        }
        if (widths[1][1] - (x - tx) <= x) {
            printf("%d", i);
            return 0;
        }
    }
    printf("impossible");
    return 0;
}