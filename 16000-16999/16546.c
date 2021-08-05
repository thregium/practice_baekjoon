#include <stdio.h>

/*
문제 : 1부터 N(N <= 32768)까지의 수 가운데 나오지 않은 수가 하나 있을 때, 그 수가 무엇인지 구한다.

해결 방법 : 배열에 각 수들의 등장 여부를 저장한 후, 값이 0인 값을 찾으면 된다.

주요 알고리즘 : 구현

출처 : Waterloo 20180930 A번
*/

int a[65536];

int main(void) {
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        a[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            printf("%d", i);
        }
    }
    return 0;
}