#include <stdio.h>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#define INNER pair<string, tuple<int, int, int, vector<int>, vector<int>, vector<int>>>
using namespace std;

/*
���� : �־��� ���ڿ� �̸��� ���� �迭�鿡 ���� �������� �־��� ��, �� �������� �̿��� ���� �ּҸ� ã�´�.

�ذ� ��� : �� �迭�� �̸��� �������� �ؽø��� ���� �����Ѵ�. �̸� �̿��� 2�������� �������� ����ϰ�,
�Էµ� �̸��� �����鿡 ���� �ش� �迭�� �������� �̿��� ���� �ּҸ� ã�Ƴ����� �ȴ�.

�ֿ� �˰��� : ����, �ؽø�, ����

��ó : MidC 1996 C��
*/

unordered_map<string, tuple<int, int, int, vector<int>, vector<int>, vector<int>>> um; //Base, Byte, D, L, U, C
char s[16];

int main(void) {
    int n, r, x, y;
    string str;
    INNER inner;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM3\\ARRAYMAP.IN", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\midc96\\PROBLEM3\\ARRAYMAP_T.OUT", "w", stdout);
    scanf("%d %d", &n, &r);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        str.assign(s);
        if (um.find(str) != um.end()) return 1;
        inner.first = str;
        scanf("%d", &x);
        get<0>(inner.second) = x;
        scanf("%d", &x);
        get<1>(inner.second) = x;
        scanf("%d", &x);
        get<2>(inner.second) = x;
        for (int j = 0; j < get<2>(inner.second); j++) {
            scanf("%d", &x);
            get<3>(inner.second).push_back(x);
            scanf("%d", &x);
            get<4>(inner.second).push_back(x);
            get<5>(inner.second).push_back(0);
        }
        get<5>(inner.second).push_back(get<1>(inner.second));
        for (int j = get<2>(inner.second) - 1; j > 0; j--) {
            get<5>(inner.second)[j] = get<5>(inner.second)[j + 1] *
                (get<4>(inner.second)[j] - get<3>(inner.second)[j] + 1);
        }
        get<5>(inner.second)[0] = get<0>(inner.second);
        for (int j = 1; j <= get<2>(inner.second); j++) {
            get<5>(inner.second)[0] -= get<3>(inner.second)[j - 1] * get<5>(inner.second)[j];
        }
        um.insert(inner);
        get<3>(inner.second).clear();
        get<4>(inner.second).clear();
        get<5>(inner.second).clear();
    }

    for (int i = 0; i < r; i++) {
        scanf("%s", s);
        str.assign(s);
        printf("%s[", s);
        if (um.find(str) == um.end()) return 2;
        inner = *um.find(str);
        y = get<5>(inner.second)[0];
        for (int j = 0; j < get<2>(inner.second); j++) {
            scanf("%d", &x);
            printf("%d", x);
            if (j < get<2>(inner.second) - 1) printf(", ");
            y += get<5>(inner.second)[j + 1] * x;
        }
        printf("] = %d\n", y);
    }
    return 0;
}