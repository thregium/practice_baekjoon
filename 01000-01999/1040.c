#include <stdio.h>

/*
문제 : N보다 크거나 같은 수 가운데 K개의 서로 다른 수로 이루어진 자연수 중 가장 작은 수를 구한다. (N <= 10^18)

해결 방법 : 마지막 자리에서 시작해서 자리를 올려가며 해당 자리까지만 놓고 봤을 때 문제의 조건을 만족할 수 있는지 여부를 확인한다.
조건을 만족할 수 있는 경우 뒷 자리로 이동해 조건을 만족하는 경우를 다시 찾는다. 만족할 수 없는 경우 해당 자리의 수를 1 올리고,
9에서 0으로 올라간 경우 앞 자리로 이동한다. 이를 반복하다가 다시 마지막 자리로 돌아오면 그때의 값을 결괏값으로 한다.(항상 돌아오는 것이 가능하다.)

주요 알고리즘 : 다이나믹 프로그래밍?, 그리디 알고리즘?, 백트래킹?
*/

long long d10[24]; //10^i을 저장한다

int available(long long n, long long k, int d) {
    char appear[10] = { 0, };
    for (int i = 0; i < d; i++) n /= 10;
    for (long long x = n; x; x /= 10) {
        appear[x % 10]++;
    }
    int r = 0;
    for (int i = 0; i < 10; i++) {
        r += !!appear[i];
    }
    if (r > k || r < k - d) return 0;
	//현재 자리까지 등장한 서로 다른 수가 k보다 크거나 남은 자리를 모두 사용해도 k가 될 수 없는 경우 0을 반환, 나머지 경우에는 1을 반환한다.
    return 1;
}

int main(void) {
    long long n, k, t, d, x;
    scanf("%lld %lld", &n, &k);
    t = n;
    x = 1;
    for (int i = 0; i <= 18; i++) {
        d10[i] = x;
        x *= 10;
    }
    d = 0;
    while (1) {
        if (available(t, k, d)) {
            d--;
            if (d < 0) break; //맨 뒷 자리에서 값이 결정된 경우 프로그램을 종료한다.
            else continue;
        }
        t += d10[d]; //해당 자릿수를 1 올린다.
        if (t / d10[d] % 10 == 0) d++; //해당 자리에서 모든 자릿수를 확인한 경우 위치를 한 칸 앞으로 옮긴다.
    }
    printf("%lld", t);
    return 0;
}