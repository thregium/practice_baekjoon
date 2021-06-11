#include <stdio.h>

/*
문제 : 태어난 연, 월, 일과 현재 연, 월, 일이 있을 때 만 나이, 세는 나이, 연 나이를 각각 구한다.

해결 방법 : 먼저 현재 날짜가 태어난 날짜 이후인지 확인한다. 이번 달이 태어난 달보다 뒤에 있거나 서로 같은 달이면서 태어난 날이 뒤인 경우이다.
만약 태어난 날 이후인 경우에는 현재 연도에서 태어난 연도를 빼면 만 나이가 되고, 전이라면 그 값에서 1을 빼면 만 나이가 된다.
세는 나이나 연 나이는 올해 연도에서 태여난 연도를 빼면 되고, 세는 나이라면 거기서 1을 더하면 된다.

주요 알고리즘 : 구현
*/

int main(void) {
    int yb, mb, db, yn, mn, dn, afterbday = 0;
    scanf("%d %d %d%d %d %d", &yb, &mb, &db, &yn, &mn, &dn);
    if (mb < mn) afterbday = 1;
    else if (mb == mn && db <= dn) afterbday = 1;

    if (afterbday) printf("%d\n", yn - yb);
    else printf("%d\n", yn - yb - 1);
    printf("%d\n%d", yn - yb + 1, yn - yb);
    return 0;
}