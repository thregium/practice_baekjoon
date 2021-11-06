#include <stdio.h>
#include <stdlib.h>

/*
문제 : 넓은 정수 직사각형의 높이 H와 너비 W(0 < H < W <= 100)가 주어질 때, 해당 크기의 직사각형보다 큰 정수 직사각형 가운데
가장 작은 정수 직사각형의 크기를 구한다. 크기는 대각선을 우선으로 하며, 대각선의 길이가 같다면 높이가 큰 것이 더 크다.
답의 높이와 너비는 150 이내의 범위에 있다.

해결 방법 : 우선 150 * 150 범위 내의 모든 넓은 정수 직사각형을 배열에 담은 다음, 크기 순서대로 정렬한다.
정렬한 다음에는 이분 탐색을 통해 배열에서 해당 직사각형의 위치를 찾고 다음 직사각형을 출력하면 된다.

주요 알고리즘 : 수학, 정렬, 이분 탐색

출처 : JDC 2013 A번
*/

int rect[16384][2];

int cmp1(const void* a, const void* b) {
    int ah = *(int*)a;
    int bh = *(int*)b;
    int aw = *((int*)a + 1);
    int bw = *((int*)b + 1);
    if (ah * ah + aw * aw != bh * bh + bw * bw) return (ah * ah + aw * aw) - (bh * bh + bw * bw);
    return ah > bh ? 1 : ah == bh ? 0 : -1;
}

int main(void) {
    int p = 0, rt[2];
    int* r;
    for (int i = 1; i < 150; i++) {
        for (int j = i + 1; j < 150; j++) {
            rect[p][0] = i;
            rect[p++][1] = j;
        }
    }
    qsort(rect, p, sizeof(int) * 2, cmp1);
    while (1) {
        scanf("%d %d", &rt[0], &rt[1]);
        if (!rt[0]) break;
        r = bsearch(rt, rect, p, sizeof(int) * 2, cmp1);
        printf("%d %d\n", *(r + 2), *(r + 3));
    }
    return 0;
}