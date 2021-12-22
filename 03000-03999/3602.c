#include <stdio.h>

/*
문제 : 흰 색을 W, 검은 색을 B(W, B <= 10000)개 사용하여 만들 수 있는 가장 큰 체스판 정사각형의 한 변의 길이를 구한다.

해결 방법 : B와 W가 크지 않으므로 체스판의 크기를 1부터 점점 늘려가며 확인해본다. 매번 더 많은 쪽의 색은 ceil(N * N / 2),
적은 쪽은 floor(N * N / 2)개가 포함된다는 점을 이용한다.

주요 알고리즘 : 브루트 포스

출처 : NEERC 2007N I번
*/

int main(void) {
    int a, b, t, r = 0;
    scanf("%d %d", &a, &b);
    if (a < b) {
        t = a;
        a = b;
        b = t;
    }
    for (r = 1;; r++) {
        if ((r * r + 1) >> 1 > a || (r * r) >> 1 > b) break;
    }
    r--;
    if (r == 0) printf("Impossible");
    else printf("%d", r);
    return 0;
}