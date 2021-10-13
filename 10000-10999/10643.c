#include <stdio.h>

/*
문제 : 8조각 피자의 각 조각에 있는 버섯의 개수(<= 50)가 주어질 때, 피자를 반으로 나누어 가장 많은 버섯이 있도록 하는 경우의
버섯 수를 구한다. 단, 피자는 조각 단위로만 자를 수 있다.

해결 방법 : 

주요 알고리즘 : 브루트 포스

출처 : COCI 14/15#5 1번
*/

int mush[8];

int main(void) {
    int best = -1, sum;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &mush[i]);
    }
    for (int i = 0; i < 8; i++) {
        sum = 0;
        for (int j = 0; j < 4; j++) {
            sum += mush[(i + j) & 7];
        }
        if (sum > best) best = sum;
    }
    if (best < 0) return 1;
    printf("%d", best);
    return 0;
}