#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
문제 : N(N <= 5000)개의 서로 다른 음이 아닌 정수(<= 328 * 10^5)가 주어질 때, 서로 다른 정수 쌍 가운데
가장 차이가 작은 정수 쌍의 차이와, 그러한 정수 쌍의 개수를 구한다.

해결 방법 : 모든 정수 쌍을 살펴보며 절댓값을 확인한다. 최솟값보다 작다면 최솟값을 갱신하고 개수를 1로 초기화한다.
최솟값과 같다면 개수를 1 늘린다. 이를 반복한 후 최솟값과 개수를 출력하면 된다.

주요 알고리즘 : 브루트 포스

출처 : 중앙대 2017R
*/

int a[5120];

int main(void) {
    int n, r = INF, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(a[i] - a[j]) < r) {
                r = abs(a[i] - a[j]);
                cnt = 1;
            }
            else if (abs(a[i] - a[j]) == r) cnt++;
        }
    }
    printf("%d %d", r, cnt);
    return 0;
}