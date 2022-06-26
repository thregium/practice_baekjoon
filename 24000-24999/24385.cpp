#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
문제 : 서로 다른 3개 이상 7개 이하의 소문자로 이루어진 문자열이 주어질 때,
이 문자열로 만들 수 있는 모든 순열을 사전순으로 출력한다.

해결 방법 : next_permutation() 함수를 이용하여 모든 순열을 확인하면 된다.

주요 알고리즘 : 브루트 포스

출처 : IATI 2013D 3번
*/

char s[8];

int main(void) {
    int l;
    scanf("%s", s);
    l = strlen(s);
    while (next_permutation(s, s + l));
    do {
        printf("%s\n", s);
    } while (next_permutation(s, s + l));
    return 0;
}