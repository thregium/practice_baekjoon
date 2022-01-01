#include <stdio.h>

/*
문제 : 성냥개비로 만들 수 있는 두 자리 수 + 두 자리 수 = 두 자리 수인 식 가운데
성냥개비를 정확히 N(1 <= N <= 50)개 쓰는 것을 구한다. 없다면 impossible을 출력한다.

해결 방법 : 모든 더하는 수에 대해 사용하는 성냥의 수를 구한 다음, N과 같다면 그 식을 출력하고 종료한다.
끝까지 그러한 경우가 없다면 impossible을 출력하면 된다.

주요 알고리즘 : 브루트 포스

출처 : 인천대 2021 B번
*/

int matc[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 100; i++) {
        for (int j = 0; i + j < 100; j++) {
            if (n == matc[i / 10] + matc[i % 10] + matc[j / 10] + matc[j % 10] + matc[(i + j) / 10] + matc[(i + j) % 10] + 4) {
                printf("%02d+%02d=%02d", i, j, i + j);
                return 0;
            }
        }
    }
    printf("impossible");
    return 0;
}