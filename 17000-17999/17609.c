#include <stdio.h>
#include <string.h>

/*
문제 : 길이 N(N <= 100000)의 소문자로 이루어진 문자열이 주어질 때, 이 문자열이 회문인지,
또는 한 글자를 제거하여 회문이 되는지(유사회문) 여부를 구한다.

해결 방법 : 양쪽에서부터 문자들을 보면서 서로 다른 문자가 나오면 앞의 문자를 제거하고 다음 문자가 뒤의 문자와 같은지 확인한다.
같은 경우 앞 문자를 무시하고 이후 문자들이 모두 같은지 확인한다. 나오지 않는다면 회문이고, 이후 모든 문자들이 같다면
유사회문이다. 그 외에는 다시 뒤의 문자를 제거하고 앞의 문자와 비교한 다음, 유사회문 여부를 살피면 된다.

주요 알고리즘 : 문자열, 투 포인터

출처 : 정올 2019 1차 초2번
*/

char s[103000];

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        r = 0;
        for (int i = 0, j = strlen(s) - 1; i <= j; i++, j--) {
            if (s[i] != s[j]) {
                if (r) {
                    r = 2;
                    break;
                }
                else if (s[i + 1] == s[j]) {
                    r++;
                    i++;
                }
                else if (s[i] == s[j - 1]) {
                    r++;
                    j--;
                }
                else {
                    r = 2;
                    break;
                }
            }
        }
        if (r < 2) {
            printf("%d\n", r);
            continue;
        }
        r = 0;
        for (int i = 0, j = strlen(s) - 1; i <= j; i++, j--) {
            if (s[i] != s[j]) {
                if (r) {
                    r = 2;
                    break;
                }
                else if (s[i] == s[j - 1]) {
                    r++;
                    j--;
                }
                else if (s[i + 1] == s[j]) {
                    r++;
                    i++;
                }
                else {
                    r = 2;
                    break;
                }
            }
        }
        printf("%d\n", r);
    }
    return 0;
}