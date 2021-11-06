#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 점들이 주어질 때, 이 점들로 만들 수 있는 볼록 껍질을 이루는 꼭짓점의 개수를 출력한다.
단, 직선상의 점은 제외한다.

해결 방법 : 볼록 껍질을 구현한다.

주요 알고리즘 : 기하학, 볼록 껍질
*/

long long points[103000][2];
int stack[103000];
int top = 2;
long long sx = 0, sy = 0;

int ccw(int a, int b, int c) {
    long long r = points[a][0] * points[b][1] + points[b][0] * points[c][1] + points[c][0] * points[a][1];
    r -= points[a][1] * points[b][0] + points[b][1] * points[c][0] + points[c][1] * points[a][0];
    return r > 0 ? 1 : r == 0 ? 0 : -1;
}

long long dist(int a, int b) {
    return (points[a][0] - points[b][0]) * (points[a][0] - points[b][0]) + (points[a][1] - points[b][1]) * (points[a][1] - points[b][1]);
}

int cmp1(const void* a, const void* b) {
    //각 점들을 각도 순으로 정렬
    long long ax = *(long long*)a;
    long long ay = *((long long*)a + 1);
    long long bx = *(long long*)b;
    long long by = *((long long*)b + 1);
    int ar, br;
    if (ax == sx) ar = 0;
    else if (ay > sy) ar = 1;
    else if (ay == sy) ar = 2;
    else ar = 3;
    if (bx == sx) br = 0;
    else if (by > sy) br = 1;
    else if (by == sy) br = 2;
    else br = 3;
    if (ar != br) return ar > br ? 1 : -1;
    if (ar == 0 && br == 0) return ay > by ? 1 : ay == by ? 0 : -1;
    if (ar == 2 && br == 2) return ax > bx ? 1 : ax == bx ? 0 : -1;

    long long res = (ax - sx) * (by - sy) - (ay - sy) * (bx - sx);
    return res > 0 ? 1 : res == 0 ? 0 : -1;
}

int main(void) {
    int n, c, sel = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &points[i][0], &points[i][1]);
        if (points[i][0] < points[sel][0] || (points[i][0] == points[sel][0] && points[i][1] < points[sel][1])) {
            sel = i;
        }
    }
    sx = points[sel][0];
    sy = points[sel][1];
    qsort(points, n, sizeof(long long) * 2, cmp1);

    stack[1] = 1;
    for (int i = 2; i <= n; i++) {
        //스택을 이용한 볼록 껍질 확인
        stack[top++] = (i == n ? 0 : i);
        c = ccw(stack[top - 3], stack[top - 2], stack[top - 1]);
        while (top > 2 && c >= 0) {
            if (c == 0 && dist(stack[top - 3], stack[top - 2]) > dist(stack[top - 3], stack[top - 1])) {
                top--;
                continue;
            }
            top -= 2;
            stack[top++] = (i == n ? 0 : i);
            if (top > 2) {
                c = ccw(stack[top - 3], stack[top - 2], stack[top - 1]);
            }
        }
    }
    top--;
    printf("%d", top);
    return 0;
}