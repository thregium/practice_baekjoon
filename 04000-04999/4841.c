#include <stdio.h>

/*
문제 : 1000자 이하의 수가 주어질 때, 이 수로 만들 수 있는 다음 개미 수를 구한다.

해결 방법 : 처음에는 같은 수의 개수를 1로 놓고, 이후로 숫자들을 앞에서부터 살펴본다. 다음 숫자와 같다면 개수를 1 늘리고,
다르다면 그때까지의 개수와 그 숫자를 출력하고 개수를 1로 초기화한다. 이를 수의 끝까지 반복하면 된다.

주요 알고리즘 : 문자열, 구현

출처 : Rocky 2007 B번
*/

char s[1024];

int main(void) {
    int t, cnt;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        cnt = 1;
        for (int i = 0; s[i]; i++) {
            if (s[i] != s[i + 1]) {
                printf("%d%c", cnt, s[i]);
                cnt = 1;
            }
            else cnt++;
        }
        printf("\n");
    }
    return 0;
}