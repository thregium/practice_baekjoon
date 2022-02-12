#include <stdio.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*
���� : N(N <= 200)���� ���(30��)�� ���� ��ǰ�, M(M <= 200)���� ������ �־��� ��,
�� ������ ������� �������� �� �� ���� �� ���Ѵ�. ��� ��ǰ� ������ A�� B���� ���ڴٷ� �־�����.
����Ǵ� ����� �־����� �ʴ´�.

�ذ� ��� : �� ����� ��������, �� ��ǵ��� �� ���� �������� ���ϴ� �������� �����,
�� ���忡 ���� ù ��󿡼� �÷����ʷ� �� ��° ��� �����ϴ� �� ���Ѵ�. �� ��� ����̴�.
���⼭ ������ ���� ������ ���� �� ��° ��� �����ϴ� ��� �����̴�.
�Ѵ� �ƴ϶�� ���� ���θ� �� �� ����.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, �ؽø�, �ؽü�

��ó : GCPC 2017 D��
*/

char buff[64], buff2[64];
unordered_map<string, unordered_set<string>> ed, edr;
unordered_set<string> vis;

int dfs1(string s, string t) {
    int r = 0;
    vis.insert(s);
    if (s == t) return 1;
    for (auto i : ed[s]) {
        if (vis.find(i) != vis.end()) continue;
        r |= dfs1(i, t);
    }
    return r;
}
int dfs2(string s, string t) {
    int r = 0;
    vis.insert(s);
    if (s == t) return 2;
    for (auto i : edr[s]) {
        if (vis.find(i) != vis.end()) continue;
        r |= dfs2(i, t);
    }
    return r;
}

int main(void) {
    int n, m, r;
    string s, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s are worse than %s", buff, buff2);
        s.assign(buff);
        t.assign(buff2);
        if (ed.find(s) == ed.end()) {
            ed.insert(make_pair(s, unordered_set<string>()));
        }
        ed[s].insert(t);
        if (edr.find(t) == edr.end()) {
            edr.insert(make_pair(t, unordered_set<string>()));
        }
        edr[t].insert(s);
    }
    for (int i = 0; i < m; i++) {
        scanf("%s are worse than %s", buff, buff2);
        s.assign(buff);
        t.assign(buff2);
        r = 0;
        if (ed.find(s) != ed.end()) {
            if (dfs1(s, t)) {
                printf("Fact\n");
                r += 1;
            }
            vis.clear();
        }
        if (edr.find(s) != edr.end()) {
            if (dfs2(s, t)) {
                printf("Alternative Fact\n");
                r += 2;
            }
            vis.clear();
        }
        if (!r) printf("Pants on Fire\n");
        if (r == 3) return 1;
    }
    return 0;
}