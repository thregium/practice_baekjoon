#include <stdio.h>

/*
문제 : 시작하는 시각과 끝나는 시각이 시:분:초 형태로 주어진다. 두개의 시각은 최대 24시간 - 1초 차이가 날 수 있다.
이때, 시작 시각과 끝 시각 사이의 시각으로 만들 수 있는 시계 정수 가운데 3의 배수인 것의 수를 찾는다.
시계 정수는 시:분:초를 시 * 10000 + 분 * 100 + 초의 형태로 정수로 바꾼 것이다.

해결 방법 : 먼저 각 시각을 초 단위로 바꾼다. 만약 끝나는 시간이 더 앞인 경우 끝나는 시각에 1일을 더해준다.
그 다음 시작 시각부터 끝나는 시각까지 반복하며 각 시각마다 시계 정수를 만든 다음 3의 배수인지 확인하면 된다.
시계 정수는 초 단위를 시, 분, 초로 분해한 뒤 각각 10000, 100, 1을 곱해서 더하면 되고, 3의 배수의 개수를 세면 답을 구할 수 있다.

주요 알고리즘 : 구현, 브루트 포스

출처 : Seoul 2006 A번
*/

int main(void) {
    int sh, sm, ss, st, eh, em, es, et, cn, r; //s : 시, 분, 초, 시각 / e : 시, 분, 초, 시각 / cn : 시계 정수, r : 결괏값
    for (int tt = 0; tt < 3; tt++) {
        scanf("%d:%d:%d %d:%d:%d", &sh, &sm, &ss, &eh, &em, &es);
        st = sh * 3600 + sm * 60 + ss;
        et = eh * 3600 + em * 60 + es;
        if (st > et) et += 86400;
        r = 0;
        for (int i = st; i <= et; i++) {
            cn = 10000 * (i / 3600 % 24) + 100 * (i / 60 % 60) + i % 60;
            if (cn % 3 == 0) r++;
        }
        printf("%d\n", r);
    }
    return 0;
}