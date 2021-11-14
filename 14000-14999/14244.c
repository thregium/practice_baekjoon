#include <stdio.h>

/*
문제 : N(N <= 50)개의 정점으로 이루어진 트리 가운데 리프 노드가 M(2 <= M <= N - 1)개인 트리를 구한다.

해결 방법 : 리프 노드가 되지 않는 노드들(처음, 끝 제외)을 일자로 연결하고, 나머지는 그 중간에 연결해주면 된다.

주요 알고리즘 : 구성적, 트리
*/

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; i++) {
        if (i <= n - m + 1) printf("%d %d\n", i - 1, i);
        else printf("1 %d\n", i);
    }
    return 0;
}