#include <stdio.h>
#include <assert.h>
#include <algorithm>
using namespace std;

/*
문제 : N(N <= 8)개의 비율이 자연수로 주어진다. 비율 합이 100일 때, 비율로 원형 차트를 그려서 나오는
중심선의 개수가 가장 많을 때의 중심선 개수를 구한다.

해결 방법 : next_permutation() 함수를 이용하여 모든 경우를 세면서 각 경우 가운데 중심선의 개수가
가장 많은 경우를 세면 된다.

주요 알고리즘 : 브루트 포스
*/

int a[8];
int best = 0;

int count_halfline(int n) {
    int r = 0, sum;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; sum < 50; j = (j + 1) % n) {
            sum += a[j];
            if (sum == 50) r++;
        }
    }
    assert(r % 2 == 0);
    r >>= 1;
    if (r > best) best = r;
    return r;
}

int main(void) {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        assert(a[i] > 0);
        sum += a[i];
    }
    assert(sum == 100);
    while (next_permutation(a, a + n));
    count_halfline(n);
    while (next_permutation(a, a + n)) count_halfline(n);
    printf("%d", best);
    return 0;
}