#include <stdio.h>
#include <map>
using namespace std;

/*
문제 : 각각 길이 N과 M(N, M <= 1000)인 수열 A, B가 있을 때 이 수열의 연속합을 각각 더해서 T(|T| <= 10^9)가 나오게 하는 방법의 가짓수를 수한다.

해결 방법 : A의 연속합으로 만들 수 있는 모든 수와 그 방법을 만드는 가짓수를 구해서 맵에 저장한다.
그 다음 B의 연속합으로 만들 수 있는 모든 방법에 대해 해당 합과 합해서 T가 나오게 하는 A의 방법의 가짓수를 결괏값에 더한다.
이를 모든 방법에 대해 시행하면 답을 얻을 수 있다.

주요 알고리즘 : 자료구조, map

출처 : 정올 2001 고1번
*/

int a[1024], b[1024];
map<int, int> mp;

int main(void) {
    int t, n, m, p, s;
    long long r = 0;
    scanf("%d%d", &t, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = i; j < n; j++) {
            s += a[j];
            if (mp.find(s) == mp.end()) {
                mp.insert(pair<int, int>(s, 1));
            }
            else {
                p = mp.find(s)->second;
                mp.erase(s);
                mp.insert(pair<int, int>(s, p + 1));
            }
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < m; i++) {
        s = 0;
        for (int j = i; j < m; j++) {
            s += b[j];
            if (mp.find(t - s) != mp.end()) {
                r += mp.find(t - s)->second;
            }
        }
    }
    printf("%d", r);
    return 0;
}