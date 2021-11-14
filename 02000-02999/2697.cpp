#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/*
문제 : 80자 이하의 수가 주어질 때, 이 수와 구성이 같으면서 이 수 다음 크기인 수를 구한다.
없다면 BIGGEST를 출력한다.

해결 방법 : next_permutation 함수를 이용한다.

주요 알고리즘 : 수학, 조합론, 문자열

출처 : GNY 2009 E번
*/

char s[128];

int main(void) {
    int t, n, l;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%s", s);
        l = strlen(s);
        if (!next_permutation(s, s + l)) printf("BIGGEST\n");
        else printf("%s\n", s);
    }
    return 0;
}