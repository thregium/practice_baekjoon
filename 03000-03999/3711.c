#include <stdio.h>

/*
문제 : G(G <= 300)개의 10^6 이하인 음이 아닌 정수가 주어진다. 이때, M으로 모든 수를 나눈 나머지가 전부 다른 자연수
M 가운데 가장 작은 값을 구한다.

해결 방법 : G가 작기 때문에 1부터 올라가며 그러한 수를 찾더라도 작은 값에서 답이 나오게 된다.

주요 알고리즘 : 브루트 포스, 정수론

출처 : NWERC 2005 F번
*/

int nb[512], md[1048576];

int main(void) {
    int n, g, r;
    //freopen("E:\\PS\\ICPC\\Europe\\NWERC\\2005\\reducedidnumbers.in", "r", stdin);
    scanf("%d", &n);
    for (int nn = 0; nn < n; nn++) {
        scanf("%d", &g);
        for (int i = 0; i < g; i++) {
            scanf("%d", &nb[i]);
        }
        for (int i = 1;; i++) {
            r = 1;
            for (int j = 0; j < g; j++) {
                if (md[nb[j] % i]) {
                    r = 0;
                    break;
                }
                else md[nb[j] % i] = 1;
            }
            for (int j = 0; j < i; j++) md[j] = 0;
            if (r) {
                printf("%d\n", i);
                break;
            }
        }
    }
    return 0;
}