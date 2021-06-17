#include <stdio.h>
#include <stdlib.h>

/*
문제 : 수직선 위에 N(N <= 10000)개의 책장이 있다. 책들은 0의 위치에 있고, 한 번에 M(M <= N)개의 책들을 옮길 수 있다면
최단거리로 이동했을 때의 모든 책들을 각 책장에 꽂기 위한 이동 거리를 구한다.
단, 각 책장들은 0에 있지 않고 마지막 책을 꽂은 다음 0으로 돌아올 필요는 없다.

해결 방법 : 수직선을 원점에 대해 양수와 음수로 나눈 다음, 양수와 음수 각각에 대해 가장 먼 책장부터 책을 채워가기 시작한다.
이 방법을 통해 책을 채웠을 때의 이동 거리에서 양쪽 끝의 책장 중 절대값이 더 큰 책장 좌표의 절대값만큼을 빼면 답을 구할 수 있다.

주요 알고리즘 : 그리디 알고리즘, 정렬
*/

int a[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, r = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n && a[i] < 0; i += m) {
        r += -a[i] * 2;
    }
    for (int i = n - 1; i >= 0 && a[i] > 0; i -= m) {
        r += a[i] * 2;
    }
    if (-a[0] < a[n - 1]) r -= a[n - 1];
    else r += a[0];
    printf("%d", r);
    return 0;
}