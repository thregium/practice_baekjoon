#include <stdio.h>
#include <stdlib.h>

/*
문제 : 최소 스패닝 트리의 비용을 구한다.

해결 방법 : 크루스칼 알고리즘을 통해 구현한다.

주요 알고리즘 : MST
*/

int edges[103000][3], connect[10240];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int n) {
    if (!connect[n]) return n;
    while (connect[n]) n = connect[n];
    return n;
}

int uni(int a, int b) {
    connect[b] = a;
}

int main(void) {
    int v, e, a, b, c, cost = 0;
    scanf("%d %d", &v, &e);
    for (int i = 1; i <= e; i++) {
        scanf("%d %d %d", &edges[i][1], &edges[i][2], &edges[i][0]);
    }
    qsort(edges + 1, e, sizeof(int) * 3, cmp1); //모든 간선을 비용 오름차순으로 정렬한다.
    for (int i = 1; i <= e && v > 1; i++) {
		//모든 집합이 연결될 때 까지 반복한다.
        a = find(edges[i][1]); //각 집합이 어디에 속하는지 확인한다.
        b = find(edges[i][2]);
        if (a != b) {
            cost += edges[i][0];
            uni(a, b); //두 집합을 하나로 묶는다.
            v--;
        }
    }
    printf("%d", cost);
    return 0;
}