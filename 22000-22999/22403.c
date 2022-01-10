#include <stdio.h>

/*
문제 : 길이 N(N <= 100)의 "A"와 "Un"으로 이루어진 문자열의 배열이 주어질 때, 각 "A"의 뒤에는 "Un"이 오는 지,
각 "Un"의 앞에는 "A"가 오는 지 구한다.

해결 방법 : 괄호 문자열인지 여부를 검사하는 것과 동치이다. 스택을 이용할 수도 있고,
여는 괄호("A")의 개수를 세는 방법 등이 있을 수 있다.

주요 알고리즘 : 구현

출처 : JAG 2016DA A번
*/

char buff[8];

int main(void) {
    int n, a = 0, r = -1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (buff[0] == 'A') {
            if (r < 0) r = 1;
            a++;
        }
        else {
            if (r < 0) r = 0;
            a--;
            if (a < 0) r = 0;
        }
    }
    if (a == 0 && r > 0) printf("YES");
    else printf("NO");
    return 0;
}