#include <stdio.h>

/*
문제 : N * M(N, M <= 10^6) 크기의 지도에서 T(T <= 100)개의 보석의 위치가 주어진다. 이때, K * K(K <= 10^6) 크기의 정사각형 안에
가장 많은 보석이 있도록 하면 그 정사각형의 위치와 안에 존재하는 보석의 수를 출력한다.
단, 정사각형은 지도를 벗어날 수 없다.

해결 방법 : 지도에서 각 보석의 X, Y좌표를 전부 기록해둔다. 그 다음, 지도에서 벗어나지 않는다면 각 보석의 X, Y 좌표에 해당하는
모든 지점들을 정사각형의 각 꼭지점에 대응시켜 놓고 정사각형 안에 들어가는 보석의 수를 계산한다.
이 수가 최고값보다 크다면 값을 갱신하고 그때의 좌표를 저장하면 된다.
그런데, 이 과정에서 모든 꼭지점이 좌표를 벗어날 수도 있기 때문에 0과 N, M도 각 X, Y 좌표에 포함해서 계산해야 한다. 

주요 알고리즘 : 브루트 포스

출처 : 정올 2009지 초3번
*/

int pos[128][2], xl[128], yl[128], bp[2];

int main(void) {
    int n, m, t, k, best = 0, cnt;
    scanf("%d %d %d %d", &n, &m, &t, &k);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
        xl[i] = pos[i][0];
        yl[i] = pos[i][1];
    }
    pos[t][0] = 0;
    pos[t][1] = 0;
    pos[t + 1][0] = n;
    pos[t + 1][1] = m;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (xl[i] + k <= n && yl[j] + k <= m) {
                cnt = 0;
                for (int c = 0; c < t; c++) {
                    if (pos[c][0] >= xl[i] && pos[c][0] <= xl[i] + k && pos[c][1] >= yl[j] && pos[c][1] <= yl[j] + k) cnt++;
                }
                if (cnt > best) {
                    bp[0] = xl[i];
                    bp[1] = yl[j] + k;
                    best = cnt;
                }
            }

            if (xl[i] >= k && yl[j] + k <= m) {
                cnt = 0;
                for (int c = 0; c < t; c++) {
                    if (pos[c][0] >= xl[i] - k && pos[c][0] <= xl[i] && pos[c][1] >= yl[j] && pos[c][1] <= yl[j] + k) cnt++;
                }
                if (cnt > best) {
                    bp[0] = xl[i] - k;
                    bp[1] = yl[j] + k;
                    best = cnt;
                }
            }

            if (xl[i] + k <= n && yl[j] >= k) {
                cnt = 0;
                for (int c = 0; c < t; c++) {
                    if (pos[c][0] >= xl[i] && pos[c][0] <= xl[i] + k && pos[c][1] >= yl[j] - k && pos[c][1] <= yl[j]) cnt++;
                }
                if (cnt > best) {
                    bp[0] = xl[i];
                    bp[1] = yl[j];
                    best = cnt;
                }
            }

            if (xl[i] >= k && yl[j] >= k) {
                cnt = 0;
                for (int c = 0; c < t; c++) {
                    if (pos[c][0] >= xl[i] - k && pos[c][0] <= xl[i] && pos[c][1] >= yl[j] - k && pos[c][1] <= yl[j]) cnt++;
                }
                if (cnt > best) {
                    bp[0] = xl[i] - k;
                    bp[1] = yl[j];
                    best = cnt;
                }
            }

        }
    }
    printf("%d %d\n%d", bp[0], bp[1], best);
    return 0;
}