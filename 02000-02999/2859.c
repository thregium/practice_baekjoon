#include <stdio.h>

/*
문제 : 두 별이 주기적으로 떨어진다고 할 때, 두 별이 처음 떨어진 시각과 떨어지는 주기가 주어지면
두 별이 처음으로 동시에 떨어지는 시점을 구한다. 주기는 0이 아니고 두 별이 처음 떨어진 시각은 서로 다르다.

해결 방법 : 시작점에서 최대 1440 * 1440만큼의 시간 안에는 두 별이 동시에 들어오거나
영원히 동시에 들어오지 않아야 하기 때문에 그 범위를 모두 탐색한 다음 같은 지 확인하면 된다.

주요 알고리즘 : 수학, 정수론, 브루트 포스

출처 : COCI 10/11#4 3번
*/

const char* weekday[7] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

int main(void) {
    int h, m, as, bs, at, bt;
    scanf("%d:%d", &h, &m);
    as = h * 60 + m;
    scanf("%d:%d", &h, &m);
    bs = h * 60 + m;
    scanf("%d:%d", &h, &m);
    at = h * 60 + m;
    scanf("%d:%d", &h, &m);
    bt = h * 60 + m;
    for (int i = 0; i < 103000; i++) {
        if (as < bs) as += at;
        else if (as > bs) bs += bt;
        else break;
    }

    if (as != bs) printf("Never");
    else printf("%s\n%02d:%02d", weekday[as / 1440 % 7], as / 60 % 24, as % 60);

    return 0;
}