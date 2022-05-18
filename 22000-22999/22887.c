#include <stdio.h>

/*
문제 : N(N <= 100)개의 자연수로 이루어진 순열 가운데 reversesort시 비용(구간 크기의 합)이
정확히 C(C <= 1000)인 것이 있는 지 찾고 있다면 그러한 것을 출력한다.

해결 방법 : 비용의 최댓값은 sum(2, ... N)이고, 최솟값은 N - 1이다. 그 범위 안에 없다면 그러한 순열이 없다.
그 범위 안에 있다면 정렬된 상태에서 뒤집는 연산을 반복하여 그러한 순열을 찾을 수 있다.
최댓값에서 C를 뺀 후 그 횟수만큼은 넘기고 그 횟수일 때의 위치까지 뒤집은 다음,
그 이후로 각 시작점부터 끝까지 뒤집는 것을 반복하면 된다.

주요 알고리즘 : 애드 혹?, 구성적, 정렬

출처 : GCJ 2021Q C번
*/

int a[128];

void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void rev(int* a, int s, int e) {
    for (int i = s, j = e; i < j; i++, j--) {
        swap(&a[i], &a[j]);
    }
}

int main(void) {
    int t, n, c, mx;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &c);
        mx = 0;
        for (int i = 2; i <= n; i++) mx += i;
        if (c < n - 1 || c > mx) {
            printf("Case #%d: IMPOSSIBLE\n", tt);
            continue;
        }
        c = mx - c;
        for (int i = 1; i <= n; i++) a[i] = i;
        for (int i = n - 1; i > 0; i--) {
            for (int j = n; j > i; j--) {
                if (c == 0) {
                    rev(a, i, j);
                    break;
                }
                else c--;
            }
        }
        printf("Case #%d: ", tt);
        for (int i = 1; i <= n; i++) {
            printf("%d%c", a[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}