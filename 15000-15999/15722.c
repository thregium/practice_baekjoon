#include <stdio.h>

/*
문제 : 원점에서 출발해서 북쪽으로 이동하는 것으로 출발해 시계방향으로 달팽이 모양으로 움직일 때,
N(N <= 1000)번 움직였을 때의 위치를 구한다.

해결 방법 : N이 크지 않기 때문에 직접 움직여본다. 방향은 X축 방향과 Y축 방향의 변화량을 미리 배열에 넣어두고,
길이는 반복문을 통해 늘려간다. 같은 길이로 2번 움직인 다음 길이가 1씩 늘어나고, 움직일 때 마다 방향을 90도씩
바꾼다는 점을 활용해 코드를 짤 수 있다. N번 움직이면 그때까지 움직임을 마치고 그 때의 좌표를 출력하면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 중앙대 2018R 4번
*/

int dxy[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int main(void) {
    int n, d = 0, x = 0, y = 0;
    scanf("%d", &n);
    for (int i = 0, l = 1; i < n; l++) {
        for (int ii = 0; ii < 2; ii++) {
            for (int j = 0; j < l && i < n; j++) {
                x += dxy[d][0];
                y += dxy[d][1];
                i++;
            }
            d = ((d + 1) & 3);
        }
    }
    printf("%d %d", x, y);
    return 0;
}