#include <stdio.h>

/*
문제 : 나무 N(N <= 1000)그루가 있다. 각 나무의 생장 기간(<= 10^6년, 이후로는 0이 될 때 까지 크기 감소),
생장량(<= 1000, 생장 기간동안 1년에 해당 량만큼 증가, 이후로는 해당 량만큼 감수),
초기 크기(<= 10^6), 심은 해(<= 10^6)가 주어질 때, 나무의 양이 가장 많은 해의 나무 수를 구한다.

해결 방법 : 그래프의 개형을 생각해보면 각 나무를 심을 때와 가장 크기가 커질 때만 고려해도 됨을 알 수 있다.
따라서, 각 경우에 대해 나무의 양을 구하고, 가장 많을 때의 양을 찾아 출력하면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : VTH 2019 J번
*/

int tre[1024][4];

int main(void) {
    int n;
    long long y, r = 0, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &tre[i][j]);
        }
    }
    for (int i = 0; i < n * 2; i++) {
        if (i & 1) y = tre[i >> 1][3] + tre[i >> 1][0];
        else y = tre[i >> 1][3];
        t = 0;
        for (int j = 0; j < n; j++) {
            if (y < tre[j][3]) continue;
            else if (y <= tre[j][3] + tre[j][0]) t += tre[j][2] + tre[j][1] * (y - tre[j][3]);
            else if (tre[j][2] + tre[j][1] * (tre[j][3] + tre[j][0] * 2 - y) > 0) {
                t += tre[j][2] + tre[j][1] * (tre[j][3] + tre[j][0] * 2 - y);
            }
        }
        if (t > r) r = t;
    }
    printf("%lld", r);
    return 0;
}