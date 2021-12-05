#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

/*
���� : 60�� ������ ���ǰ� �� ������ ��ȯ�� �־�����. ! x a = y b�� �� ������ ��ȯ�� x : y��� ���� �˷��ְ�,
? a = b�� a�� b�� ��ȯ�� ã�ƾ� �Ѵ�. ��ȯ�� ���� ��� ? a = ? b�� ����ϰ�, �ִٸ� x a = y b�� ����Ѵ�.
�̶� x�� y�� ���μҿ��� �Ѵ�. ���� ���������� ��ȯ ������ ��쵵 ��ȯ�� �ִ� ���̴�.
�� ������ 20�� ������ �ҹ��ڷ� �̷���� �ְ�, �Է��� x�� y�� 100 ���ϰ�, ����� x�� y�� 10000 ���ϴ�.
���� ����� ��ȯ��� �־����� �ʴ´�.

�ذ� ��� : �� ���� ������ ��ȯ�� �������� ���� ����, �Ź� ?�� ���� �� ���� a���� ����ؼ� b�� ã�Ƴ�����.
b�� ���ϴ� ��ȯ�� �Ź� ���ذ��� �ִ������� ��� ������ �ȴ�.
b�� ������ ��� �׶��� �� ���� ����ϸ� �ǰ�, ������ �ʴ´ٸ� ? a = ? b�� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, ��Ŭ���� ȣ����

��ó : MidC 1999 C��
*/

char buff1[32], buff2[32];
unordered_map<string, vector<tuple<string, int, int>>> ed;
unordered_set<string> vis;
long long res1, res2;

long long gcd(long long a, long long b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return a > b ? gcd(a % b, b) : gcd(a, b % a);
}

void dfs(string s, string e, long long x, long long y) {
    long long g = gcd(x, y);
    x /= g;
    y /= g;
    vis.insert(s);
    if (s == e) {
        res1 = x;
        res2 = y;
    }
    for (auto i : ed[s]) {
        if (vis.find(get<0>(i)) != vis.end()) continue;
        dfs(get<0>(i), e, x * (get<1>(i)), y * (get<2>(i)));
    }
}

int main(void) {
    int a, b;
    char c;
    string s1, s2;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1999\\exchange\\exchange.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc1999\\exchange\\exchange_t.out", "w", stdout);
    while (1) {
        scanf(" %c", &c);
        if (c == '.') break;
        if (c == '!') {
            scanf("%d %s = %d %s", &a, buff1, &b, buff2);
            s1.assign(buff1);
            s2.assign(buff2);
            if (ed.find(s1) == ed.end()) ed.insert(pair<string, vector<tuple<string, int, int>>>(s1, {}));
            if (ed.find(s2) == ed.end()) ed.insert(pair<string, vector<tuple<string, int, int>>>(s2, {}));
            ed[s1].push_back(make_tuple(s2, a, b));
            ed[s2].push_back(make_tuple(s1, b, a));
        }
        else if (c == '?') {
            scanf("%s = %s", buff1, buff2);
            s1.assign(buff1);
            s2.assign(buff2);
            res1 = 0, res2 = 0;
            dfs(s1, s2, 1, 1);
            if (res1 == 0) printf("? %s = ? %s\n", buff1, buff2);
            else printf("%lld %s = %lld %s\n", res1, buff1, res2, buff2);
            vis.clear();
        }
        else return 1;
    }
    return 0;
}