#include <stdio.h>

/*
문제 : 길이 N(N <= 10^6)의 'W', 'Z'로 이루어진 문자열이 주어질 때, 모든 'Z'가 선택되거나
양 옆 중 하나의 'Z'가 선택되도록 'Z'를 선택할 때 선택해야 하는 최소의 'Z' 개수를 구한다.

해결 방법 : 각 'Z'의 연속마다 선택해야 하는 개수를 세면 ceil(연속 길이 / 3)과 같다.
따라서, 이를 각각 구해서 더하면 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : JPOI 2012 1-5번
*/

char s[1048576];

int main(void) {
    int n, cons = 0, r = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') {
            r += (cons + 2) / 3;
            cons = 0;
        }
        else cons++;
    }
    r += (cons + 2) / 3;
    printf("%d", r);
    return 0;
}