#include <stdio.h>
#include <unordered_map>
using namespace std;

/*
문제 : N(N <= 10^12), P, Q(P, Q <= 10^9)가 주어질 때, f(0) = 1, f(N) = f(N / p) + f(N / q)로 정의되는 함수가 있다면,
이 함수의 값을 구한다.

해결 방법 : 탑다운 방식의 DP를 하되, 메모이제이션은 해시맵을 사용한다.

주요 알고리즘 : DP, 자료구조, 해시맵

출처 : SRM 413 D2C
*/

unordered_map<long long, long long> a;

long long dp(long long n, long long p, long long q) {
    if (n == 0) {
        if (a.find(n) == a.end()) a.insert(pair<long long, long long>(n, 1));
        return 1;
    }
    else if (a.find(n) != a.end()) {
        return a.find(n)->second;
    }
    else {
        long long r = dp(n / p, p, q) + dp(n / q, p, q);
        a.insert(pair<long long, long long>(n, r));
        return r;
    }
}

int main(void) {
    long long n, p, q;
    scanf("%lld %lld %lld", &n, &p, &q);
    printf("%lld", dp(n, p, q));
    return 0;
}