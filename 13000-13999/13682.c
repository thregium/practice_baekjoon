#include <stdio.h>

/*
문제 : 길이 N(N <= 10000)의 수열이 있다. 이 수열을 원형으로 이어붙일 때 극댓값과 극솟값의 개수 합을 구한다.
단, 인접한 두 수는 서로 같지 않다.

해결 방법 : 인접한 두 수가 같지 않으므로 어떠한 수가 양 옆 수보다 크거나 작다면 극댓값이나 극솟값이다.
따라서, 모든 지점에 대해 양 옆 수와 비교해본 다음 위 조건에 맞다면 결괏값에 1씩 추가해주면 된다. 이때, 양 끝 점이라면
양 옆 수 중 하나는 반대쪽 끝임에 유의한다. 전부 확인한 뒤에는 결괏값을 출력하면 된다.

주요 알고리즘 : 구현, 브루트 포스

출처 : Brasil 2008 F번
*/

int a[10240];

int main(void) {
    int n, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        r = 0;
        for (int i = 1; i < n - 1; i++) {
            if (a[i] < a[i - 1] && a[i] < a[i + 1]) r++;
            else if (a[i] > a[i - 1] && a[i] > a[i + 1]) r++;
        }
        if (a[0] < a[n - 1] && a[0] < a[1]) r++;
        else if (a[0] > a[n - 1] && a[0] > a[1]) r++;
        if (a[n - 1] < a[n - 2] && a[n - 1] < a[0]) r++;
        else if (a[n - 1] > a[n - 2] && a[n - 1] > a[0]) r++;
        printf("%d\n", r);
    }
    return 0;
}