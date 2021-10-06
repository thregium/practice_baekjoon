#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define FOUT 0
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)
using namespace std;

/*
문제 : N(N <= 1000)개의 세 단어가 주어진다. 이때, 가장 많이 나온 단어 조합의 등장 횟수를 구한다.
순서만 다른 것은 같은 조합이고, 각 단어들은 10자 이하의 대문자이다.

해결 방법 : 각 단어 조합을 셋에 저장한 후, 이들의 등장 횟수와 함께 이 조합을 맵에 저장한다.
만약 맵에 단어 조합이 없으면 등장 횟수를 1로 해서 저장하고, 있다면 해당하는 조합의 등장 횟수를 늘리면서 최댓값을 갱신하면 된다.

주요 알고리즘 : 자료구조, 맵, 셋, 문자열

출처 : USACO 2013D B1번
*/

map<set<string>, int> mp;
char buff[3][16];

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("records.in", "r");
        fo = fopen("records.out", "w");
    }

    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        set<string> st;
        string s;
        scanf("%s %s %s", buff[0], buff[1], buff[2]);
        for (int j = 0; j < 3; j++) {
            s.assign(buff[j]);
            st.insert(s);
        }
        if (mp.find(st) == mp.end()) {
            mp.insert(pair<set<string>, int>(st, 1));
        }
        else {
            (mp.find(st)->second)++;
            if (mp.find(st)->second > r) r = mp.find(st)->second;
        }
    }

    printf("%d", r);
    return 0;
}