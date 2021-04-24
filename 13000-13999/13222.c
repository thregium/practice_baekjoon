#include <stdio.h>

/*
문제 : 직사각형의 가로, 세로 길이 W, H가 각각 주어질 때, 주어진 길이의 선분이 직사각형에 들어갈 수 있는지 출력한다.

해결 방법 : 주어진 선분이 직사각형의 대각선 길이보다 작다면 직사각형에 들어갈 수 있다.
그 값은 피타고라스 정리를 이용해 구한다.

주요 알고리즘 : 기하학, 피타고라스 정리

출처 : AIPO 2015P 1번
*/

int main(void) {
    int n, w, h, l;
    scanf("%d %d %d", &n, &w, &h);
    for (int i = 0; i < n; i++) {
        scanf("%d", &l);
        if (l * l > w * w + h * h) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}