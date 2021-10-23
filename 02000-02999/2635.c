#include <stdio.h>

/*
문제 : N(N <= 30000)이 주어질 때, N을 첫 번째 수로 하는 수열 가운데 규칙을 따라 만들 수 있는 가장 긴 수열을 구한다.
규칙은 다음과 같다. N을 첫 수로 하고, 임의의 양의 정수를 두 번째 수로 한다. 그 뒤로는 음수가 나오기 전까지
뒤에서 두 번째 수에서 맨 뒤의 수를 뺀 값을 다음 수로 하는 것을 반복하는 것이다.

해결 방법 : 해당 수열의 길이는 길어도 logN의 길이에 비례한다. 따라서, 1부터 N(N보다 크면 음수가 나오므로)까지의 각 수를
두 번째 수로 하는 수열의 길이를 잰 다음 가장 긴 수가 나온 두 번째 수를 저장한다.
해당 수열의 길이는 재귀를 통해서 구할 수 있다.(코드 참조)
탐색이 끝나면 해당 수를 두 번째 수로 하는 수열을 출력하면 된다. 역시 재귀를 이용한다.

주요 알고리즘 : 브루트 포스, 재귀

출처 : 정올 2000 초1번
*/

int track(int n, int i, int l) {
    if (n < i) return l;
    else return track(i, n - i, l + 1);
}

void track2(int n, int i) {
    printf("%d ", n);
    if (n >= i) track2(i, n - i);
    else printf("%d", i);
}

int main(void) {
    int n, x, l = -1, r = -1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        x = track(n, i, 2);
        if (x > l) {
            l = x;
            r = i;
        }
    }
    printf("%d\n", l);
    track2(n, r);
    return 0;
}