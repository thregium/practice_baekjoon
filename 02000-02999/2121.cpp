#include <stdio.h>
#include <set>
using namespace std;

/*
문제 : N(N <= 500000)개의 점이 좌표평면상에 주어질 때, 점을 이어 만들 수 있는 가로가 A, 세로가 B인
좌표축에 평행한 직사각형의 개수를 구한다.

해결 방법 : 셋에 각 점의 좌표를 넣고, 각 점을 왼쪽 위 꼭짓점으로 하는 직사각형을 만들 수 있는지 살펴본다.
만약 다른 세 점이 모두 셋에 있다면 그러한 직사각형을 만들 수 있다.

주요 알고리즘 : 자료 구조, 셋, 정렬
*/

set<pair<int, int>> st;

int main(void) {
    int n, a, b, x, y, r = 0;
    scanf("%d%d %d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        st.insert(pair<int, int>(x, y));
    }
    for (auto i : st) {
        if (st.find(pair<int, int>(i.first, i.second + b)) != st.end()) {
            if (st.find(pair<int, int>(i.first + a, i.second)) != st.end()) {
                if (st.find(pair<int, int>(i.first + a, i.second + b)) != st.end()) r++;
            }
        }
    }
    printf("%d", r);
    return 0;
}