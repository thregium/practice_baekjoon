#include <stdio.h>

/*
문제 : 배열이 주어질 때, 두 값의 차 중 가장 큰 것을 출력한다. 단, 반드시 뒤쪽 수가 앞쪽 수보다 커야 한다.

해결 방법 : 배열을 돌며 현재까지의 최솟값을 저장한 다음, 현재 값과 최솟값의 차이가 가장 큰 것을 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : AIPO 2016P 5번
*/

int a[10240];

int main(void) {
    int n, l = 1234567, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] < l) l = a[i];
        else if (r < a[i] - l) r = a[i] - l;
    }
    printf("%d", r);
    return 0;
}