#include <stdio.h>
#include <unordered_map>
using namespace std;

/*
문제 : N(N <= 1000)개의 자연수(<= 10^9)의 곱으로 이루어진 두 수의 최대공약수를 구한다. 10^9 이상인 경우 마지막 9자리만 구한다.

해결 방법 : 각 수에 대해 구성되는 모든 자연수를 소인수분해한다. 이때, 소인수가 매우 커질 수 있으므로 각 소인수는
해시맵에 해당하는 소인수의 개수와 함께 저장한다. 저장이 끝나면 두 수에 대해 겹치는 소인수를 겹치는 횟수만큼 곱해나간다.
곱하면서 10^9를 넘어가면 넘었음을 저장하고, 10억으로 나눈 모듈로를 저장해나간다.
마지막으로 10억으로 넘었는지 확인하고 넘었다면 마지막 9자리를 출력, 넘지 않았다면 그대로 출력한다.

주요 알고리즘 : 수학, 정수론, 에라토스테네스, 해시맵

출처 : COCI 11/12#2 3번
*/

char sieve[32768];
int prime[4096];
int pp = 0;
unordered_map<int, int> a, b;

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    for (int i = 2; i < 32768; i++) {
        if (sieve[i]) continue;
        prime[pp++] = i; //32768 미만의 소수 저장
        for (int j = i * 2; j < 32768; j += i) sieve[j] = 1;
    }
    int n, x, c, r2 = 0;
    long long r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        for (int j = 0; j < pp; j++) {
            if (x % prime[j]) continue;
            c = 0; //소인수 분해
            while (x % prime[j] == 0) {
                x /= prime[j];
                c++;
            }
            if (a.find(prime[j]) == a.end()) a.insert(pair<int, int>(prime[j], c)); //새로운 소인수
            else a.find(prime[j])->second += c; //이미 있는 소인수
        }
        if (x == 1) continue;
        else if (x < prime[pp - 1]) return 1;
        else {
            if (a.find(x) == a.end()) a.insert(pair<int, int>(x, 1)); //큰 소인수에 대해
            else (a.find(x)->second)++;
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        for (int j = 0; j < pp; j++) {
            if (x % prime[j]) continue;
            c = 0; //소인수 분해
            while (x % prime[j] == 0) {
                x /= prime[j];
                c++;
            }
            if (b.find(prime[j]) == b.end()) b.insert(pair<int, int>(prime[j], c));
            else b.find(prime[j])->second += c;
        }
        if (x == 1) continue;
        else if (x < prime[pp - 1]) return 1;
        else {
            if (b.find(x) == b.end()) b.insert(pair<int, int>(x, 1)); //큰 소인수
            else (b.find(x)->second)++;
        }
    }
    
    for (auto i : a) {
        if (b.find(i.first) == b.end()) continue;
        else {
            c = small(i.second, b.find(i.first)->second); //겹치는 소인수의 개수만큼 곱하기
            for (int j = 0; j < c; j++) {
                if (r * i.first >= 1000000000) {
                    r2 = 1; //10억을 넘었음에 대한 표시
                    r = r * i.first % 1000000000; //모듈로 처리
                }
                else r *= i.first;
            }
        }
    }
    if (r2) printf("%09lld", r);
    else printf("%lld", r);
    return 0;
}