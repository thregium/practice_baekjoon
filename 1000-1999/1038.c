#include <stdio.h>

/*
문제 : 맨 앞자리부터 맨 뒷자리까지의 숫자가 내림차순인 수 가운데 N번째 수를 구한다. (N <= 1000000)
존재하지 않는 경우 -1을 출력한다.

해결 방법 : 조건을 만족하는 가장 큰 수는 10자리 수인 9876543210이고, 이때의 N은 100만보다 작다.
따라서, 백트래킹을 통해 1자리부터 10자리까지 각 수가 조건에 만족하는지 여부를 확인해가며 N번째 수를 찾으면 된다.
*/

int n, c = 0; //c : 현재까지 구한 감소하는 수의 갯수
long long s = -1; //결괏값

void track(int p, int r, long long x, int y) {
    if (p == r) {
        if (c == n) s = x;
        c++;
        return;
    }
    x *= 10;
    for (int i = 0; i < y; i++) {
        track(p, r + 1, x + i, i);
    }
}

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++) {
        track(i, 0, 0, 10);
    }
    printf("%lld", s);
    return 0;
}