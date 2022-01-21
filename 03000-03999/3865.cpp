#include <stdio.h>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
���� : N(N <= 100)���� ��ȸ�� �ְ�, �� ��ȸ�� ���� ��ȸ������ �־�����. ��ȸ���� ����� ���� �ְ�,
�ٸ� ��ȸ�� ���� �ִ�. �̶�, ù ��° ��ȸ�� ���� ����� ���� ���Ѵ�. ��ȸ���� ����� �̸���
15�� ������ �ҹ��ڷ� �̷���� ���ڿ��̸�, ��ȸ�� �ƴ϶�� ����̴�.
����, �ϳ��� ��ȸ�� �ִ� 10���� ��ȸ���� ������, ��ȯ���� ���԰��踦 ���� �ʴ´�.

�ذ� ��� : ���� ��ȸ������ ���踦 �Ľ��� ���� ���Ѵ�. �� ��ȸ���� �ش� ��ȸ�� ���ϴ� ��ȸ������
�ؽøʰ� �ؽü��� ���� ������ѵд�. �� ����, ù ��° ��ȸ���� ���ϴ� ��ȸ������ ��������� Ȯ���� ������
�� ��ȸ�� ��ȸ������ ���Ѵ�. ��ȸ�� �ƴ� ��ȸ��(���)�� ���� �� ���� �� ������ �� ����,
�� ���� ����ϸ� �ȴ�. �湮 ó���� ����� �Ѵ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, �ؽø�, �ؽü�, �÷�����

��ó : Tokyo 2010 A��
*/

char buff[1024];
unordered_set<string> vis;
unordered_map<string, unordered_set<string>> u;

int dfs(string s) {
    int r = 0;
    vis.insert(s);
    if (u.find(s) == u.end()) return 1;
    for (string i : u[s]) {
        if (vis.find(i) == vis.end()) r += dfs(i);
    }
    return r;
}

int main(void) {
    int n, p;
    string f, s, t;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        f = "";
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            s = "", t = "", p = 0;
            for (int j = 0; buff[j] != '.'; j++) {
                if (buff[j] == ':') {
                    p = 1;
                    u.insert(make_pair(s, unordered_set<string>()));
                    if (i == 0) f = s;
                    continue;
                }
                else if (buff[j] == ',') {
                    u[s].insert(t);
                    t = "";
                    continue;
                }
                if (p == 0) s += buff[j];
                else t += buff[j];
            }
            u[s].insert(t);
        }

        printf("%d\n", dfs(f));
        vis.clear();
        u.clear();
    }
    return 0;
}