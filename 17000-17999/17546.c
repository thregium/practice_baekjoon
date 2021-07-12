#include <stdio.h>

/*
문제 : 정점 N(N <= 100000)개, 간선 M(M <= 200000)개인 유향 그래프에서 간선 R(R <= M / 2)개를 지워 사이클이 없도록 만든다.
단, 자기 자신과 연결되는 간선은 없고 출발 정점과 도착 정점이 서로 같은 간선도 없다.

해결 방법 : 자기 자신과 연결되는 간선이 없기 때문에 모든 간선은 번호가 증가하는 방향 또는 번호가 감소하는 방향으로만 되어있다.
그런데, 번호가 증가하는 방향으로만 연결된 그래프나 감소하는 방향으로만 연결된 그래프는 반드시 사이클이 없을 수 밖에 없다.
또한, 번호가 증가하는 방향 또는 번호가 감소하는 방향 둘 중 하나는 전체의 과반일 것이므로 둘 중 간선이 적은 쪽을 지우면 된다.

주요 알고리즘 : 그래프 이론, 애드 혹

출처 : BAPC 2019P E번
*/

int inc[204800], dec[204800];
int incc = 0, decc = 0;

int main(void) {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        if (a > b) dec[decc++] = i;
        else inc[incc++] = i;
    }
    if (incc < decc) {
        printf("%d\n", incc);
        for (int i = 0; i < incc; i++) {
            printf("%d\n", inc[i]);
        }
    }
    else {
        printf("%d\n", decc);
        for (int i = 0; i < decc; i++) {
            printf("%d\n", dec[i]);
        }
    }
    return 0;
}