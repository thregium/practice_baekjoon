#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100000)개의 딸기가 일렬로 각 위치(<= 10^9, 자연수)에 있다.
각 딸기는 각 시각(<= 10^9, 자연수)에 완전히 익게 된다. 이때, 0에서 출발하여 단위 시간당 1씩 움직일 수 있다면
모든 딸기를 익은 후 수확하고 0으로 돌아오기 위해 필요한 최소 시간을 구한다.

해결 방법 : 우선 맨 오른쪽까지는 반드시 가야 한다. 그곳에서 왼쪽으로 순서대로 이동하며
딸기를 따는 것이 최적이다. 특정한 곳에 딸기가 열린다면 그 시각 이후에 그곳에 가야 하지만,
그 과정에서 굳이 돌아갈 이유가 없기 때문이다. 따라서 오른쪽부터 위치 순서대로 정렬한 다음,
추가로 가장 오래 기다려야 하는 딸기의 익는 시간 + 가장 오른쪽의 위치 * 2를 하면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : JOI 2020예2 2번
*/

int st[103000][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    long long r;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &st[i][0], &st[i][1]);
    }
    qsort(st, n, sizeof(int) * 2, cmp1);
    r = 0;
    for (int i = 0; i < n; i++) {
        if (st[i][1] - (st[0][0] * 2 - st[i][0]) > r) r = st[i][1] - (st[0][0] * 2 - st[i][0]);
    }
    printf("%lld\n", r + st[0][0] * 2);
    return 0;
}