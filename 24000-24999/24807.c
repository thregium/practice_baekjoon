#include <stdio.h>

/*
문제 : 세 동물의 다리 수 A, B, C(1 <= A, B, C <= 100)가 주어질 때, 전체 다리 수 합이 L(L <= 250)개가
되는 구성을 전부 출력한다. 순서는 앞쪽 동물의 수가 증가하는 순으로 한다.

해결 방법 : 각 동물의 수를 늘려가면서 답이 L인 경우를 모두 출력한다. L을 넘어가면 반복을 멈추고
밖으로 나온다.

주요 알고리즘 : 수학, 브루트 포스

출처 : VTH 2018 C번
*/

int main(void) {
    int a, b, c, l, r = 0;
    scanf("%d %d %d %d", &a, &b, &c, &l);
    for (int i = 0; i * a <= l; i++) {
        for (int j = 0; i * a + j * b <= l; j++) {
            for (int k = 0; i * a + j * b + k * c <= l; k++) {
                if (i * a + j * b + k * c == l) {
                    printf("%d %d %d\n", i, j, k);
                    r++;
                }
            }
        }
    }
    if (r == 0) printf("impossible");
    return 0;
}
