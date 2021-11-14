#include <stdio.h>

/*
문제 : N(N <= 10^6) 크기의 수열에 수들이 해당 수 횟수만큼 인접해서 있다고 한다. 
인접한 것을 제외하고 원래 수열의 수들을 출력한다.

해결 방법 : 각 수열을 확인하면서 출력할 차례가 오면 출력한다. 출력할 차례는 첫 번째 부터 그 번째에 있는
수를 더해나가는 방법으로 구할 수 있다.

주요 알고리즘 : 구현

출처 : KAIST 2021F F번
*/

int a[1048576];

int main(void) {
    int n, nxt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i == nxt) {
            nxt += a[i];
            printf("%d ", a[i]);
        }
    }
    return 0;
}