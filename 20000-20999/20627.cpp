#include <stdio.h>
#include <set>
using namespace std;

/*
문제 : N(N <= 1000)개의 자연수(<= 10^9)로 이루어진 배열이 있다. 이 배열의 최대공약수가
1보다 크게 만들기 위해 일부 수들을 제거할 때, 남은 수들의 합의 최댓값을 구한다.

해결 방법 : 각 배열의 최대공약수로 가능한 수들에 대해 모든 경우를 살펴보면 된다.
가능한 수들 중 봐야 할 수들은 소수일 때 뿐이다. 합성수인 경우보다 그 수를 이루는 소수가
더 최대공약수가 될 수 있는 경우가 많기 때문이다.

따라서, 배열의 각 수에 대해 그 수들을 소인수분해한 다음 1번이라도 나오는 소수들을 셋에 넣는다.
그 다음, 셋에 있는 각 수마다 그 수로 나누어 떨어지는 수의 합을 계산하고 가장 큰 것을 구하면 된다.

주요 알고리즘 : 수학, 정수론, 소인수분해, 브루트 포스, 셋

출처 : JAG 2019S1 B번 // Petro 2020S5 B번
*/

int a[1024];
set<int> prime;

int main(void) {
    int n;
    long long r = 0, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        t = a[i];
        for (int j = 2; j * j <= t; j++) {
            if (t % j == 0 && prime.find(j) == prime.end()) {
                prime.insert(j);
            }
            while (t % j == 0) t /= j;
        }
        if (t > 1 && prime.find(t) == prime.end()) prime.insert(t);
    }
    for (int i : prime) {
        t = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] % i == 0) t += a[j];
        }
        if (t > r) r = t;
    }
    printf("%lld\n", r);
    return 0;
}