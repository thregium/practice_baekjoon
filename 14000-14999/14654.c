#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 300)번의 가위바위보를 두 팀이 한다. 두 팀의 경기 가운데 가장 오래 연승한 횟수를 구한다.
첫 경기는 반드시 승부가 갈리고, 이후로는 무승부시 연승중이던 팀이 지는 것으로 생각한다.

해결 방법 : 가위바위보의 승부를 함수로 만든 다음, 매 경기를 확인하며 승부를 확인한다. 연승중이던 팀이 이기면
연승 횟수를 늘리고, 지면 새로운 팀의 연승 횟수를 1로 바꾸어 다시 확인한다.
이 가운데 연승 횟수가 가장 큰 것을 찾으면 된다.

주요 알고리즘 : 구현, 시뮬레이션

출처 : 선린 1회 E번
*/

int a[384], b[384];

int game(int a, int b) {
    if (a == b) return 0;
    else if (a == b + 1 || (a == 1 && b == 3)) return 1;
    else return -1;
}

int main(void) {
    int n, w = 0, r = 0, g;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    for (int i = 0; i < n; i++) {
        g = game(a[i], b[i]);
        if (g > 0) {
            if (w > 0) w++;
            else w = 1;
        }
        else if (g < 0) {
            if (w < 0) w--;
            else w = -1;
        }
        else {
            if (w > 0) w = -1;
            else if (w < 0) w = 1;
            else return 1;
        }
        if (r < abs(w)) r = abs(w);
    }
    printf("%d", r);
    return 0;
}