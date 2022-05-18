#include <stdio.h>
#include <map>
using namespace std;

/*
문제 : N + 1(N <= 10^6)개의 버튼으로 이루어진 기계가 있다. 1부터 N까지의 버튼은 그 버튼의 카운터를
1씩 증가시키며, N + 1번 버튼은 모든 버튼의 카운터를 최댓값으로 초기화시킨다.
이때, M(M <= 10^6)회 버튼을 누른 후 각 버튼의 카운터를 각각 출력한다.

해결 방법 : 맵에 각 버튼을 누른 횟수를 담고 카운터를 올려 나가다가 N + 1번 버튼이 나올 때 마다
누른 모든 버튼을 확인하면서 가장 많이 누른 횟수를 현재의 초기값에 더한다.
그리고 맵을 초기화해둔다. 이를 반복한 다음, 각 버튼을 누른 횟수 + 초기값을 각 버튼에 대해 출력하면 된다.

주요 알고리즘 : 자료 구조, 맵

출처 : JPOI 2012 2-1번
*/

map<int, int> mp;
int res[1048576];

int main(void) {
    int n, m, x, hist = 0, biggest;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        if (x > n) {
            if (mp.size() == 0) continue;
            else {
                biggest = 0;
                for (auto& j : mp) {
                    if (j.second > biggest) biggest = j.second;
                }
                hist += biggest;
            }
            mp.clear();
        }
        else {
            if (mp.find(x) == mp.end()) mp.insert({ x, 1 });
            else mp[x]++;
        }
    }
    for (auto& i : mp) res[i.first] = i.second;
    for (int i = 1; i <= n; i++) {
        printf("%d ", res[i] + hist);
    }
    return 0;
}