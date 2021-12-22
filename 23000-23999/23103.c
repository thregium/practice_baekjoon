#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 정수 점(|| <= 100)이 주어진다. 각 점들을 차례로 이동할 때, 걸리는 맨해튼 거리의 합을 구한다.

해결 방법 : 마지막 점을 저장해가며 마지막 점과의 차이를 계산해 맨해튼 거리를 더해나가면 된다.

주요 알고리즘 : 기하학, 수학

출처 : Petro 2021S1 A번
*/

int main(void) {
    int n, x, y, lx, ly, r = 0;
    scanf("%d%d %d", &n, &lx, &ly);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        r += abs(lx - x) + abs(ly - y);
        lx = x;
        ly = y;
    }
    printf("%d", r);
    return 0;
}