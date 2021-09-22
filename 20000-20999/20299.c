#include <stdio.h>

/*
문제 : 3개의 자연수로 이루어진 쌍 N(N <= 500000)개가 주어질 때, 자연수의 합이 K(K <= 12000) 이상이며 가장 작은 자연수가
L(L <= 4000) 이상인 쌍의 개수를 구하고, 쌍을 이루는 모든 자연수들을 차례로 출력한다.

해결 방법 : 자연수들을 입력받으며 조건에 맞는 경우 해당하는 쌍을 저장하고 개수를 늘린다.
입력이 끝나면 해당하는 쌍들을 차례로 출력하면 된다.

주요 알고리즘 : 구현

출처 : 서강대 2020M A번
*/

int vip[524288][3];

int main(void) {
    int n, k, l, a, b, c, r = 0;
    scanf("%d %d %d", &n, &k, &l);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (a >= l && b >= l && c >= l && a + b + c >= k) {
            vip[r][0] = a;
            vip[r][1] = b;
            vip[r][2] = c;
            r++;
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%d %d %d ", vip[i][0], vip[i][1], vip[i][2]);
    }
    return 0;
}