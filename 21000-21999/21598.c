#include <stdio.h>

/*
문제 : 1이 주어지면 SciComLove를 1번, 2가 주어지면 SciComLove를 2번 출력한다.

해결 방법 : 문제에 쓰인대로 구현한다.

주요 알고리즘 : 구현

출처 : SciCom 2021Q 1A번
*/

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("SciComLove\n");
    }
    return 0;
}