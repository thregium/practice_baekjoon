#include <stdio.h>

/*
문제 : 트리의 노드마다 부모 노드가 주어질 때, 각 노드의 깊이를 출력한다.

해결 방법 : 모든 노드에 대해 노드의 부모가 없거나 정해진 경우 그 값에 1을 더하고,
정해지지 않은 경우 넘어가는 방식으로 깊이를 저장하고 출력하면 된다.

주요 알고리즘 : 그래프 이론, 트리

출처 : AIPO 2016P 4번
*/

int p[32], l[32];

void up(int x) {
    if (p[x] < 0) l[x] = 1; //루트 노드인 경우
    else if (l[p[x]]) l[x] = l[p[x]] + 1; //부모 노드의 깊이가 정해진 경우
    else {
        up(p[x]); //부모 노드로 올라감
        l[x] = l[p[x]] + 1; //부모 노드 + 1
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++) up(i);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", l[i] - 1);
    }
    return 0;
}