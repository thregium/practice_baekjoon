#include <stdio.h>

/*
문제 : 길이 N(N <= 100000)의 두 'W', 'B'로 이루어진 문자열이 주어질 때, 앞 문자열에서 'W'와 'B'를 교환하거나
'W'를 'B'로 바꾸거나 'B'를 'W'로 바꾸는 연산이 가능할 때, 몇 회 연산을 해야 뒤 문자열이 되는지 구한다.

해결 방법 : 두 문자열에서 서로 다른 문자의 개수를 센다. 이를 첫 번째 문자열에서 'W'인 경우와 'B'인 경우로 나누어 세야 한다.
그러면 'W'와 'B'가 균형을 맞출 때 까지는 서로를 바꾸고, 그 외에는 따로 반대로 바꾸면 되기 때문에
W인 경우와 B인 경우의 개수 중 더 많은 것이 답이 된다.

주요 알고리즘 : 그리디 알고리즘

출처 : 국민대 2016 A번
*/

char s1[103000], s2[103000];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int t, n, wb, bw;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        scanf("%s%s", s1, s2);
        wb = 0, bw = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'W' && s2[i] == 'B') wb++;
            else if (s1[i] == 'B' && s2[i] == 'W') bw++;
        }
        printf("%d\n", big(wb, bw));
    }
    return 0;
}