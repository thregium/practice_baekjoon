#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
문제 : 20자 이하의 소문자로 이루어진 문자열이 주어질 때, 이 문자열의 아나그램을 사전순으로 모두 출력한다.
단, 아나그램은 최대 100000개 까지만 나온다.

해결 방법 : next_permutation 함수를 이용해 첫 번째 아나그램으로 돌아간 다음, 마찬가지로 next_permutation() 함수로
아나그램들을 각각 출력하면 된다.

주요 알고리즘 : 수학, 조합론

출처 : SWERC 1995 E번
*/

char s[32];

int main(void) {
    int n, l;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        l = strlen(s);
        while (next_permutation(s, s + l));
        while (1) {
            printf("%s\n", s);
            if (!next_permutation(s, s + l)) break;
        }
    }
    return 0;
}