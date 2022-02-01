#include <stdio.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
���� : K(K <= 50000)���� 3���� ������ �ִ� ������ �糡�� ��ǥ(<= 1000, �ڿ���)�� �־��� ��,
������ ������ �����Ͽ� ����Ŭ�� ������ �� ���ο�
2������ �翵���� �� �׷��� ����Ŭ�� ������ �� ���θ� ���� ���Ѵ�.

�ذ� ��� : �� ������ �������� ����, �� ���� ������ �������� ���� 2������ 3������ �׷����� �����.
�� �׷����� ����Ŭ ���θ� �÷������� ���� Ȯ���ϸ� �ȴ�.
2������ �翵�ϴ� ��� ���� ���� ������ ��찡 ������ �����Ѵ�. ����, ��ǥ�� ������
�� ������ �ؽø�, �ؽü����� �����ϴ� ���� ����.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, �ؽü�, �ؽø�

��ó : SWERC 2016 K��
*/

unordered_map<int, unordered_set<int>> edt;
unordered_map<int, unordered_set<int>> edf;
unordered_set<int> vist, visf;
int r1 = 0, r2 = 0;

void dfs1(int x, int y) {
    if (vist.find(x) != vist.end()) {
        r1 = 1;
        return;
    }
    else vist.insert(x);
    for (int i : edt[x]) {
        if (i == y) continue;
        dfs1(i, x);
    }
}

void dfs2(int x, int y) {
    if (visf.find(x) != visf.end()) {
        r2 = 1;
        return;
    }
    else visf.insert(x);
    for (int i : edf[x]) {
        if (i == y) continue;
        dfs2(i, x);
    }
}

int main(void) {
    int k, x1, y1, z1, x2, y2, z2;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
        if (edt.find((x1 << 20) + (y1 << 10) + z1) == edt.end()) {
            edt.insert(make_pair((x1 << 20) + (y1 << 10) + z1, unordered_set<int>()));
        }
        edt[(x1 << 20) + (y1 << 10) + z1].insert((x2 << 20) + (y2 << 10) + z2);
        if (edt.find((x2 << 20) + (y2 << 10) + z2) == edt.end()) {
            edt.insert(make_pair((x2 << 20) + (y2 << 10) + z2, unordered_set<int>()));
        }
        edt[(x2 << 20) + (y2 << 10) + z2].insert((x1 << 20) + (y1 << 10) + z1);
        if (edf.find((x1 << 10) + y1) == edf.end()) {
            edf.insert(make_pair((x1 << 10) + y1, unordered_set<int>()));
        }
        if ((x1 << 10) + y1 != (x2 << 10) + y2) edf[(x1 << 10) + y1].insert((x2 << 10) + y2);
        if (edf.find((x2 << 10) + y2) == edf.end()) {
            edf.insert(make_pair((x2 << 10) + y2, unordered_set<int>()));
        }
        if ((x2 << 10) + y2 != (x1 << 10) + y1) edf[(x2 << 10) + y2].insert((x1 << 10) + y1);
    }

    for (auto &i : edt) {
        if(vist.find(i.first) == vist.end()) dfs1(i.first, -1);
    }
    for (auto& i : edf) {
        if (visf.find(i.first) == visf.end()) dfs2(i.first, -1);
    }
    printf("%srue closed chains\n", r1 ? "T" : "No t");
    printf("%sloor closed chains", r2 ? "F" : "No f");
    return 0;
}