#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

/*
���� : N * M(N, M <= 1000) ũ���� ��Ʈ���� �� ������ ������ 0�� ���� ���� ������ �� �� 0�� ���� ���� ����Ѵ�.

�ذ� ��� : �� ������ ������ ������ ��Ʈ�� ������ ���� �࿡�� �� ���� �������� �� ���� ��Ʈ�� ���� ���̴�.
����, ��Ʈ�� � ���´��� ���� 0���� ����� ���� �����ϰ�, ��Ʈ�� �ٸ� ���̶�� ���� 0�� �ƴ� ���̹Ƿ�
��Ʈ�� ������ ���� ���� ���� ��� ���� ���� ���� ����ϸ� �ǰ�, �̴� multiset�� �̿��� ������ ���� �� �ִ�.

�ֿ� �˰��� : �׸��� �˰���

��ó : AIPO 2016F 3��
*/

multiset<vector<char>> s;

int main(void) {
    int n, m, r = 0;
    char c;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        vector<char> v;
        for (int j = 0; j < m; j++) {
            scanf(" %c", &c);
            v.push_back(c);
        }
        s.insert(v);
        if (s.count(v) > r) r = s.count(v);
    }
    printf("%d", r);
    return 0;
}