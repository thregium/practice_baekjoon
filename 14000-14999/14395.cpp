#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#define MX 1000000000
using namespace std;

/*
문제 : 10억 이하의 두 자연수 S와 T가 주어질 때, 다음 연산을 통해 S에서 T로 이동이 가능한지 구하고, 가능한 경우에는
가장 이동 횟수가 적은 것 가운데 사전순으로 가장 앞선 연산 과정을 출력한다.
1. x * x, 2. x + x, 3. x - x, 4. x / x

해결 방법 : BFS를 통해 S에서 각 수로의 이동 거리와 이동 과정을 추적한다. 큐와 맵에 이동 과정을 같이 넣으면 된다.
그와 함께 위 순서대로 식들을 적용해 보며 이미 방문한 경우를 제외한 가장 빠른 연산 가운데 가장 앞선 연산이
같이 이동 과정에 들어가게 된다. 따라서, T가 나오면 답과 같은 값이 나오게 되는 것이다.
맵에 T가 없다면 그러한 과정이 없는 것이다. 값이 증가하는 연산이 최소 2배 이상의 값으로 변하기 때문에
S와 T의 범위가 매우 크지만 빠른 시간 내에 끝낼 수 있다. 중간값이 10억을 넘어가는 경우는 볼 필요가 없기 때문이다.

주요 알고리즘 : 그래프 이론, BFS, 역추적?
*/

queue<pair<int, string>> q;
map<int, string> mp;

void bfs(int s, int e) {
    int x;
    string ss;
    ss.assign("");
    q.push(pair<int, string>(s, ss));
    mp.insert(pair<int, string>(s, ss));
    while (q.size()) {
        x = q.front().first;
        ss = q.front().second;
        q.pop();
        if (x == e) return;
        
        if ((long long)x * x <= MX && mp.find(x * x) == mp.end()) {
            q.push(pair<int, string>(x * x, ss + "*"));
            mp.insert(pair<int, string>(x * x, ss + "*"));
        }
        if (x + x <= MX && mp.find(x + x) == mp.end()) {
            q.push(pair<int, string>(x + x, ss + "+"));
            mp.insert(pair<int, string>(x + x, ss + "+"));
        }
        if (mp.find(0) == mp.end()) {
            q.push(pair<int, string>(0, ss + "-"));
            mp.insert(pair<int, string>(0, ss + "-"));
        }
        if (mp.find(1) == mp.end()) {
            q.push(pair<int, string>(1, ss + "/"));
            mp.insert(pair<int, string>(1, ss + "/"));
        }
    }
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == b) {
        printf("0");
        return 0;
    }
    bfs(a, b);
    if (mp.find(b) == mp.end()) printf("-1");
    else printf("%s", (mp.find(b)->second).c_str());
    return 0;
}