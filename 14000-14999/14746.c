#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : 직선 Y = c1(|c1, c2| <= 10^9)상에 N(N, M <= 500000)개의 점으로 이루어진 집합 P와
Y = c2상에 M개의 점으로 이루어진 집합 Q가 주어진다. P와 Q의 점 사이 맨해튼 거리가 가장 작은 쌍의
맨해튼 거리와 그러한 쌍의 개수를 구한다. P와 Q의 모든 점은 서로 다른 위치에 있다.

해결 방법 : P와 Q의 모든 점이 서로 다른 위치에 있기 때문에, 같은 위치에 있는 점은 최대 2개이다.
따라서, 모든 점들을 X좌표 순서대로 정렬한 다음, 인접한 점의 쌍 가운데 서로 다른 집합에 있는
점들에 대해서만 차이를 보면서 답을 찾아나가면 된다.

주요 알고리즘 : 애드 혹?, 정렬

출처 : Daejeon 2017I A번
*/

int a[1048576][2];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    if (ai != bi) return ai > bi ? 1 : -1;
    ai = *((int*)a + 1);
    bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, c1, c2, lw = INF, lwc = 0;
    scanf("%d %d%d %d", &n, &m, &c1, &c2);
    for (int i = 0; i < n + m; i++) {
        scanf("%d", &a[i][0]);
        if (i >= n) a[i][1] = 1;
    }
    qsort(a, n + m, sizeof(int) * 2, cmp1);
    for (int i = 1; i < n + m; i++) {
        if (a[i][1] == a[i - 1][1]) continue;
        if (a[i][0] - a[i - 1][0] < lw) {
            lw = a[i][0] - a[i - 1][0];
            lwc = 1;
        }
        else if (a[i][0] - a[i - 1][0] == lw) lwc++;
    }
    printf("%d %d", lw + abs(c1 - c2), lwc);
    return 0;
}