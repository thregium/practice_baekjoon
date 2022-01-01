#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 10^6)개의 자연수로 이루어진 수열에서 연속된 1개 이상의 부분 문자열 가운데 가장 평균이 작은 것의 평균을 구한다.

해결 방법 : 최솟값보다 평균이 작아질 수는 없으므로 답은 최솟값과 같다.

주요 알고리즘 : 그리디 알고리즘, 수학

출처 : ILOCAMP 2011B 4-1번
*/

int main(void) {
    int n, a, best = INF;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a < best) best = a;
    }
    printf("%d.00", best);
    return 0;
}
