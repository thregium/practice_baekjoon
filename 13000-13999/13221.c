#include <stdio.h>
#include <math.h>

/*
문제 : 첫 좌표가 주어지고 이후 다른 좌표들이 주어질 때,
처음 주어진 좌표와 맨해튼 거리가 가장 가까운 점을 찾는다.

해결 방법 : 첫 점의 좌표를 저장하고, 이후로는 주어진 점과 첫 점의 좌표의 절댓값 합을 더한 값이
지금까지 거리의 최솟값보다 작은지 확인한 후, 작다면 해당 값을 결과 좌표로 저장한다.
끝나면 저장한 결과 좌표를 출력한다.

주요 알고리즘 : 수학

출처 : AIPO 2015p 1번
*/

int main(void) {
    int x, y, n, a, b, d = 1234567890, r[2] = { 0, };
    scanf("%d %d%d", &x, &y, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        if (abs(x - a) + abs(y - b) < d) {
            d = abs(x - a) + abs(y - b);
            r[0] = a;
            r[1] = b;
        }
    }
    printf("%d %d", r[0], r[1]);
    return 0;
}