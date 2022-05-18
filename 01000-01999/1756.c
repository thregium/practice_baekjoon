#include <stdio.h>
#define INF 1012345678

/*
문제 : D개의 층으로 이루어진 오븐과 N(D, N <= 300000)개의 피자가 있다. 이때, 오븐의 각 위치와
각 피자의 사이즈가 주어지면 피자를 차례로 오븐에 넣었을 때 마지막 피자의 위치를 구한다.

해결 방법 : 오븐의 각 층의 누적 최솟값을 구한다. 이는 해당 층 또는 그 이상 높이의 사이즈 가운데 최솟값이다.
그 다음, 피자가 들어올 때 마다 마지막 위치 - 1 위치에서부터 피자를 놓을 장소를 찾아나간다.
이는 누적 최솟값이 해당 피자의 크기 이상인 첫 장소가 되면 된다. 이를 반복해 답을 찾을 수 있다.

주요 알고리즘 : 누적 합, 투 포인터

출처 : POI 2005/2006_1 1번
*/

int oven[327680], pizza[327680];

int main(void) {
    int d, n, x, p;
    scanf("%d %d", &d, &n);
    p = d + 1;
    oven[0] = INF;
    for (int i = 1; i <= d; i++) {
        scanf("%d", &oven[i]);
        if (oven[i - 1] < oven[i]) oven[i] = oven[i - 1];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (p > 0) p--;
        while (p > 0 && x > oven[p]) p--;
    }
    printf("%d", p);
    return 0;
}