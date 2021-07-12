#include <stdio.h>
#include <set>
using namespace std;

/*
문제 : 크기 N(N <= 18)인 집합의 부분합이 주어질 때, 크기 N인 집합을 만들 수 있는지 구하고,
가능하다면 해당 집합의 원소들을 출력한다. 단, 모든 원소는 0 이상의 정수이다.

해결 방법 : 모든 원소들을 트리셋에 집어넣는다. 먼저 가장 작은 수가 0인지 확인한 후 맞다면 지운다. 아니라면 해당 집합을
만들 수 없으므로 프로그램을 종료한다. 이후로는 가장 작은 원소를 가져온 뒤(현재 남은 부분합들 중 가장 작은 수),
가져온 원소와 현재까지의 원소들로 만들 수 있는 모든 부분합들을 트리셋에서 제거한다. 이를 반복하다가 부분합이 트리셋에 없다면
집합을 만들 수 없으므로 마찬가지로 종료하고, N개의 원소 전부에 대해 성공했다면 지금까지의 원소들을 출력하면 된다.

주요 알고리즘 : 그리디 알고리즘, 트리셋

출처 : BAPC 2019P K번
*/

multiset<long long> ms;
long long res[32];

int main(void) {
    long long n, w, x;
    scanf("%lld", &n);
    for (int i = 0; i < (1 << n); i++) {
        scanf("%lld", &w);
        ms.insert(w);
    }
    if (*(ms.begin()) != 0) {
        printf("impossible");
        return 0;
    }
    ms.erase(ms.begin());
    for (int i = 0; i < n; i++) {
        res[i] = *(ms.begin());
        for (int j = 0; j < (1 << i); j++) {
            x = res[i];
            for (int k = 0; k < i; k++) {
                if (j & (1 << k)) x += res[k];
            }
            if (ms.find(x) != ms.end()) {
                ms.erase(ms.find(x));
            }
            else {
                printf("impossible");
                return 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%lld\n", res[i]);
    }
    return 0;
}