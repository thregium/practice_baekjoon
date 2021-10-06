#include <stdio.h>

/*
문제 : X와 Y가 주어질 때, X가 Y 이상이면 "MMM BRAINS"를 출력하고, 그 외에는 "NO BRAINS"를 출력한다. 이를 N회 반복한다.

해결 방법 : 문제에 주어진대로 구현한다.

주요 알고리즘 : 구현

출처 : SCNA 2004 8번
*/

int main(void) {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        if (x >= y) printf("MMM BRAINS\n");
        else printf("NO BRAINS\n");
    }
    return 0;
}