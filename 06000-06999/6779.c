#include <stdio.h>

/*
문제 : 풍선의 높이 H(H <= 100)과 최대 시간 M(M <= 100)이 주어질 때, 풍선을 띄운 후 땅에 떨어질 때 까지 걸리는 시간을 구한다.
그 시간은 -6t^4 + ht^3 + 2t^2 + t라는 식으로 구할 수 있다. M 내에 답이 나오지 않는다면 나오지 않는다고 출력한다.

해결 방법 : 문제에 주어진 식을 t의 값을 1부터 M까지 올려가며 계산한다. 만약 값이 0 이하가 되는 점이 나온다면
그 때의 값을 출력한다. M까지 나오지 않았다면 나오지 않는 것이다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : CCC 2011J 2번
*/

int main(void) {
    int h, m;
    scanf("%d%d", &h, &m);
    for (int i = 1; i <= m; i++) {
        if (-6 * i * i * i * i + h * i * i * i + 2 * i * i + i <= 0) {
            printf("The balloon first touches ground at hour: %d", i);
            return 0;
        }
    }
    printf("The balloon does not touch ground in the given time.");
    return 0;
}