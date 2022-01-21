#include <stdio.h>

/*
문제 : N(N <= 100)개의 데이터가 있고, 각 데이터는 100 이하의 음이 아닌 정수이다.
각 데이터를 W(10 <= W <= 50) 단위로 나누고 등장 횟수를 히스토그램으로 만들었다.
이때, 이 히스토그램을 만드는데 드는 잉크의 양을 구한다. 히스토그램은 가장 높은 막대를 기준으로 높이를 정하며,
그 막대의 높이는 일정하게 맞추어진다. 각 막대의 색은 높이가 있는 가장 오른쪽 막대를 흰색,
가장 왼쪽(높이가 0인 경우 포함) 막대를 검은색으로 하여 사이의 막대들은 그 중간 색을 등차로 이룬다.
중간에 높이가 0인 막대가 있더라도 넘어가지 않는다. 가장 높은 높이의 막대를 전부 검은색으로 칠하면 1만큼의 잉크가 들며,
색이 흐려질수록 드는 잉크의 양이 적어진다. 칠하는 것 외에는 잉크를 0.01만큼 사용한다.
항상 막대가 2개 이상인 경우만 주어진다.

해결 방법 : 먼저 W 단위의 막대 높이들을 구하는 동시에 막대의 개수를 구한다. 그 다음에는 가장 높은 막대의 높이를 확인하고,
막대의 개수와 가장 높은 막대의 높이를 바탕으로 각 막대의 잉크 사용량을 전부 더하면 된다.
높이에 의한 사용량은 높이 / 최대 높이이고, 색에 의한 사용량은 (오른쪽에서 본 현재 막대의 번째) / (막대의 개수 - 1)이다.
이 두 값을 곱하면 각 막대의 사용량이 되고, 이를 전부 더한 다음 0.01을 더하면 답이 된다.

주요 알고리즘 : 구현, 수학

출처 : Aizu 2008 A번
*/

int cnt[16];

int main(void) {
    int n, w, x, best, hcnt, hbest;
    double r;
    while (1) {
        scanf("%d %d", &n, &w);
        if (w == 0) break;
        best = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            cnt[x / w]++;
            if (x > best) best = x;
        }
        hcnt = best / w + 1;
        if (hcnt <= 1) return 1;
        hbest = 0;
        for (int i = 0; i < hcnt; i++) {
            if (cnt[i] > hbest) hbest = cnt[i];
        }

        r = 0.01;
        for (int i = 0; i < hcnt; i++) {
            r += (double)cnt[i] / hbest * ((double)hcnt - i - 1) / (hcnt - 1);
        }
        printf("%f\n", r);

        for (int i = 0; i < hcnt; i++) cnt[i] = 0;
    }
    return 0;
}