#include <stdio.h>
#include <stdlib.h>

/*
문제 : 길이 10 이상 1000 이하의 줄자에 3가지 색의 점이 2개씩 있다. 순서대로 같은 색의 점이 같은 위치에 오도록
줄자를 접을 때, 최종적으로 남는 줄자의 길이를 구한다.

해결 방법 : 각 색을 순서대로 접는 위치를 구한다. 만약 두 점이 같은 위치라면 접지 않고, 그렇지 않다면
두 점 위치의 평균을 구하면 된다. 그리고 다른 점들의 위치를 옮긴다. 접은 지점과의 거리로 옮기면 된다.
전체 줄자의 길이는 남은 두 부분의 길이 가운데 더 긴 부분의 길이이다.

주요 알고리즘 : 구현, 수학

출처 : 정올 2004 초2번
*/

int point[3][2];

int big(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int l, tf;
    scanf("%d", &l);
    l *= 2;
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &point[i][0], &point[i][1]);
        point[i][0] *= 2;
        point[i][1] *= 2;
    }
    for (int i = 0; i < 3; i++) {
        if (point[i][0] == point[i][1]) continue;
        tf = (point[i][0] + point[i][1]) / 2;
        for (int j = i + 1; j < 3; j++) {
            point[j][0] = abs(point[j][0] - tf);
            point[j][1] = abs(point[j][1] - tf);
        }
        l = big(tf, l - tf);
    }
    printf("%.1f", l / 2.0);
    return 0;
}