#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
using namespace std;

/*
문제 : 60개 이하의 물건과 각 물건의 교환비가 주어진다. ! x a = y b로 두 물건의 교환비가 x : y라는 것을 알려주고,
? a = b로 a와 b의 교환비를 찾아야 한다. 교환비가 없는 경우 ? a = ? b를 출력하고, 있다면 x a = y b로 출력한다.
이때 x와 y는 서로소여야 한다. 서로 간접적으로 교환 가능한 경우도 교환비가 있는 것이다.
각 물건은 20자 이하의 소문자로 이루어져 있고, 입력의 x와 y는 100 이하고, 출력의 x와 y는 10000 이하다.
서로 모순된 교환비는 주어지지 않는다.

해결 방법 : 각 물건 사이의 교환비를 간선으로 이은 다음, 매번 ?가 나올 때 마다 a에서 출발해서 b를 찾아나간다.
b로 향하는 교환비를 매번 곱해가며 최대공약수를 들고 있으면 된다.
b가 나오는 경우 그때의 두 값을 출력하면 되고, 나오지 않는다면 ? a = ? b를 출력하면 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 유클리드 호제법

출처 : MidC 1999 C번
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