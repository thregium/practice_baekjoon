#include <stdio.h>
#include <unordered_map>
using namespace std;

/*
���� : N(N <= 10^12), P, Q(P, Q <= 10^9)�� �־��� ��, f(0) = 1, f(N) = f(N / p) + f(N / q)�� ���ǵǴ� �Լ��� �ִٸ�,
�� �Լ��� ���� ���Ѵ�.

�ذ� ��� : ž�ٿ� ����� DP�� �ϵ�, �޸������̼��� �ؽø��� ����Ѵ�.

�ֿ� �˰��� : DP, �ڷᱸ��, �ؽø�

��ó : SRM 413 D2C
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