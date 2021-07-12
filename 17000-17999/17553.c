#include <stdio.h>
#include <stdlib.h>
#define CON 186947453825714673 //충분히 큰 자연수 중 아무거나 하나 잡기

/*
문제 : N(N <= 10000)개의 점이 주어질 때, 이 점들과 서로 다른 두 점을 잡아서 어느 한 쪽에 더 가까운 점들을
정확히 반씩으로 나누는 점의 위치를 구한다. 단, N이 홀수인 경우 한 개의 점은 양쪽에서 정확히 같은 거리만큼 떨어져야 한다.
각 점의 좌표는 절댓값이 10^9 이하의 정수이고, 출력할 좌표는 절댓값이 10^18 이하의 정수여야 한다.

해결 방법 : X좌표 -> Y좌표 순으로 정렬한 다음 정확히 가운데 순서(짝수인 경우 가운데 2개 중 뒤쪽 위치)에 있는 것을 뽑는다.
홀수인 경우 이를 통과하며 \방향에서 최대한 세로쪽으로 붙은 형태가 되면 정확히 절반으로 나눌 수 있다. 이를 좌표로 표현하면
해당 점의 좌표를 (x, y), C는 매우 큰 정수(10^9를 넘는)라 했을 때 (x - C, y - 1)과 (x + C, y + 1)이 되면 된다.
짝수인 경우에는 해당 위치에서 매우 약간만 아래로 내려가야 하는데, (x - C, y - 1)과 (x + C, y)로 맞춰두면 된다.

주요 알고리즘 : 기하학, 정렬

출처 : BAPC 2019P L번
*/

int points[103000][2];

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int bx = *(int*)b;
    if (ax != bx) return ax > bx ? 1 : -1;
    int ay = *((int*)a + 1);
    int by = *((int*)b + 1);
    return ay > by ? 1 : ay == by ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }
    qsort(points, n, sizeof(int) * 2, cmp1);
    if (n & 1) {
        printf("%lld %lld\n", points[n >> 1][0] - CON, points[n >> 1][1] - 1LL);
        printf("%lld %lld", points[n >> 1][0] + CON, points[n >> 1][1] + 1LL);
    }
    else {
        printf("%lld %lld\n", points[n >> 1][0] - CON, points[n >> 1][1] - 1LL);
        printf("%lld %lld", points[n >> 1][0] + CON, (long long)points[n >> 1][1]);
    }
    return 0;
}