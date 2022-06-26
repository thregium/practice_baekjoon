#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

/*
문제 : 정팔면체를 주어진 8개의 색상으로 칠할 때 돌려서 같아지는 경우를 제외하고
칠하는 경우의 수의 가짓수를 구한다.

해결 방법 : 정팔면체를 돌리는 모든 경우의 수를 하드코딩한 후, 각 색의 모든 순열에 대해
아직 돌려서 같아지는 경우가 나오지 않은 경우를 전부 세면 된다.
그러한 경우가 나올 때 마다 셋에 그 경우를 돌리는 경우를 추가해 나간다.
모든 순열을 확인한 후 센 개수를 출력하면 답이 된다.

주요 알고리즘 : 기하학, 3차원 기하학, 셋, 브루트 포스

출처 : JAG 2009S3 E번
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