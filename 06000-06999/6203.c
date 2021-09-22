#include <stdio.h>
#include <stdlib.h>

/*
문제 : 좌표평면상에 N(N <= 1000)개의 점이 있다. 각 점들에 번호를 매기고 1번부터 차례로 가장 가까이 있는 점을 제거한다.
제거한 점은 넘어가고 제거하지 않은 다음 점에서 가장 가까이 있는 점을 제거하는 것을 반복한다. 마지막 점 다음에는
다시 1번 점으로 돌아와서 이를 반복한다. 이때, 마지막으로 남는 점을 구한다.

해결 방법 : 각 점들 사이의 거리를 미리 구해둔 다음, 각 점들에서 가까운 순으로 점들의 번호를 정렬해둔다.
그 뒤로는 점들을 살펴보면서 가장 가까운 점을 구하고 지우는 것을 반복하면 된다.

주요 알고리즘 : 구현, 시뮬레이션, 기하학, 정렬

출처 : USACO 2006N B3번 // CERC 2002 E번
*/

int pos[1024][2], dists[1024][1024], order[1024][1024], checked[1024], elim[1024];
int search = 0; //정렬을 위한 전역 변수

int sqr(int x) {
    return x * x;
}

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return dists[search][ai] > dists[search][bi] ? 1 : dists[search][ai] == dists[search][bi] ? 0 : -1;
}

int main(void) {
    int n, turn = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dists[i][j] = sqr(pos[i][0] - pos[j][0]) + sqr(pos[i][1] - pos[j][1]); //거리 구하기
            order[i][j - 1] = j; //모든 번호를 미리 적어둔다.
        }
    }
    for (int i = 1; i <= n; i++) {
        search = i;
        qsort(order + i, n, sizeof(int), cmp1); //정렬한다.
    }
    for (int i = 1; i < n; i++) {
        for (int j = checked[turn] + 1; j <= n; j++) {
            //마지막으로 확인한 번호 다음부터 확인한다.
            checked[turn] = j;
            if (j >= n) return 1; //오류 검출용
            if (!elim[order[turn][j]]) {
                elim[order[turn][j]] = 1; //삭제할 점이 나온 경우
                break;
            }
        }
        turn = turn % n + 1;
        while (elim[turn]) turn = turn % n + 1; //다음 점을 찾는다.
    }
    printf("%d", turn);
    return 0;
}