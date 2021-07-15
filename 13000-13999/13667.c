#include <stdio.h>

/*
문제 : 5개의 수 가운데 127 이하인 수를 선택했다고 한다. 이 중 하나만 선택했다면 선택한 수의 번호를 출력하고
선택하지 않았다면 *를 출력한다.

해결 방법 : 각 수들 중 마지막으로 127 이하였던 수와 선택한 수의 개수를 저장한다. 선택한 수가 1개라면
마지막으로 선택했던 수를 출력하고 1개가 아니면 *를 출력하면 된다.

주요 알고리즘 : 구현

출처 : Brasil 2010 J번
*/

int main(void) {
    int n, x, cnt, l;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            cnt = 0, l = -1;
            for (int j = 0; j < 5; j++) {
                scanf("%d", &x);
                if (x < 128) {
                    cnt++;
                    l = j;
                }
            }
            if (cnt == 1) printf("%c\n", 'A' + l);
            else printf("*\n");
        }
    }
    return 0;
}