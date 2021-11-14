#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
문제 : 6자리 이하의 수가 주어질 때, 이 수와 조합이 같으면서 그 수보다 큰 가장 작은 수를 구한다.
없는 경우 0을 출력한다.

해결 방법 : next_permutation 함수를 이용한다.

주요 알고리즘 : 수학, 조합론?

출처 : COCI 07/08#4 2번
*/

char s[16];

int main(void) {
    scanf("%s", s);
    if (!next_permutation(s, s + strlen(s))) printf("0");
    else printf("%s", s);
    return 0;
}