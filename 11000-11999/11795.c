#include <stdio.h>

/*
문제 : A, B, C 세 개의 물품이 매일 들어온다. 모든 물품이 30개 이상 남는 날에는 남은 물품을 최대한 많이, 모든 물품을 같은 양만큼
보낸다고 하면, 각 날마다 보내는 물품의 양을 각각 구한다. 보내지 않는 날은 NO라고 출력한다.

해결 방법 : 매일 재고의 양을 확인하고 물품이 들어온 다음 셋 중 최솟값을 확인해서 가장 작은 값이 30 미만인 경우 NO를 출력한 다음
다음 날로 넘어가고, 30 이상이면 최솟값만큼을 출력하고 각각 재고에서 빼내면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : Phuket 2015 L번
*/

int small3(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int main(void) {
    int t, a = 0, b = 0, c = 0, xa, xb, xc, dtb;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d %d", &xa, &xb, &xc);
        a += xa, b += xb, c += xc;
        dtb = small3(a, b, c);
        if (dtb < 30) {
            printf("NO\n");
            continue;
        }
        printf("%d\n", dtb);
        a -= dtb, b -= dtb, c -= dtb;
    }
    return 0;
}