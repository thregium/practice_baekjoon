#include <stdio.h>

/*
문제 : M * N(M, N <= 10^9) 크기의 체스판에서 특정한 위치의 칸의 색이 주어질 때, 흰색과 검은색 중 어느 쪽이 더 많은지 구한다.

해결 방법 : 전체 칸 수가 짝수개인 경우 당연히 두 색의 수는 같을 것이다.
홀수개인 경우에는 꼭짓점과 같은 칸(좌표의 합이 짝수인 칸)이라면 그 칸과 같은 색이 더 많고, 아니라면 그 칸과 다른 색이 더 많다.

주요 알고리즘 : 수학, 케이스 워크

출처 : ROI 2011R 5번
*/

int main(void) {
    int m, n, x, y, c;
    scanf("%d %d %d %d %d", &m, &n, &x, &y, &c);
    if ((m & 1) && (n & 1)) {
        if ((x + y) & 1) {
            if (c) printf("black");
            else printf("white");
        }
        else {
            if (c) printf("white");
            else printf("black");
        }
    }
    else printf("equal");
    return 0;
}