#include <stdio.h>
#include <unordered_map>
#include <queue>
using namespace std;

/*
문제 : 두 물통의 용량 A, B와 목표 용량 C, D(A, B, C, D <= 100000)가 주어진다. 처음에 물통은 전부 빈 상태이고,
각 행동마다 물통 하나를 채우거나 비우거나 둘 중 하나가 차거나 빌 때 까지 한 물통의 물을 다른 물통에 옮길 수 있다.
이때, 물통의 물을 목표량으로 몲길 수 있는지 확인하고 가능하다면 필요한 최소 행동 횟수를 구한다.

해결 방법 : 가능한 상태의 수는 많아야 A + B가지이기 때문에 해싱을 이용한 BFS로 물을 채우는 것이 가능해진다.

주요 알고리즘 : 그래프 이론, BFS, 해시맵

출처 : 정올 2017 고1번
*/

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int, int>, int, hash_pair> dist;
queue<pair<int, int>> q;

int small(int a, int b) {
    return a < b ? a : b;
}

void bfs(int a, int b) {
    int x, y, d;
    q.push(pair<int, int>(0, 0));
    dist.insert(pair<pair<int, int>, int>(pair<int, int>(0, 0), 0));
    while (q.size()) {
        x = q.front().first;
        y = q.front().second;
        d = dist.find(pair<int, int>(x, y))->second;
        q.pop();
        
        if (dist.find(pair<int, int>(a, y)) == dist.end()) {
            dist.insert(pair<pair<int, int>, int>(pair<int, int>(a, y), d + 1));
            q.push(pair<int, int>(a, y));
        }
        if (dist.find(pair<int, int>(x, b)) == dist.end()) {
            dist.insert(pair<pair<int, int>, int>(pair<int, int>(x, b), d + 1));
            q.push(pair<int, int>(x, b));
        }
        if (dist.find(pair<int, int>(0, y)) == dist.end()) {
            dist.insert(pair<pair<int, int>, int>(pair<int, int>(0, y), d + 1));
            q.push(pair<int, int>(0, y));
        }
        if (dist.find(pair<int, int>(x, 0)) == dist.end()) {
            dist.insert(pair<pair<int, int>, int>(pair<int, int>(x, 0), d + 1));
            q.push(pair<int, int>(x, 0));
        }
        if (dist.find(pair<int, int>(x + small(a - x, y), y - small(a - x, y))) == dist.end()) {
            dist.insert(pair<pair<int, int>, int>(pair<int, int>(x + small(a - x, y), y - small(a - x, y)), d + 1));
            q.push(pair<int, int>(x + small(a - x, y), y - small(a - x, y)));
        }
        if (dist.find(pair<int, int>(x - small(x, b - y), y + small(x, b - y))) == dist.end()) {
            dist.insert(pair<pair<int, int>, int>(pair<int, int>(x - small(x, b - y), y + small(x, b - y)), d + 1));
            q.push(pair<int, int>(x - small(x, b - y), y + small(x, b - y)));
        }
        
    }
}

int main(void) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    bfs(a, b);
    if (dist.find(pair<int, int>(c, d)) == dist.end()) printf("-1");
    else printf("%d", dist.find(pair<int, int>(c, d))->second);
    return 0;
}