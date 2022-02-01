#include <stdio.h>
#include <stdlib.h>

/*
문제 : R * S(R, S <= 500)크기의 좌석 배치가 양쪽에 있다. 그 사이에는 너비 1의 통로가 있고,
통로의 뒤쪽 끝에는 출구가 있다. 각 좌석에서 전후좌우로 1칸 이동하는 데 1씩 시간이 들고,
다른 사람이 있을 칸으로는 이동할 수 없다면, 모든 사람이 출구로 가는 데 걸리는 최소 시간을 구한다.

해결 방법 : 각 사람이 출구에서의 거리가 서로 다르다면 서로 다른 통로의 위치에 서 있을 것이므로
각자 독립적으로 나갈 수 있다. 거리가 같다면 그 중 1명만 통로로 나갈 수 있고, 다른 사람들은 기다려야 하므로
기다리는 사람은 시간이 1씩 지체된다. 이를 출구에서 가까운 사람부터 차례로 확인하며 각 사람이 출구로
이동하는 데 걸리는 시간을 찾으면 된다. 밀려나는 효과는 연쇄적일 수 있음에 유의한다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : Yokohama 2018 C번
*/

int d[524288];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int r, s, p, x, y;
    scanf("%d %d %d", &r, &s, &p);
    for (int i = 0; i < p; i++) {
        scanf("%d %d", &x, &y);
        d[i] = r - x + 1;
        if (y <= s) d[i] += s - y + 1;
        else d[i] += y - s;
    }
    qsort(d, p, sizeof(int), cmp1);
    for (int i = 1; i < p; i++) {
        if (d[i - 1] + 1 > d[i]) d[i] = d[i - 1] + 1;
    }
    printf("%d\n", d[p - 1]);
    return 0;
}