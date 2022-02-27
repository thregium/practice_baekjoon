#include <stdio.h>
#include <string>
#include <set>
#include <map>
using namespace std;

/*
문제 : N(N <= 100)개의 그룹이 있다. 각 그룹은 최대 100명으로 이루어져 있고, 각 사람은 최대 100자 이하의
소문자 이름을 갖는다. 이때, M(M <= 100)개의 쿼리에 응답한다.
0. 그룹 이름이 주어지면 각 사람 이름을 사전순으로 출력한다.
1. 사람 이름이 주어지면 그 사람의 그룹 이름을 출력한다.

해결 방법 : 각 그룹마다의 구성원들을 맵-셋의 형태로 저장하고, 각 사람마다 그룹 이름도 맵에 저장한다.
둘 중 하나가 주어지면 나머지 하나를 맵에서 꺼내와 출력하면 된다.

주요 알고리즘 : 자료 구조, 맵, 셋

출처 : 숭실대/중앙대 2018 A번
*/

map<string, set<string>> group;
map<string, string> member;
char buff[128];

int main(void) {
    int n, m, c;
    string gg, mb;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        gg.assign(buff);
        group.insert(make_pair(gg, set<string>()));
        scanf("%d", &c);
        for (int j = 0; j < c; j++) {
            scanf("%s", buff);
            mb.assign(buff);
            group[gg].insert(mb);
            member.insert(make_pair(mb, gg));
        }
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", buff);
        gg.assign(buff);
        scanf("%d", &c);
        if (c) printf("%s\n", member[gg].c_str());
        else {
            for (string i : group[gg]) {
                printf("%s\n", i.c_str());
            }
        }
    }
    return 0;
}