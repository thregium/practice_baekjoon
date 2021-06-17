#include <stdio.h>

/*
문제 : N(N <= 100000)개의 중복되지 않는 점들이 주어질 때, 이 점들을 통해 만들 수 있는 좌표평면과 평행한
직각삼각형의 수를 구한다.

해결 방법 : 먼저, 해당 X좌표와 Y좌표를 갖는 지점의 수를 세 준다. 그 다음으로, 모든 지점에 대해 해당 지점과 같은
X좌표를 갖는 지점과 Y좌표를 갖는 지점의 수를 각각 곱하면 해당 점을 직각으로 하는 직각삼각형의 수가 되므로 이 값들을 전부 더하면 된다.

주요 알고리즘 : 기하학, 조합론

출처 : COCI 07/08#3 4번
*/

int points[103000][2], xposes[103000], yposes[103000];

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
        xposes[points[i][0]]++;
        yposes[points[i][1]]++;
    }
    for (int i = 0; i < n; i++) {
        r += ((long long)xposes[points[i][0]] - 1) * ((long long)yposes[points[i][1]] - 1);
    }
    printf("%lld", r);
    return 0;
}