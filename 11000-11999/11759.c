#include <stdio.h>

/*
문제 : v1 * a + v2 * b = s(0 < v1, v2, s <= 10^6, v1, v2, s는 자연수, v1 > v2)가 되는 음이 아닌 정수
a와 b의 쌍이 있는지 확인하고, 있다면 그러한 쌍 가운데 b가 가장 작은 것을 구한다.

해결 방법 : a의 값을 s / v1에서 시작해서 0까지 내려가며 하나씩 확인해본다. 만약 s - (i * v1)이 v2로 나누어 떨어진다면
b가 있는 것이므로 (s - (i * v1)) / v2의 값을 b로 두고 a와 b를 출력하면 된다.
그러한 값이 a = 0까지 나오지 않는다면 그러한 쌍이 없는 것이므로 Impossible을 출력하면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : ECRC 2015 PA번
*/

int main(void) {
    int s, v1, v2;
    scanf("%d %d %d", &s, &v1, &v2);
    for (int i = s / v1; i >= 0; i--) {
        if ((s - (i * v1)) % v2 == 0) {
            printf("%d %d", i, (s - (i * v1)) / v2);
            return 0;
        }
    }
    printf("Impossible");
    return 0;
}