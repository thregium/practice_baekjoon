#include <stdio.h>

/*
문제 : N(N <= 1000)개의 팀들 가운데 총점이 가장 높은 팀의 점수를 구한다. 총점은 팀원 3명의 점수 합이고,
각 팀원의 점수는 기술 3개의 횟수가 주어질 때, 각 기술의 배점 * 사용 횟수의 합이다.

해결 방법 : 각 팀의 점수를 계산해 나가면서 최댓값을 갱신한다.

주요 알고리즘 : 구현, 사칙연산

출처 : 항공대 1회 A번
*/

int main(void) {
    int n, a, b, c, x, y, z, t, best = -1;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        t = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%d %d %d", &x, &y, &z);
            t += a * x + b * y + c * z;
        }
        if (t > best) best = t;
    }
    printf("%d", best);
    return 0;
}