#include <stdio.h>
#include <unordered_map>
using namespace std;

/*
문제 : N(N <= 10^6)개의 차례로 놓인 풍선의 높이(<= 10^6, 자연수)가 주어진다. 이때, 왼쪽에서 원하는 높이로
다트를 던지면 그 높이의 첫 풍선이 터지고 그 때 다트의 높이가 1씩 감소한다.
이때, 모든 풍선을 터뜨리기 위해 던져야 하는 다트의 최소 개수를 구한다.

해결 방법 : 왼쪽에 있는 풍선을 터뜨리기 위해서는 그 높이로 우선 던져야 하기 때문에
왼쪽부터 풍선을 터뜨리면 다트의 최소 개수가 된다. 각 다트의 높이 별 개수를 해시맵으로 관리하면서
최종적으로 남은 다트의 개수를 구하면 답이 된다.

주요 알고리즘 : 그리디 알고리즘, 해시맵

출처 : COCI 15/16#1 3번
*/

unordered_map<int, int> m;

int main(void) {
    int n, h, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h);
        if (m.find(h) != m.end() && m[h] > 0) m[h]--;
        if (m.find(h - 1) != m.end()) m[h - 1]++;
        else m.insert(pair<int, int>(h - 1, 1));
    }
    for (auto i : m) r += i.second;
    printf("%d", r);
    return 0;
}