#include <stdio.h>

/*
문제 : N(<= 10) 크기의 배열에 -10부터 10 사이의 정수가 쓰여 있다. 이때, 모든 누적 합에 대한 음양 여부가 주어지면
가능한 배열 가운데 하나를 출력한다. 없는 경우는 주어지지 않는다.

해결 방법 : 첫 번째 수부터 가능한 모든 경우를 해본다. 만약 직전 하나의 누적 합이라도 만족하지 못한다면
탐색을 종료하고 다음 값을 탐색한다. 역방향으로 누적 합을 구하면 조금 더 시간을 절약할 수 있다.

주요 알고리즘 : 백트래킹, 누적 합

출처 : Seoul 2008 G번
*/

int a[16][16], arr[16];
int r = 0;

int track(int n, int x) {
    if (n == x) {
        r = 1;
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        return;
    }

    int s, t;
    for (int i = -10; i <= 10; i++) {
        arr[x] = i;
        s = 0, t = 1;
        for (int j = x; j >= 0; j--) {
            s += arr[j];
            if (a[j][x] < 0 && s >= 0) t = 0;
            if (a[j][x] == 0 && s != 0) t = 0;
            if (a[j][x] > 0 && s <= 0) t = 0;
            if (!t) break;
        }
        if (!t) continue;
        track(n, x + 1);
        if (r) return;
    }
}

int main(void) {
    int n;
    char c;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            c = getchar();
            if (c == '0') a[i][j] = 0;
            else if (c == '-') a[i][j] = -1;
            else if (c == '+') a[i][j] = 1;
            else return 1;
        }
    }
    track(n, 0);
    if (r == 0) return 1;
    return 0;
}