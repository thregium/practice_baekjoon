#include <stdio.h>
#include <unordered_map>
#include <queue>
using namespace std;

/*
���� : �� ������ �뷮 A, B�� ��ǥ �뷮 C, D(A, B, C, D <= 100000)�� �־�����. ó���� ������ ���� �� �����̰�,
�� �ൿ���� ���� �ϳ��� ä��ų� ���ų� �� �� �ϳ��� ���ų� �� �� ���� �� ������ ���� �ٸ� ���뿡 �ű� �� �ִ�.
�̶�, ������ ���� ��ǥ������ ���� �� �ִ��� Ȯ���ϰ� �����ϴٸ� �ʿ��� �ּ� �ൿ Ƚ���� ���Ѵ�.

�ذ� ��� : ������ ������ ���� ���ƾ� A + B�����̱� ������ �ؽ��� �̿��� BFS�� ���� ä��� ���� ����������.

�ֿ� �˰��� : �׷��� �̷�, BFS, �ؽø�

��ó : ���� 2017 ��1��
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