#include <stdio.h>

/*
문제 : 좌표평면을 특정한 패턴으로 걸어갈 때, 특정한 좌표에 이동한 적이 있는지 확인하고 있다면 몇 번째로 이동했는지 구한다.
좌표의 범위는 0 이상 5000 이하의 정수이다.

해결 방법 : 패턴을 분석해 경우를 나누어 해결한다.

주요 알고리즘 : 수학, 케이스 워크

출처 : Tehran 2000 A번
*/

int main(void) {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x == y) {
            if (x & 1) printf("%d\n", x * 2 - 1);
            else printf("%d\n", x * 2);
        }
        else if (x == y + 2) {
            if (x & 1) printf("%d\n", x + y - 1);
            else printf("%d\n", x + y);
        }
        else printf("No Number\n");
    }
    return 0;
}