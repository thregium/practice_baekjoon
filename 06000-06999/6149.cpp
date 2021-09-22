#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std;

/*
문제 : K(K <= 100000)개의 카드가 있고, N(N <= 100)명에게 카드를 나누어 주려고 한다. 매번 나누어 준 다음, 위의 P(P <= 10)장을
밑으로 집어넣는다면, 마지막 사람이 받는 카드를 오름차순으로 출력한다.

해결 방법 : 큐를 이용하여 카드 더미를 구현한 다음, 차례로 카드를 나누어 주면 된다. 카드를 나누어 주는 것은 pop()연산,
위의 카드를 밑으로 집어넣는 것은 pop()과 push()연산으로 구현이 가능하다. 맨 처음에는 1부터 K까지 미리 큐에 집어넣어둔다.

주요 알고리즘 : 구현, 큐, 시뮬레이션

출처 : USACO 2007D B3번
*/

int bessie[103000];
queue<int> q;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k, p, bp = 0;
    scanf("%d %d %d", &n, &k, &p);
    for (int i = 1; i <= k; i++) q.push(i);
    while (q.size()) {
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                bessie[bp++] = q.front();
                q.pop();
            }
            else q.pop();

            if (q.empty()) break;
            for (int j = 0; j < p; j++) {
                q.push(q.front());
                q.pop();
            }
        }
    }
    qsort(bessie, bp, sizeof(int), cmp1);
    for (int i = 0; i < bp; i++) {
        printf("%d\n", bessie[i]);
    }
    return 0;
}