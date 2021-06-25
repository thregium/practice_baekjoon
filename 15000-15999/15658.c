#include <stdio.h>
#define INF 1012345678

/*
문제 : N(N <= 11)개의 수 사이에 연산자를 적절히 끼워넣어 넣을 수 있는 가장 큰 수와 작은 수를 각각 구한다.
단, 넣을 수 있는 연산자의 개수가 정해져 있고, 연산자 우선순위는 무시한다.

해결 방법 : 맨 앞부터 차례로 남아있는 연산자들을 하나씩 끼워가며 확인한다. 끼우려는 연산자가 없다면 끼우지 않고
다른 연산자를 확인해본다.

주요 알고리즘 : 브루트 포스, 백트래킹
*/

int a[16], op[4];
int highest = -INF, lowest = INF; //최대, 최솟값을 불가능한 값으로 정의

track(int n, int c, int m) {
    if (c == n - 1) {
        if (m > highest) highest = m;
        if (m < lowest) lowest = m;
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!op[i]) continue;
        op[i]--;
        if (i == 0) track(n, c + 1, m + a[c + 1]);
        else if (i == 1) track(n, c + 1, m - a[c + 1]);
        else if (i == 2) track(n, c + 1, m * a[c + 1]);
        else if (i == 3) track(n, c + 1, m / a[c + 1]);
        op[i]++;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 4; i++) {
        scanf("%d", &op[i]);
    }
    track(n, 0, a[0]);
    printf("%d\n%d", highest, lowest);
    return 0;
}