#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 10)개의 팬케이크가 있다. 각 팬케이크는 앞면 또는 뒷면을 보고 있다.
맨 위에서부터 임의 개수의 연속한 팬케이크의 순서와 앞뒤를 동시에 뒤집는 연산을 반복하여
모든 팬케이크가 앞면을 보도록 할 때, 필요한 연산의 최소 횟수를 구한다.

해결 방법 : 맨 위에서부터 연속한 같은 개수의 팬케이크를 뒤집어 나가며 모든 팬케이크가 +가 될 때 까지
뒤집는 것이 최적의 방법이다. 맨 뒤를 +로 가정하고 앞뒤가 바뀌는 지점을 세면 좀더 간단하게 풀 수 있다.

주요 알고리즘 : 그리디 알고리즘

출처 : GCJ 2016Q B1번
*/

char s[128];

int main(void) {
    int t, r, plus;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s", s);
        r = 0, plus = 1;
        for (int i = strlen(s) - 1; i >= 0; i--) {
            if (s[i] == '-' && plus) {
                plus = 0;
                r++;
            }
            else if (s[i] == '+' && !plus) {
                plus = 1;
                r++;
            }
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}