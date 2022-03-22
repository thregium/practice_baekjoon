#include <stdio.h>

/*
문제 : 럭비에서 한 팀이 N(N <= 15)번의 움직임동안 터치다운이나 세이프티가 일어났는 지 확인한다.

해결 방법 : 최근 퍼스트다운이 일어난 이후 4회동안 10 야드 이상 전진하지 못했다면 공격권을 잃어버리고
공격이 끝난다. 따라서, 그러한 경우가 생긴다면 Nothing을 출력한다. 그 외에는 현재 위치가 100야드 이상이면
터치다운, 0야드 이하면 세이프티를 출력하고 마치면 된다. 끝까지 아무 일도 일어나지 않았다면
Nothing을 출력한다.

주요 알고리즘 : 구현

출처 : VTH 2018 G번
*/

int main(void) {
    int n, x, p = 20, q = 1, s = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        p += x, s += x;
        if (q == 4 && s < 10) {
            printf("Nothing");
            return 0;
        }
        if (x >= 10) {
            q = 0, s = 0;
        }
        q++;
        if (p >= 100) {
            printf("Touchdown");
            return 0;
        }
        else if (p <= 0) {
            printf("Safety");
            return 0;
        }
    }
    printf("Nothing");
    return 0;
}
