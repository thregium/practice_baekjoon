#include <stdio.h>
#define INF 1234567890987654321

/*
문제 : C(C <= 100000)명의 사람에게 H(H <= 100000)개의 일을 맡겨야 한다. 각 사람의 불만도는
a_i(1 <= a_i <= 10^9)이고, 일을 시킬 때 마다 늘어나는 불만도는 d_i(1 <= d_i <= 10^9)일 때,
H개의 일을 시킨 후 불만도가 가장 높은 사람의 불만도를 최소화할 때의 불만도를 구한다.

해결 방법 : 불만도의 최댓값이 증가할 때 마다 시킬 수 있는 일의 수는 단조 증가하므로
매개 변수 탐색이 가능하다. 불만도의 최댓값을 변수로 잡은 다음, 해당 불만도에서 시킬 수 있는
일의 개수가 H개 이상인 최소 불만도를 찾으면 된다. 해당 불만도에서 시킬 수 있는 일의 개수는
(불만도 - a_i) / d_i를 하되, 불만도가 a_i 이상인 경우에서만 해당된다.
또한, 최솟값은 a_i의 최솟값으로 해야 최소 불만도인 경우 판정이 잘못 되지 않는다.

주요 알고리즘 : 파라메트릭

출처 : VTH 2019 H번
*/

int co[103000][2];

int helps(long long h, int c, long long lv) {
    for (int i = 0; i < c; i++) {
        if (lv > co[i][0]) h -= (lv - co[i][0]) / co[i][1];
        if (h <= 0) return 1;
    }
    return 0;
}

int main(void) {
    int h, c;
    long long lo = 0, hi = INF, mid;
    scanf("%d %d", &h, &c);
    for (int i = 0; i < c; i++) {
        scanf("%d %d", &co[i][0], &co[i][1]);
        if (co[i][0] > lo) lo = co[i][0];
    }
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (helps(h, c, mid)) hi = mid;
        else lo = mid + 1;
    }
    printf("%lld", lo);
    return 0;
}