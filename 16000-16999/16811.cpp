#include <stdio.h>
#include <tuple>
#include <set>
using namespace std;

/*
문제 : A * B * C(A, B, C <= 10^8) 크기의 직육면체에서 N(N <= 1000)개의 서로 다른 1 * 1 * 1 크기
블록들을 빼냈다. 이 입체의 겉넓이를 구한다. 어떤 형태로 입체가 만들어지든 블록이 있는 곳과
있지 않은 곳이 인접한 면은 전부 겉넓이에 포함된다.

해결 방법 : 블록을 빼내면 겉넓이에 영향을 받는 곳은 주위 6칸뿐이다.
따라서, 처음 상태의 겉넓이((a * b + a * c + b * c) * 2)에서 시작하여 겉넓이의 변화를 추적해 나간다.
블록을 빼낼 때 마다 바뀌는 겉넓이는 (주위 블록 수 * 2) - 6만큼이다.
주위에 있는 블록들은 빼낸 블록인지 여부만 셋에 저장하면 블록이 있는 칸인지 빈 칸인지를 간단히 알 수 있다.
N개의 블록에 대해 이를 반복한 후 답을 출력하면 된다.

주요 알고리즘 : 자료 구조, 셋, 기하학

출처 : JAG 2015S4 G번
*/

set<tuple<int, int, int>> st;
int dxyz[6][3] = { {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}, {0, -1, 0}, {-1, 0, 0} };

int main(void) {
    int n, x, y, z, xt, yt, zt, cnt;
    long long a, b, c, r;
    scanf("%lld %lld %lld %d", &a, &b, &c, &n);
    r = (a * b + a * c + b * c) * 2;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &x, &y, &z);
        cnt = 0;
        for (int j = 0; j < 6; j++) {
            xt = x + dxyz[j][0];
            yt = y + dxyz[j][1];
            zt = z + dxyz[j][2];
            if (xt < 0 || yt < 0 || zt < 0 || xt >= a || yt >= b || zt >= c) continue;
            if (st.find(make_tuple(xt, yt, zt)) != st.end()) continue;
            cnt++;
        }
        r += cnt * 2 - 6;
        st.insert(make_tuple(x, y, z));
    }
    printf("%lld\n", r);
    return 0;
}