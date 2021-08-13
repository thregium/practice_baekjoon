#include <stdio.h>

/*
문제 : 너비 W(W <= 100)인 칸에서 칸막이 P(P < W)개의 위치가 주어지고, 각 칸막이를 세우거나 세우지 않을 수 있을 때,
칸을 분할하는 너비의 모든 경우를 구한다.

해결 방법 : 가능한 너비는 전부 W 이하다. W가 매우 작으므로 모든 너비의 후보에 대해 가능한지 확인해보면 된다.
모든 칸막이의 쌍에 대해 너비를 확인해보면 된다. 이때 0과 W도 확인해야 함에 주의한다.
너비를 확인한 다음에는 1부터 W까지의 너비 가운데 나온 너비들만 출력해주면 된다.

주요 알고리즘 : 브루트 포스

출처 : NAQ 2014 C번 / 2020 D번
*/

int parts[128], valids[128];

int main(void) {
    int w, p;
    scanf("%d %d", &w, &p);
    for (int i = 1; i <= p; i++) {
        scanf("%d", &parts[i]);
    }
    parts[p + 1] = w;
    for (int i = 0; i <= p + 1; i++) {
        for (int j = i + 1; j <= p + 1; j++) {
            valids[parts[j] - parts[i]]++;
        }
    }
    for (int i = 1; i <= w; i++) {
        if (valids[i]) printf("%d ", i);
    }
    return 0;
}