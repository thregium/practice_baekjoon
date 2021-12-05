#include <stdio.h>

/*
문제 : N(N <= 200000)개의 정점으로 이루어진 이진 트리가 있다. 루트(1번 정점)에서 구슬을 떨어뜨리면
리프 노드까지 내려가 쌓이게 된다. 자식 노드가 1개인 경우 그 자식 노드로 내려가고, 2개인 경우 구슬이 적은 쪽,
같다면 왼쪽 노드로 내려가게 된다. 이때, K(K <= 10^18)개의 구슬을 떨어뜨렸을 때, 마지막 구슬이 떨어지는 정점을 구한다.

해결 방법 : 매 자식 노드가 2개인 정점마다 홀수 번째 도착하는 경우 왼쪽,
짝수 번째 도착하는 경우 오른쪽으로 떨어지는 것을 알 수 있다.
이를 다르게 표현하면, K에서 1을 뺐을 때, 각 비트를 뒤에서부터 보며 비트가 1일 때만 오른쪽으로 내려가면 된다.
이때, 이것이 적용되는 것은 자식 노드가 2개인 정점인 경우 뿐이다. 그러한 정점을 만났을 때,
밑에서부터 x(지금까지 만난 자식 노드가 2개인 정점 수)번째 비트가 1이면 오른쪽, 0이면 왼쪽으로 이동한다.
이를 반복하여 도착하는 노드를 찾으면 된다.

주요 알고리즘 : 수학, 비트마스킹, 트리

출처 : 연세대 2017 C번
*/

int child[204800][2];

int main(void) {
    int n, duals = 0, node = 1;
    long long k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &child[i][0], &child[i][1]);
    }
    scanf("%lld", &k);
    k--;
    while (1) {
        if (child[node][0] < 0 && child[node][1] < 0) break;
        else if (child[node][0] < 0) {
            node = child[node][1];
            continue;
        }
        else if (child[node][1] < 0) {
            node = child[node][0];
            continue;
        }

        if (duals > 64) node = child[node][0];
        else if ((k >> duals) & 1) node = child[node][1];
        else node = child[node][0];
        duals++;
    }
    printf("%d", node);
    return 0;
}