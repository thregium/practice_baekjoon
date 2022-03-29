#include <stdio.h>

/*
문제 : 두 음이 아닌 정수 A, B(A <= B < 2^31)가 주어질 때, A의 각 자릿수에 몇 거듭제곱을 해서 더해야
B가 되는 지 구한다. 그러한 답이 유일한 경우만 주어진다.

해결 방법 : 크기 제한이 심하기 때문에 모든 경우의 수를 살펴보면서 답을 찾아 나가면 된다.

주요 알고리즘 : 수학, 브루트 포스, 백트래킹

출처 : VTH 2021 K번
*/

int arr[16];

int b10(int x) {
    if (x >= 1000000000) return 1000000000;
    else if (x >= 100000000) return 100000000;
    else if (x >= 10000000) return 10000000;
    else if (x >= 1000000) return 1000000;
    else if (x >= 100000) return 100000;
    else if (x >= 10000) return 10000;
    else if (x >= 1000) return 1000;
    else if (x >= 100) return 100;
    else if (x >= 10) return 10;
    else return 1;
}

void printkey(int a, int b, int t, int p) {
    if (t == 0) {
        if (b == 0) {
            for (int i = 0; i < p; i++) printf("%d ", arr[i]);
        }
        return;
    }
    int x = a / t % 10;
    for (long long i = t, j = 0; i <= b; i *= x, j++) {
        arr[p] = j;
        printkey(a, b - i, t / 10, p + 1);
    }
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printkey(a, b, b10(a), 0);
    return 0;
}