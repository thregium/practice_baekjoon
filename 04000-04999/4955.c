#include <stdio.h>

/*
문제 : N(N <= 200)개의 정사각형을 0번부터 차례로 이미 놓인 정사각형에 인접하게 붙여나갔다.
정사각형을 붙여나갈 때 마다 붙인 상대와 방향이 주어지면 전체 형태를 둘러싸는 직사각형의 크기를 구한다.

해결 방법 : 각 정사각형의 X와 Y좌표를 저장한 다음(0번 정사각형은 (0, 0)), 붙여나갈 때 마다
X와 Y좌표의 최대, 최솟값을 갱신해 나간다. 전부 붙인 후 최댓값 - 최솟값 + 1이 각 좌표의 범위와 같고,
이는 곧 높이와 너비가 된다.

주요 알고리즘 : 구현

출처 : JDC 2010 A번
*/

int point[256][2];
int dxy[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

int main(void) {
    int n, ni, d, xl, yl, xh, yh;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Domestic\\2010\\qualify_judge\\A1", "r", stdin);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        xl = 0, yl = 0, xh = 0, yh = 0;
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &ni, &d);
            if (ni >= i) return 1;
            point[i][0] = point[ni][0] + dxy[d][0];
            point[i][1] = point[ni][1] + dxy[d][1];
            if (point[i][0] < xl) xl = point[i][0];
            if (point[i][0] > xh) xh = point[i][0];
            if (point[i][1] < yl) yl = point[i][1];
            if (point[i][1] > yh) yh = point[i][1];
        }
        printf("%d %d\n", yh - yl + 1, xh - xl + 1);
    }
    return 0;
}