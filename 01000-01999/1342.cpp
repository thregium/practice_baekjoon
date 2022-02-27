#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
문제 : 길이 10 이하의 소문자로 이루어진 문자열이 주어질 때, 이 문자열을 재배치하여
만들 수 있는 (인접한 글자 중 같은 글자가 없는 문자열)의 개수를 구한다.

해결 방법 : next_permutation 함수를 이용해 모든 순열을 확인해가며 조건을 만족하는 것의 개수를 찾으면 된다.

주요 알고리즘 : 문자열, 브루트 포스

출처 : SRM 428D1 1번 / D2 2번
*/

char s[16];

int main(void) {
    int l, r = 0, t;
    scanf("%s", s);
    l = strlen(s);
    while (next_permutation(s, s + l));
    while (1) {
        t = 1;
        for (int i = 1; i < l; i++) {
            if (s[i] == s[i - 1]) {
                t = 0;
                break;
            }
        }
        r += t;
        if (!next_permutation(s, s + l)) break;
    }
    printf("%d", r);
    return 0;
}