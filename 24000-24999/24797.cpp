#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

/*
���� : N(N <= 100000)���� ����� M(M <= 100000)���� �ΰ� ���谡 �־�����. �� ����� �ҹ���
T_i(T_i <= 1000)���Լ� ��� �Ǹ� ���� ������ �ҹ��� �۶߸��� �����Ѵ�.
�̶�, T_i�� 0�� ����� �����ϰ� �� ������� �ҹ��� �۶߸��� �����Ѵٸ� D(D <= 10000)�� �Ŀ���
ó�� �ҹ��� �۶߸� ����� �����ϸ� �� ���� ����� �ҹ��� ��� �Ǵ� �� ���Ѵ�.

�ذ� ��� : BFS�� ���� T_i�� 0�� ������� Ž���� �����Ѵ�. �� ����� T_i���� �ؽø����� �����ϰ�,
�ٸ� �������� ������ �� ���� 1�� �ٿ������� 0�� �Ǹ� ť�� ����ִ� ������� �ϸ� �ȴ�.
�Ÿ��� ���������� �ؽø����� �����ϸ� �Ÿ��� D�� �� �� Ž���� �����ϰ� ���ݱ��� Ž���� ��� ���� Ȯ���Ѵ�.
Ž���� ����� �ؽü����� �����Ѵ�. �� �ؽü��� ũ�� - 1(ó�� �۶߸� ���)�� ���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, BFS, �ؽø�, �ؽü�

��ó : VTH 2017 E��
*/

char buff[32], buff2[32];
unordered_map<string, unordered_set<string>> ed;
unordered_map<string, int> skep, dist;
unordered_set<string> vis;
queue<string> q;

void bfs(string s, int d) {
    q.push(s);
    dist.insert({ s, 0 });
    vis.insert(s);
    while (q.size()) {
        s = q.front();
        q.pop();
        if (dist[s] == d) return;
        for (auto& i : ed[s]) {
            if (vis.find(i) == vis.end()) vis.insert(i);
            skep[i]--;
            if (skep[i] == 0) {
                dist.insert({ i, dist[s] + 1 });
                q.push(i);
            }
        }
    }
}

int main(void) {
    int n, m, d, t;
    string s, s2;
    //freopen("E:\\PS\\High School\\VTH\\2017\\grapevine\\data\\secret\\secret-06.in", "r", stdin);
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", buff, &t);
        s.assign(buff);
        skep.insert({ buff, t });
    }
    for (int i = 0; i < m; i++) {
        scanf("%s %s", buff, buff2);
        s.assign(buff);
        s2.assign(buff2);
        if (ed.find(s) != ed.end()) ed[s].insert(s2);
        else ed.insert({ s, {s2} });
        if (ed.find(s2) != ed.end()) ed[s2].insert(s);
        else ed.insert({ s2, {s} });
    }
    scanf("%s", buff);
    s.assign(buff);
    bfs(s, d);
    printf("%d", (int)vis.size() - 1);
    return 0;
}