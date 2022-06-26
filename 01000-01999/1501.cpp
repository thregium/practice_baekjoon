#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

/*
문제 : N(N <= 10000)개의 단어와 M(M <= 10000)개의 문장이 주어질 때, 모든 문장에 대해
가능한 해석의 가짓수를 각각 구한다. 각 단어는 시작점과 끝점이 같다면 중간 글자들의 순서를 마음대로
바꾸어 해석 가능하다. 단, 해석된 단어는 단어장에 있는 것이어야 한다.

해결 방법 : 각 단어의 중간 글자들의 각 개수와 맨 앞, 뒤 글자를 벡터에 넣고 맵에 다시 넣어
각 경우에 따른 개수를 저장한다.
다시 문장들을 입력받으면 문장을 단어 단위로 바꾼 후 각 단어 별로 가능한 해석의 가짓수를 전부 곱하고,
그 답을 출력하면 된다.

주요 알고리즘 : 문자열, 자료 구조, 맵

출처 : TUD 2005 7번
*/

char buff[10240], s[128];
map<vector<int>, int> mp;

int main(void) {
    int n, m, r;
    char* ss;
    vector<int> v;
    for (int i = 0; i < 130; i++) v.push_back(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        v[128] = s[0];
        v[129] = s[strlen(s) - 1];
        for (int j = 0; j < 128; j++) v[j] = 0;
        for (int j = 0; s[j]; j++) {
            v[s[j]]++;
        }

        if (mp.find(v) == mp.end()) mp.insert({ v, 1 });
        else mp[v]++;
    }
    scanf("%d\n", &m);
    for (int i = 0; i < m; i++) {
        fgets(buff, 10130, stdin);
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        
        r = 1;
        ss = strtok(buff, " ");
        while (ss) {
            v[128] = ss[0];
            v[129] = ss[strlen(ss) - 1];
            for (int j = 0; j < 128; j++) v[j] = 0;
            for (int j = 0; ss[j]; j++) {
                v[ss[j]]++;
            }
            if (mp.find(v) == mp.end()) r = 0;
            else r *= mp[v];

            ss = strtok(NULL, " ");
        }
        printf("%d\n", r);
    }
    return 0;
}