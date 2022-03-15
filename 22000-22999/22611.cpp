#include <stdio.h>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

/*
���� : ��� �ִ� 10^9���� ������ ���� ��, N(N <= 10000)���� ������ �����Ѵ�.
W. �� �տ������� B����ŭ�� �� ������ A�� �Ҵ��Ѵ�.
D. A�� �Ҵ�� ������ �����Ѵ�.
R. A�� ��ġ�� �Ҵ�� ���� ������ �� ���Ѵ�. ���ٸ� -1�� ����Ѵ�.
�Ҵ�Ǵ� ���� ���� ��ȣ�� ������ 10^9���� �۴�.

�ذ� ��� : �ʰ� �̺� Ž���� �̿��Ѵ�. �� �ϳ����� ������ ������������ ������ �Ҵ�� ��ȣ�� �����ϰ�,
�ٸ� �ʿ��� ��ȣ������ ������ ����� �����Ѵ�.
������ �Ҵ��� ������ 0������ ���� ��ġ�� �̵��� �ݺ��ϸ� �� �������� ���� �ʿ� �߰��� ������.
ã�� ��ġ�� �̺� Ž���� ���� Ȯ���ϰ�, �� �������� ���� ũ�⸦ Ȯ���ذ��� ���� ���� ���� �� ���� �ݺ��Ѵ�.
���� ã�� ĭ�� ���� ������ ���� �����̴�. ����, �� ĭ�� ���ٸ� �ٷ� ���� ĭ���� �Ѿ��.
������ ������ ��ȣ������ ����� ������ ����� ��� ������ �ٸ� �ʿ��� �����Ѵ�.
�׸��� �� ���� ��ȣ�� �����Ѵ�.
�Ҵ��� Ȯ���� ������ ���� �̺� Ž���� ���� ��ġ�� ã�� ������ �´� �� Ȯ���ϰ�,
������ �´� ��츸 �� ��ȣ��, �� �ܿ��� -1�� ����Ѵ�.

�ֿ� �˰��� : �ڷ� ����, ��, �ؽø�, �̺� Ž��

��ó : JDC 2009 D��
*/

map<int, pair<int, int>> space; //st, ed, file
unordered_map<int, vector<int>> file;

int main(void) {
    int n, a, b, s;
    char o;
    pair<int, pair<int, int>> node;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2009D\\D\\D1", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2009D\\D\\D1_t.out", "w", stdout);
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf(" %c", &o);
            if (o == 'W') {
                scanf("%d %d", &a, &b);
                s = 0;
                while (b > 0) {
                    if (space.lower_bound(s) == space.end()) {
                        space.insert({ s, {s + b - 1, a} });
                        if (file.find(a) != file.end()) file[a].push_back(s);
                        else file.insert({ a, {s} });
                        break;
                    }
                    node = *space.lower_bound(s);
                    if (node.first > s) {
                        if (node.first - s > b) {
                            space.insert({ s, {s + b - 1, a} });
                            b = 0;
                        }
                        else {
                            space.insert({ s, {node.first - 1, a} });
                            b -= node.first - s;
                        }
                        if (file.find(a) != file.end()) file[a].push_back(s);
                        else file.insert({ a, {s} });
                    }
                    s = node.second.first + 1;
                }
            }
            if (o == 'D') {
                scanf("%d", &a);
                for (int i : file[a]) {
                    space.erase(i);
                }
                file.erase(a);
            }
            if (o == 'R') {
                scanf("%d", &a);
                if (space.size() == 0) {
                    printf("-1\n");
                    continue;
                }
                if (space.upper_bound(a) != space.begin() &&
                    a <= (space.upper_bound(a).operator--())->second.first) {
                    printf("%d\n", (space.upper_bound(a).operator--())->second.second);
                }
                else printf("-1\n");
            }
        }
        printf("\n");
        space.clear();
        file.clear();
    }
    return 0;
}