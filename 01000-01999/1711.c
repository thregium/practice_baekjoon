#include <stdio.h>

/*
문제 : N(N <= 1500)개의 서로 다른 점(|| <= 10^9, 정수)이 좌표평면상에 주어질 때, 해당 점들을 이어 만들 수 있는 직각삼각형의 개수를 구한다.
(제한시간 5초)

해결 방법 : 가능한 모든 직각삼각형의 개수를 구하면 nC3으로, 제한시간 5초를 생각하면 시간 내로 돌아갈 수 있다.
따라서, 모든 직각삼각형의 거리의 제곱을 구한 후, 어느 하나가 나머지의 합과 같은 경우를 모두 찾아내면 된다.

주요 알고리즘 : 브루트 포스, 기하학
*/

long long point[1536][2];

int main(void) {
    int n;
    long long r = 0, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &point[i][0], &point[i][1]);
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = i + 1; j < n; j++) {
            for (long long k = j + 1; k < n; k++) {
                a = (point[i][0] - point[j][0]) * (point[i][0] - point[j][0]) + (point[i][1] - point[j][1]) * (point[i][1] - point[j][1]);
                b = (point[j][0] - point[k][0]) * (point[j][0] - point[k][0]) + (point[j][1] - point[k][1]) * (point[j][1] - point[k][1]);
                c = (point[k][0] - point[i][0]) * (point[k][0] - point[i][0]) + (point[k][1] - point[i][1]) * (point[k][1] - point[i][1]);
                if (a == b + c || b == a + c || c == a + b) r++;
            }
        }
    }
    printf("%lld", r);
    return 0;
}