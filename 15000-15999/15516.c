#include <stdio.h>

/*
문제 : 길이 N(N <= 1000)의 배열이 주어질 때, 이 배열에서 각 값마다 더 작은 앞쪽 값의 개수를 출력한다.

해결 방법 : 직접 개수를 세보면 된다.

주요 알고리즘 : 구현

출처 : Startlink #1 E1번
*/

int a[1024];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        r = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}