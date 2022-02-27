#include <stdio.h>
#include <string>
#include <set>
#include <map>
using namespace std;

/*
���� : N(N <= 100)���� �׷��� �ִ�. �� �׷��� �ִ� 100������ �̷���� �ְ�, �� ����� �ִ� 100�� ������
�ҹ��� �̸��� ���´�. �̶�, M(M <= 100)���� ������ �����Ѵ�.
0. �׷� �̸��� �־����� �� ��� �̸��� ���������� ����Ѵ�.
1. ��� �̸��� �־����� �� ����� �׷� �̸��� ����Ѵ�.

�ذ� ��� : �� �׷츶���� ���������� ��-���� ���·� �����ϰ�, �� ������� �׷� �̸��� �ʿ� �����Ѵ�.
�� �� �ϳ��� �־����� ������ �ϳ��� �ʿ��� ������ ����ϸ� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, ��, ��

��ó : ���Ǵ�/�߾Ӵ� 2018 A��
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