#include <stdio.h>

/*
문제 : 23으로 이루어진 수의 합 가운데 K(K <= 23232323)번째로 작은 수를 구한다.

해결 방법 : 23으로 이루어진 수는 모두 23의 배수이다. 따라서, 조건을 만족하는 K번째 수는 23의 K번째 배수이고,
이는 곧 23 * K와 같다.

주요 알고리즘 : 수학

출처 : 선린 가을E A번 / 가을B A번
*/

int main(void) {
    int t, k;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &k);
        printf("%d\n", k * 23);
    }
    return 0;
}