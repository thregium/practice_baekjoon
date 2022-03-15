#include <stdio.h>

/*
문제 : 길이 N(N <= 1000)의 숫자로 이루어진 배열이 주어질 때, 부분 문자열 "2020"이 몇 회 등장하는 지 구한다.

해결 방법 : 배열 전체를 확인하며 그러한 경우를 직접 찾으면 된다.

주요 알고리즘 : 구현, 문자열

출처 : JDC 2020 A번
*/

int a[1024];

int main(void) {
    int n, r = 0;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        r = 0;
        for (int i = 0; i < n - 3; i++) {
            if (a[i] == 2 && a[i + 1] == 0 && a[i + 2] == 2 && a[i + 3] == 0) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}