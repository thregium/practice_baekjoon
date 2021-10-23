#include <stdio.h>

/*
문제 : 두 점 P1, P2에서 각각 X, Y(P1, P2, X, Y <= 100)만큼의 단위로 + 방향으로 이동하였다. 이때, 두 점이 공통적으로 이동한 지점
가운데 가장 작은 점을 구한다. 없다면 -1을 출력한다.

해결 방법 : 모든 수가 100 이하의 자연수이기 때문에 답이 존재하는 경우 많아야 10000번 내로는 답을 구할 수 있다.
따라서, P1과 P2 가운데 뒤에 있는 것을 앞쪽으로 옮겨가며 같은 점을 찾다가 일정 횟수를 넘기면 -1을 출력한다.
같은 점을 찾은 경우에는 그 위치를 출력하면 된다.

주요 알고리즘 : 수학, 정수론, 브루트 포스
*/

int main(void) {
    int x, y, p1, p2;
    scanf("%d %d %d %d", &x, &y, &p1, &p2);
    for (int i = 0; i < 1000000; i++) {
        if (p1 < p2) p1 += x;
        else if (p2 < p1) p2 += y;
        else {
            printf("%d", p1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}