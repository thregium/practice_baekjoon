#include <stdio.h>

/*
문제 : W * H(W, H <= 100000) 크기의 격자 형태로 된 도시가 있다. 이 도시에 N(N <= 100000)개의
wifi 중계기를 설치했을 때, 도시의 모든 점(외곽 포함)이 wifi 중계 범위에 들어가는 지 구한다.
wifi 중계기는 (x_i, y_i) 지점에 설치되며 koto 거리로 D(D <= 100000) 이내인 지점이 중계 범위이다.
koto 거리는 min(|x1 - x2|, |y1 - y2|)와 같다.

해결 방법 : 만약 한 지점이 중계 가능하다면 그와 같은 가로선 또는 세로선은 모두 중계 가능함을 알 수 있다.
따라서, 각 가로와 세로선마다 중계 가능한지 여부를 알 수 있다면 도시의 모든 지점에서 중계 가능한지
여부도 알 수 있다. 모든 가로 또는 세로선에서 중계 가능하다면 모든 지점에서 중계 가능한 것이다.
이는 각 중계 범위의 시작점과 끝점을 정해주고 누적 합을 하면 알 수 있다. 시작점과 끝점이 범위를 벗어나지
않도록 유의해야 하며, 격자점 사이가 음영지역일 수 있기 때문에 2를 곱해서
각 지점의 중계 범위 개수를 구해야 한다.

주요 알고리즘 : 누적 합

출처 : JAG 2013S2 A번
*/

int hor[204800], ver[204800];

int main(void) {
    int n, w, h, x, y, d, r = 1;
    scanf("%d %d %d", &n, &w, &h);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &d);
        hor[x * 2 - d * 2 < 0 ? 0 : x * 2 - d * 2]++;
        hor[x * 2 + d * 2 + 1 > w * 2 + 1 ? w * 2 + 1 : x * 2 + d * 2 + 1]--;
        ver[y * 2 - d * 2 < 0 ? 0 : y * 2 - d * 2]++;
        ver[y * 2 + d * 2 + 1 > h * 2 + 1 ? h * 2 + 1 : y * 2 + d * 2 + 1]--;
    }
    for (int i = 1; i <= w * 2 + 1; i++) {
        hor[i] += hor[i - 1];
        if (hor[i - 1] == 0) r = 0;
    }
    if (!r) {
        r = 1;
        for (int i = 1; i <= h * 2 + 1; i++) {
            ver[i] += ver[i - 1];
            if (ver[i - 1] == 0) r = 0;
        }
    }
    printf("%s\n", r ? "Yes" : "No");
    return 0;
}