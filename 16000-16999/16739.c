#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
문제 : 9자 이하의 문자열 N + 1(N <= 1000)개가 주어진다. 각 문자열은 알파벳과 숫자로 이루어져 있다.
이때, 2번째부터 각 문자열마다 첫 번째 문자열보다 파일 순으로 앞에 오는 지 구한다.
파일 순서는 문자와 숫자를 따로 보는 방법으로 각 문자열을 문자는 1개씩, 숫자는 연속한 수 단위로 바꾼 다음,
앞에서부터 차례로 보면서 서로 다른 것이 나오는 점을 찾는다. 서로 다른 것이 나오는 점에서
하나가 수, 다른 하나가 문자인 경우 수가 있는 것이 앞, 둘 다 수인 경우 수를 비교해 작은 것이 앞,
둘 다 문자인 경우 사전 순 비교를 한다. 하나가 비었다면 빈 것이 앞에 온다.

해결 방법 : 문자열들을 주어진 방법대로 자른 다음, 앞에서부터 비교해 나간다.
문제의 조건대로 비교하면 된다. 수 비교는 길이가 짧기 때문에 strtoll() 함수를 이용할 수 있다.

주요 알고리즘 : 문자열, 파싱

출처 : Yokohama 2018 A번
*/

char s0[16], frag0[16][16], s1[16], frag1[16][16];

int isdc(char c) {
    if (isdigit(c)) return 0;
    else if (isalpha(c)) return 1;
    else return -1;
}

int main(void) {
    int n, p1 = 0, p2 = 0, p3 = 0, p4 = 0, r;
    scanf("%d", &n);
    scanf("%s", s0);
    for (int i = 0; s0[i]; i++) {
        if (i == 0 || !(isdc(s0[i]) || isdc(s0[i - 1]))) frag0[p1][p2++] = s0[i];
        else {
            p2 = 0;
            frag0[++p1][p2++] = s0[i];
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", s1);
        p3 = 0, p4 = 0;
        for (int j = 0; s1[j]; j++) {
            if (j == 0 || !(isdc(s1[j]) || isdc(s1[j - 1]))) frag1[p3][p4++] = s1[j];
            else {
                p4 = 0;
                frag1[++p3][p4++] = s1[j];
            }
        }

        r = 0;
        for (int j = 0;; j++) {
            if (j > p3 && j <= p1) {
                r = -1;
                break;
            }
            else if (j > p1) {
                r = 1;
                break;
            }
            if (isdc(frag0[j][0]) != isdc(frag1[j][0])) {
                r = isdc(frag1[j][0]) - isdc(frag0[j][0]);
                break;
            }
            if (isdc(frag0[j][0])) {
                r = strcmp(frag1[j], frag0[j]);
                if (r != 0) break;
            }
            else {
                if (strtoll(frag1[j], NULL, 10) > strtoll(frag0[j], NULL, 10)) {
                    r = 1;
                    break;
                }
                else if (strtoll(frag1[j], NULL, 10) < strtoll(frag0[j], NULL, 10)) {
                    r = -1;
                    break;
                }
            }
        }
        printf("%c\n", r > 0 ? '+' : '-');


        for (int j = 0; j < 16; j++) {
            for (int k = 0; k < 16; k++) frag1[j][k] = 0;
        }
    }
    return 0;
}