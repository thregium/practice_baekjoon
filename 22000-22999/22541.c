#include <stdio.h>

/*
문제 : 1000 이하의 자연수 N이 주어질 때, 2개 이상의 연속한 자연수를 더해서 N이 되는 조합의 개수를 구한다.

해결 방법 : 1부터 N - 1까지의 수에서 각각 시작해서 연속한 자연수를 더해나간다.
이를 각 더함마다 N 이상이 될 때 까지 반복하며 끝났을 때 N이 되는 경우의 개수를 세면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : JDC 2010 A번
*/

int main(void) {
    int n, s, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 0;
        for (int i = 1; i < n; i++) {
            s = 0;
            for (int j = i; s < n; j++) s += j;
            if (s == n) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}