#include <stdio.h>

/*
문제 : 10^12 이하의 음이 아닌 정수 N이 주어질 때, N을 자연수로 분할하는 방법의 가짓수를 구한다.
순서만 다른 것도 다른 것으로 생각한다.

해결 방법 : 0일 때의 답은 없는 것 하나뿐이므로 0이다. 1일 때의 답도 1 하나뿐이므로 1이다.
2 이상인 경우에는 시작점을 해당 수 이전의 수로 하는 모든 답의 합과 같다. 따라서, 2^(N - 1)과 같아진다.
이 값은 분할 거듭제곱으로 빠르게 구할 수 있으므로 이를 통해 답을 구하면 된다.

주요 알고리즘 : 수학, 조합론, 분할 거듭제곱

출처 : 네블컵 1회 K번
*/

long long powe(long long x, long long y, long long m) {
    if (y == 1) return x;
    else if (y <= 0) return 1;
    long long h = powe(x, y >> 1, m);
    h = (h * h) % m;
    if (y & 1) return (h * x) % m;
    else return h;
}

int main(void) {
    long long n;
    scanf("%lld", &n);
    printf("%lld", powe(2, n - 1, 1000000007));
    return 0;
}