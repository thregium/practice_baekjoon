#include <stdio.h>

/*
문제 : X + Y^2 + Z^3 = E(E <= 10^6, 음이 아닌 정수)를 만족하는 가장 작은 X + Y + Z의 값을 찾는다.
X, Y, Z는 모두 음이 아닌 정수여야 한다.

해결 방법 : Z부터 역순으로 탐색한다. Z, Y의 값을 0부터 늘려가되 중간에 합이 E를 넘어가면 바로 탐색을 종료한다.
매 탐색때마다 X(= E - Z^3 - Y^3) + Y + Z의 최솟값을 갱신해 나가며 가장 작은 값을 구하면 된다.

주요 알고리즘 : 수학, 브루트 포스

출처 : JDC 2007 A번
*/

int main(void) {
    int e, m;
    while (1) {
        scanf("%d", &e);
        if (e == 0) break;
        m = 1234567;
        for (int z = 0; z * z * z <= e; z++) {
            for (int y = 0; z * z * z + y * y <= e; y++) {
                if (z + y + (e - z * z * z - y * y) < m) m = z + y + (e - z * z * z - y * y);
            }
        }
        printf("%d\n", m);
    }
    return 0;
}