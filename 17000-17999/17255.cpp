#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

/*
문제 : 10^7 이하의 음이 아닌 정수 N이 주어질 때, 한 자리씩 인접한 수들을 추가해가며 N을 만드는 방법의 가짓수를 구한다.
자리를 추가하는 순서가 다르더라도 추가하는 수가 같다면 같은 경우이다.

해결 방법 : 벡터와 셋을 이용해 추가하는 순서들을 관리한다. 최대 7자리이므로 수들을 추가하는 방법은 많아야 7!가지일
것이므로 브루트 포스를 이용해 풀 수 있다. 각 자리에서 시작해서 앞과 뒤 자리의 위치와 현재 수를 관리하며 풀면 된다.
답은 셋의 크기가 된다.

주요 알고리즘 : 브루트 포스, 셋

출처 : 전북대 2019 L번
*/

char n[16];
int l;
set<vector<int>> st;
vector<int> v;

void track(int s, int e, int b, int x, int nn) {
    if (x == l) {
        if (st.find(v) == st.end()) st.insert(v);
        return;
    }
    v[x] = nn;
    if (s > 0) {
        track(s - 1, e, b * 10, x + 1, nn + b * 10 * (n[s - 1] - '0'));
    }
    if (e < l - 1) {
        track(s, e + 1, b * 10, x + 1, nn * 10 + (n[e + 1] - '0'));
    }
}

int main(void) {
    int a, b;
    scanf("%s", n);
    l = strlen(n);
    for (int i = 0; i < l; i++) v.push_back(0);
    for (int i = 0; i < l; i++) {
        track(i, i, 1, 1, n[i] - '0');
    }
    printf("%d", st.size());
    return 0;
}