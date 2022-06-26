#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/*
���� : ���ȸ�ü�� �־��� 8���� �������� ĥ�� �� ������ �������� ��츦 �����ϰ�
ĥ�ϴ� ����� ���� �������� ���Ѵ�.

�ذ� ��� : ���ȸ�ü�� ������ ��� ����� ���� �ϵ��ڵ��� ��, �� ���� ��� ������ ����
���� ������ �������� ��찡 ������ ���� ��츦 ���� ���� �ȴ�.
�׷��� ��찡 ���� �� ���� �¿� �� ��츦 ������ ��츦 �߰��� ������.
��� ������ Ȯ���� �� �� ������ ����ϸ� ���� �ȴ�.

�ֿ� �˰��� : ������, 3���� ������, ��, ���Ʈ ����

��ó : JAG 2009S3 E��
*/

char buff[32];
char colors[16][32];
int ccnt = 0;
vector<int> cnum(8);
set<vector<int>> st;

const int octa[24][8] = {
    {0, 1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 0, 5, 6, 7, 4}, {2, 3, 0, 1, 6, 7, 4, 5}, {3, 0, 1, 2, 7, 4, 5, 6},
    {4, 7, 6, 5, 0, 3, 2, 1}, {7, 6, 5, 4, 3, 2, 1, 0}, {6, 5, 4, 7, 2, 1, 0, 3}, {5, 4, 7, 6, 1, 0, 3, 2},
    {0, 4, 5, 1, 3, 7, 6, 2}, {4, 5, 1, 0, 7, 6, 2, 3}, {5, 1, 0, 4, 6, 2, 3, 7}, {1, 0, 4, 5, 2, 3, 7, 6},
    {3, 2, 6, 7, 0, 1, 5, 4}, {2, 6, 7, 3, 1, 5, 4, 0}, {6, 7, 3, 2, 5, 4, 0, 1}, {7, 3, 2, 6, 4, 0, 1, 5},
    {0, 3, 7, 4, 1, 2, 6, 5}, {3, 7, 4, 0, 2, 6, 5, 1}, {7, 4, 0, 3, 6, 5, 1, 2}, {4, 0, 3, 7, 5, 1, 2, 6},
    {1, 5, 6, 2, 0, 4, 7, 3}, {5, 6, 2, 1, 4, 7, 3, 0}, {6, 2, 1, 5, 7, 3, 0, 4}, {2, 1, 5, 6, 3, 0, 4, 7}
};

int main(void) {
    int res, ok;
    vector<int> v(8);
    while (1) {
        st.clear();
        ccnt = 0;
        for (int i = 0; i < 8; i++) {
            if (scanf("%s", buff) == EOF) return 0;
            cnum[i] = -1;
            for (int j = 0; j < ccnt; j++) {
                if (!strcmp(colors[j], buff)) {
                    cnum[i] = j;
                    break;
                }
            }
            if (cnum[i] < 0) {
                strcpy(colors[ccnt], buff);
                cnum[i] = ccnt++;
            }
        }

        for (int i = 0; i < 24; i++) {
            for (int j = 0; j < 8; j++) v[j] = cnum[octa[i][j]];
            if (st.find(v) == st.end()) st.insert(v);
        }
        res = 1;
        while (next_permutation(cnum.begin(), cnum.end())) {
            ok = 1;
            for (int i = 0; i < 24; i++) {
                for (int j = 0; j < 8; j++) v[j] = cnum[octa[i][j]];
                if (st.find(v) != st.end()) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) continue;
            for (int i = 0; i < 24; i++) {
                for (int j = 0; j < 8; j++) v[j] = cnum[octa[i][j]];
                if (st.find(v) == st.end()) st.insert(v);
            }
            res++;
        }
        printf("%d\n", res);
    }
    return 0;
}