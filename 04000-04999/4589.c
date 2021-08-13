#include <stdio.h>

/*
문제 : 3개의 서로 다른 100 이하의 자연수가 주어질 때, 이 세 수가 정렬된 상태인지 아닌지 구한다.

해결 방법 : 세 수를 차례로 a, b, c라고 하면 a > b이고 b > c(내림차순)이거나 a < b이고 b < c(오름차순)이면 정렬된 것이고
둘 다 아니라면 정렬되지 않은 것이다.

주요 알고리즘 : 구현

출처 : MidC 2009 B번
*/

int main(void) {
    int n, a, b, c;
    scanf("%d", &n);
    printf("Gnomes:\n");
    for (int tt = 0; tt < n; tt++) {
        scanf("%d %d %d", &a, &b, &c);
        if ((a > b && b > c) || (a < b && b < c)) printf("Ordered\n");
        else printf("Unordered\n");
    }
    return 0;
}