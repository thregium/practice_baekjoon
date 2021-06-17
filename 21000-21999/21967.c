#include <stdio.h>

/*
문제 : N(N <= 10^6)개의 수로 이루어진 수열에서 최댓값과 최솟값의 크기 차이가 최대 2인 가장 긴 연속하는 부분 수열의 길이를 구한다.
단, 수열의 값은 1 이상 10 이하의 자연수이다.

해결 방법 : 수열 값의 범위가 작으므로 1-3부터 8-10까지의 각 범위에 대해 조건에 맞는 가장 긴 연속하는 부분 수열의 길이를 찾고
그 중 가장 큰 값을 구하면 된다.

주요 알고리즘 : 브루트 포스

출처 : 선린 5회예 D번
*/

int a[1048576];

int main(void) {
    int n, cnt, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= 8; i++) {
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] >= i && a[j] <= i + 2) cnt++;
            else {
                if (cnt > r) r = cnt;
                cnt = 0;
            }
        }
        if (cnt > r) r = cnt;
    }
    printf("%d", r);
    return 0;
}