#include <stdio.h>

/*
문제 : 원의 반지름과 직사각형의 높이와 너비가 주어질 때, 이 직사각형이 원에 들어갈 수 있는지 구한다.
원에 내접하는 경우도 들어가는 경우이다.

해결 방법 : 직사각형의 대각선이 원의 지름 이하 길이라면 원에 들어갈 수 있다. 피타고라스 정리를 이용해
직사각형의 대각선 길이의 제곱을 구하고, 원의 지름의 제곱(반지름의 제곱 * 4)와 비교해서 직사각형쪽이 더 크다면 들어갈 수 없고
그 외에는 들어갈 수 있다.

주요 알고리즘 : 기하학, 피타고라스 정리

출처 : ULM 2008 A번
*/

int main(void) {
    int r, w, l;
    for (int tt = 1;; tt++) {
        scanf("%d", &r);
        if (r == 0) break;
        scanf("%d %d", &w, &l);
        if (w * w + l * l > r * r * 4) printf("Pizza %d does not fit on the table.\n", tt);
        else printf("Pizza %d fits on the table.\n", tt);
    }
    return 0;
}