#include <stdio.h>
#include <algorithm>
using namespace std;

/*
문제 : 자연수 N(N <= 10^18)이 주어졌을 때, 이진수로 나타냈을 때 N과 1의 개수가 같은 수 가운데 N보다 크며 가장 작은 수나 작으며 가장 큰 수를 찾는다.
그러한 수가 없는 경우 0을 출력한다.

해결 방법 : 이진수로 나타냈을 때 N과 1의 개수가 같다는 것은 N을 이진수로 표현한 것을 순열로 볼 때 N과 같은 순열이라고 할 수 있다.
따라서, next_permutation이나 prev_permutation 함수를 이용해 답을 구할 수 있다.

주요 알고리즘 : 수학, 조합론

출처 : 정올 2011지역 고2번
*/

long long ab[64];

int main(void) {
    long long a, t, x = 0, y = 0;
    scanf("%lld", &a);
    for (int i = 0; i < 64; i++) {
        ab[63 - i] = ((a >> i) & 1);
    }
    t = prev_permutation(ab, ab + 64);
    for (int i = 0; i < 64; i++) {
        x += (ab[63 - i] << i);
    }
    if (!t) x = 0;
    next_permutation(ab, ab + 64);
    t = next_permutation(ab, ab + 64);
    for (int i = 0; i < 64; i++) {
        y += (ab[63 - i] << i);
    }
    if (!t) y = 0;

    printf("%lld %lld", x, y);
    return 0;
}