#include <stdio.h>

/*
문제 : N(N <= 100)개의 줄이 있고, 각 줄은 section, subsection, subsubsection으로 나뉜다.
각 줄의 이름과 종류가 주어질 때, 각 줄에 번호를 붙여 출력한다.

해결 방법 : 각 section, subsection, subsubsection의 개수를 센 다음, 개수 + 1을 각각 출력하면 된다.
출력한 다음마다 해당 종류에 1을 더하고, 아래 종류는 0으로 초기화해 둔다.

주요 알고리즘 : 구현

출처 : COCI 21/22#2 1번
*/

char buff[32], tit[32];

int main(void) {
    int n, a = 0, b = 0, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", buff, tit);
        if (buff[1] == 'e') {
            printf("%d %s\n", ++a, tit);
            b = 0, c = 0;
        }
        else if (buff[4] == 'e') {
            printf("%d.%d %s\n", a, ++b, tit);
            c = 0;
        }
        else printf("%d.%d.%d %s\n", a, b, ++c, tit);
    }
    return 0;
}
