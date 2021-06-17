#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
문제 : 100자 이하의 알파벳 대문자로 이루어진 문자열이 주어질 때, 이 문자들로 만들 수 있는 사전 순으로 다음 문자열을 찾는다.
단, 마지막 문자열인 경우 그대로 출력한다.

해결 방법 : 이는 다음 순열과 같은 의미이므로 next_permutation 함수를 이용해 풀면 된다. 이때, 0을 반환한 경우에는
마지막 순열이었다는 의미이므로 다시 prev_permutation을 통해 원래 상태로 되돌린다.

주요 알고리즘 : 수학, 조합론, 문자열

출처 : Seoul 2003 C번
*/

char s[128];

int main(void) {
    int t, r;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        r = next_permutation(s, s + strlen(s));
        if (!r) prev_permutation(s, s + strlen(s));
        printf("%s\n", s);
    }
    return 0;
}