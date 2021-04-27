#include <stdio.h>

/*
문제 : H개의 핫도그와 B(H, B <= 100)개의 햄버거가 있고, 각각의 무게가 주어질 때 두 음식의 무게를 정확히 같게 하기 위해 필요한 최소한의 음식 수를 구한다.

해결 방법 : 냅색 문제와 비슷한 방식으로 풀 수 있다. 단, 이때는 물건이 들어가는지 여부와 함께 해당 무게에 필요한 최소 물건의 개수를 같이 저장해야 한다.

주요 알고리즘 : 다이나믹 프로그래밍, 냅색

출처 : NAQ 2016 H번
*/

int hi[128], bi[128], mem1[128][103000], mem2[128][103000];

int main(void) {
    int h, b, s, r = 666;
    scanf("%d", &h);
    for (int i = 1; i <= h; i++) {
        scanf("%d", &hi[i]);
    }
    scanf("%d", &b);
    for (int i = 1; i <= b; i++) {
        scanf("%d", &bi[i]);
    }
    mem1[0][0] = 1;
    mem2[0][0] = 1;
    s = 0;
    for (int i = 1; i <= h; i++) {
        s += hi[i];
        for (int j = 0; j <= s; j++) {
            if (mem1[i - 1][j]) mem1[i][j] = mem1[i - 1][j];
            if (j >= hi[i] && mem1[i - 1][j - hi[i]]) {
                if (mem1[i][j] && mem1[i][j] <= mem1[i - 1][j - hi[i]] + 1) continue;
                else mem1[i][j] = mem1[i - 1][j - hi[i]] + 1;
            }
        }
    }
    s = 0;
    for (int i = 1; i <= b; i++) {
        s += bi[i];
        for (int j = 0; j <= s; j++) {
            if (mem2[i - 1][j]) mem2[i][j] = mem2[i - 1][j];
            if (j >= bi[i] && mem2[i - 1][j - bi[i]]) {
                if (mem2[i][j] && mem2[i][j] <= mem2[i - 1][j - bi[i]] + 1) continue;
                else mem2[i][j] = mem2[i - 1][j - bi[i]] + 1;
            }
        }
    }

    for (int i = 1; i <= 100000; i++) {
        if (mem1[h][i] && mem2[b][i]) {
            if (mem1[h][i] + mem2[b][i] < r) r = mem1[h][i] + mem2[b][i];
        }
    }
    if (r == 666) printf("impossible");
    else printf("%d", r - 2);
    return 0;
}