#include <stdio.h>

/*
문제 : 세 주사위의 면의 개수 S1, S2, S3(S1, S2 <= 20)(S3 <= 40)이 주어질 때, 가장 많이 나오는 눈의 수의 합을 구한다.

해결 방법 : 모든 경우의 수를 확인하더라도 시간 내에 풀 수 있으므로 전부 확인해본 다음 가장 많은 것을 고르면 된다.

주요 알고리즘 : 브루트 포스

출처 : USACO 2008X G1번
*/

int sums[128];

int main(void) {
    int s1, s2, s3, best = 0;
    scanf("%d %d %d", &s1, &s2, &s3);
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                sums[i + j + k]++;
            }
        }
    }
    for (int i = 1; i <= s1 + s2 + s3; i++) {
        if (sums[i] > sums[best]) best = i;
    }
    printf("%d", best);
    return 0;
}