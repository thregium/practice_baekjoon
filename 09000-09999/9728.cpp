#include <stdio.h>
#include <unordered_set>
using namespace std;

/*
문제 : N(N <= 20000)개의 서로 다른 자연수(<= 10^9)가 주어질 때, 합이 M(M <= 10^9)이 되는
수 쌍의 개수를 구한다.

해결 방법 : 해시셋에 수들을 넣어가면서 M - 현재 수가 해시셋에 있다면 결괏값을 1씩 늘려나간다.
그 후 해시셋에 현재 수를 집어넣는다. 이를 반복하여 나온 결괏값을 출력하면 된다.

주요 알고리즘 : 자료 구조, 해시셋

출처 : Khwarizmi 2010 F번
*/

unordered_set<int> st;

int main(void) {
    int t, n, m, x, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %d", &n, &m);
        st.clear();
        r = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            if (st.find(m - x) != st.end()) r++;
            st.insert(x);
        }
        printf("Case #%d: %d\n", tt, r);
    }
    return 0;
}