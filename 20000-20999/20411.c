#include <stdio.h>

/*
문제 : 모듈로가 M(M <= 100000)이고 시드가 S인 선형 동차 생성기에서 첫 두 항 X, Y가 주어질 때,
두 계수 A와 C의 값을 구한다. 반드시 답이 있는 경우만 주어진다.

해결 방법 : A가 될 수 있는 모든 경우에 대해 S와 X에서의 C의 값과 X와 Y에서의 C의 값이 같을 때를 찾아
그 때의 A와 C를 출력한다.

주요 알고리즘 : 수학, 정수론, 브루트 포스

출처 : 아주대 2020D1 A2번 / 2020D2 A2번
*/

int main(void) {
    int m, s, x, y, c;
    scanf("%d %d %d %d", &m, &s, &x, &y);
    for (int a = 0; a < m; a++) {
        c = ((x - (long long)s * a) % m + m) % m;
        if (y == ((long long)x * a + c) % m) {
            printf("%d %d", a, c);
            return 0;
        }
    }
    return 1;
}