#include <stdio.h>

/*
문제 : i dolphin(s), i jump(s), splash를 i번(i는 반복의 수)만큼 반복할 때,
N(N <= 2 * 10^9)번째에 외쳐야 할 것을 출력한다.

해결 방법 : 각 i마다 마지막에 외칠 번째을 계산해 나간다. 이를 반복하며 N번째를 넘어갈 때,
그 번째를 바탕으로 외쳐야 할 정확한 내용을 찾으면 된다.
등차수열의 합은 N^2에 비례하므로 O(sqrt(N))에 풀 수 있다.

주요 알고리즘 : 수학

출처 : Thai 2016A G번
*/

int main(void) {
    int t, n, s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        s = 0;
        for (int i = 1;; i++) {
            s += i * 3;
            if (s >= n) {
                if (s - i * 2 >= n) {
                    printf("%d dolphin", i);
                    if (i > 1) printf("s\n");
                    else printf("\n");
                }
                else if (s - i >= n) {
                    printf("%d jump", i);
                    if (i > 1) printf("s\n");
                    else printf("\n");
                }
                else printf("splash\n");
                break;
            }
        }
    }
    return 0;
}