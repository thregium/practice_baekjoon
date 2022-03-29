#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 100)잔의 커피가 있다. 각 커피는 X(X <= 4)번의 샷에 라떼를 추가하거나 추가하지 않은 형태이다.
각 커피에서 라떼를 추가하면 샷 수 + 1만큼의 물을, 추가하지 않으면 샷 수만큼의 물을 사용한다.
물통의 용량(<= 200)이 주어질 때, 순서대로 커피를 만들기 위해 물을 다시 받아야 하는 횟수를 구한다.
물이 모자란 경우 남은 물은 버린다.
각 커피는 숫자(+ L)의 형태로 주어지며, 숫자는 샷 수, L은 라떼가 있는 경우이다.

해결 방법 : 각 커피를 문자열 형태로 입력받은 다음, 끝 자리가 1인지 여부에 따라 물의 양을 체크한다.
물의 양이 모자란 경우 물을 새로 받는 것을 반복하며 물을 받은 횟수를 세면 된다.

주요 알고리즘 : 문자열, 파싱, 시뮬레이션

출처 : MidAtl 2021 A번 // NCNA 2021 L번
*/

char buff[8];

int main(void) {
    int n, s, c, r = 0;
    scanf("%d %d", &n, &s);
    c = s;
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        if (buff[strlen(buff) - 1] == 'L') c -= strtoll(buff, NULL, 10) + 1;
        else c -= strtoll(buff, NULL, 10);
        if (c < 0) {
            if (buff[strlen(buff) - 1] == 'L') c = s - strtoll(buff, NULL, 10) - 1;
            else c = s - strtoll(buff, NULL, 10);
            r++;
        }
    }
    printf("%d", r);
    return 0;
}