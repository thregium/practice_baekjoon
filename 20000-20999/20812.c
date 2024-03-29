#include <stdio.h>

/*
문제 : K(K <= 10)개의 티백이 있고, 각 주전자에는 티백 중 하나를 우릴 수 있다. 주전자는 10인용이다.
각 티백은 b_i(<= 100)명 분을 우릴 수 있다. 각 주전자에는 여러 티백을 우릴 수는 없고,
한 티백을 여러 주전자에 우릴 수는 있다. 이때, N(N <= 100)명의 사람에게 차를 주기 위해
필요한 주전자의 최소 개수를 구한다. 단, N은 b_i의 합 이하다.

해결 방법 : 우선 10인분씩으로 각 티백에 대해 최대한 우린다. 중간에 N명 치가 된다면
그때까지 우린 횟수를 출력하면 된다. 되지 않는다면 남은 분량이 많은 티백부터 차례로 우려나간다.
N명 치가 될 때의 횟수를 출력한다. 모든 b_i의 합이 N 이하므로 반드시 모두에게 차를 줄 수 있다.

주요 알고리즘 : 그리디 알고리즘, 수학

출처 : SwOI 2020Q 2번
*/

int b[16];

int main(void) {
    int k, n, r = 0;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < k; i++) {
        while (n > 0 && b[i] >= 10) {
            b[i] -= 10;
            n -= 10;
            r++;
        }
    }
    for (int i = 9; i >= 1; i--) {
        for (int j = 0; j < k && n > 0; j++) {
            if (b[j] == i) {
                b[j] = 0;
                n -= i;
                r++;
            }
        }
    }
    if (n > 0) return 1;
    printf("%d", r);
    return 0;
}