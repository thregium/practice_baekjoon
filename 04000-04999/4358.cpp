#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

/*
문제 : 10^6개 이하의 문자열들이 주어질 때, 문자열들을 정렬하고 각 문자열들이 등장한 비율을 백분율 형태로 출력한다.

해결 방법 : 맵을 이용해 각 문자열들의 등장 횟수를 같이 보관한다. 그 다음, 모든 문자열들의 입력이 끝나면
맵을 순회하며 각 문자열들의 등장 비율을 계산해 구하면 된다.

주요 알고리즘 : 자료구조, 맵

출처 : Waterloo 20020126 C번
*/

char s[64];
map<string, int> mp;

int main(void) {
    int n = 0;
    string st;
    while (fgets(s, 50, stdin)) {
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        st.assign(s);
        if (mp.find(st) != mp.end()) (mp.find(st)->second)++;
        else mp.insert(pair<string, int>(st, 1));
        n++;
        //if (n == 29) break;
    }
    for (auto i = mp.begin(); i != mp.end(); i++) {
        printf("%s %.4f\n", i->first.c_str(), (double)(i->second) / n * 100.0);
    }
    return 0;
}