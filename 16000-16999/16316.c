#include <stdio.h>
#include <stdlib.h>

/*
문제 : 1부터 N(N <= 1000)까지의 수를 센다. 이때, 몇 개의 수를 mumble로 바꾸었다고 한다면, 제대로 수를 센 것인지 확인한다.

해결 방법 : 수들을 문자열로 입력받은 후 mumble인 경우 건너뛰고, 수이며 해당 번째가 아닌 수가 있는지 확인하면 된다.

주요 알고리즘 : 구현, 파싱

출처 : NCPC 2018 B번
*/

char buff[64];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", buff);
        if (buff[0] == 'm') continue;
        else if (strtoll(buff, NULL, 10) != i) r = 0;
    }
    if (r) printf("makes sense");
    else printf("something is fishy");
    return 0;
}