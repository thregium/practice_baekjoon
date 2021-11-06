#include <stdio.h>

/*
문제 : N(N <= 100)개의 맛살에 대한 가격(<= 100000)과 중량(<= 5000)이 주어질 때, 가격 대비 중량 비가 가장 높은 것의
가격을 출력한다. 그러한 것이 여러 개인 경우 가격이 가장 낮은 것을 고른다.

해결 방법 : 최적의 물건의 가격을 BC, 중량을 BW로 두고 그 값을 갱신해 나간다. 가격을 C, 중량을 W라 한다면
W / C가 BW / BC보다 클 때 값을 갱신하면 된다. 실수오차를 줄이기 위해 여기서 C와 BC를 이항하면 W * BC가 BW * C보다 클 때가 된다.
또는 W * BC = BW * C이면서 C가 BC보다 작은 경우도 갱신해야 하는 경우이다.
위 조건일 때 마다 값을 갱신하고 난 후의 BC를 출력하면 된다.

주요 알고리즘 : 수학

출처 : Seoul 2005I A번
*/

int main(void) {
    int t, n, w, c, bw, bc;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        bw = 0, bc = 103000;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &w, &c);
            if (w * bc > c * bw || (w * bc == c * bw && c < bc)) {
                bc = c;
                bw = w;
            }
        }
        printf("%d\n", bc);
    }
    return 0;
}