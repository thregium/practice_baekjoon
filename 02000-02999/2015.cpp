#include <stdio.h>
#include <unordered_map>
using namespace std;

/*
문제 : 길이 N(N <= 200000)의 배열에 절댓값 10000 이하의 정수들이 있다.
이 배열의 구간합이 K(|K| <= 2 * 10^9)인 구간의 개수를 구한다.

해결 방법 : 왼쪽과 오른쪽부터의 누적 합 배열을 각각 만든 후, 오른쪽부터 역순으로 들어가면서
그곳의 오른쪽에서 끝나는 오른쪽 누적 합 배열의 값들을 하나씩 해시맵에 넣어 개수를 관리한다.
현재 위치에서 오른쪽과 왼쪽의 값을 빼 K가 되는 값의 개수를 결괏값에 더해나가면 답이 된다.

주요 알고리즘 : 자료 구조, 해시맵, 누적합
*/

int a[204800], lsum[204800], rsum[204800];
unordered_map<int, int> mp;

int main(void) {
    int n, k, s = 0;
    long long res = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        lsum[i] = lsum[i - 1] + a[i];
        s += a[i];
    }
    mp.insert({ 0, 1 });
    for (int i = n; i >= 1; i--) {
        rsum[i] = rsum[i + 1] + a[i];
        if (mp.find(s - lsum[i - 1] - k) != mp.end()) res += mp[s - lsum[i - 1] - k];
        
        if (mp.find(rsum[i]) == mp.end()) mp.insert({ rsum[i], 1 });
        else mp[rsum[i]]++;
    }
    printf("%lld", res);

    return 0;
}