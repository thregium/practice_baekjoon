#include <stdio.h>

/*
문제 : 시작 시각과 실행 기간이 주어질 때, 끝나는 시각을 구한다. 날짜가 바뀐다면 바뀌는 날짜의 수도 구한다.

해결 방법 : 시작 시각과 실행 기간을 통해 끝나는 시각을 분 단위로 계산한 다음, 날짜, 시간, 분 단위로 나누어 출력한다.

주요 알고리즘 : 수학, 구현, 사칙연산

출처 : NCPC 2012 C번
*/

int main(void) {
    int sh, sm, dh, dm, et, eh, em;
    while (1) {
        scanf("%d:%d %d:%d", &sh, &sm, &dh, &dm);
        if (sh == 0 && sm == 0 && dh == 0 && dm == 0) break;
        et = sh * 60 + sm + dh * 60 + dm;
        eh = et / 60;
        em = et % 60;
        if (eh >= 24) printf("%02d:%02d +%d\n", eh % 24, em, eh / 24);
        else printf("%02d:%02d\n", eh, em);
    }
    return 0;
}