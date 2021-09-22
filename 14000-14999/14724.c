#include <stdio.h>

/*
문제 : 주어진 9개의 길이 N(N <= 100)인 자연수 배열 중 최댓값이 가장 큰 배열을 찾는다.

해결 방법 : 수들을 입력받다 최댓값이 나오면 최댓값을 업데이트하며 배열의 위치를 함께 저장하고,
마지막으로 나온 배열의 위치를 출력하면 된다.

주요 알고리즘 : 구현

출처 : 충남대 1회 I번
*/

char* clubs[] = { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };

int main(void) {
    int n, x, best = 0, bn = -1;
    scanf("%d", &n);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            if (x > best) {
                best = x;
                bn = i;
            }
        }
    }
    if (bn < 0) return 1;
    printf("%s", clubs[bn]);
    return 0;
}