#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

/*
문제 : 4000자 이하의 소문자로 이루어진 두 문자열이 주어질 때, 두 문자열의 가장 긴
히든 아나그램의 길이를 구한다. 히든 아나그램은 부분 문자열 가운데 서로 아나그램 관계인 것이다.

해결 방법 : 각 길이마다 해당 길이의 모든 부분 문자열에서 각 알파벳의 개수를 담은 배열을
셋에 저장한 다음, 두 번째 문자열에 대해 같은 방식의 배열이 매번 있는 지 검사한다.
한 번이라도 있는 경우 그 길이의 문자열에 히든 아나그램이 있는 것이다.
이를 모든 길이에 대해 검사하고, 가장 큰 답을 구하면 된다.

주요 알고리즘 : 문자열, 브루트 포스, 셋

출처 : Tsukuba 2016 D번
*/

char s1[4096], s2[4096];
set<vector<int>> st;

int hashana(int lena, int len1, int len2) {
    vector<int> tcnt;
    st.clear();
    for (int i = 0; i < 26; i++) tcnt.push_back(0);
    for (int i = 0; i < lena; i++) {
        tcnt[s1[i] - 'a']++;
    }
    st.insert(tcnt);
    for (int i = lena; i < len1; i++) {
        tcnt[s1[i] - 'a']++;
        tcnt[s1[i - lena] - 'a']--;
        st.insert(tcnt);
    }
    for (int i = 0; i < 26; i++) tcnt[i] = 0;
    for (int i = 0; i < lena; i++) {
        tcnt[s2[i] - 'a']++;
    }
    if (st.find(tcnt) != st.end()) return 1;
    for (int i = lena; i < len2; i++) {
        tcnt[s2[i] - 'a']++;
        tcnt[s2[i - lena] - 'a']--;
        if (st.find(tcnt) != st.end()) return 1;
    }

    return 0;
}

int main(void) {
    int len1, len2, res = 0;
    scanf("%s%s", s1, s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    for (int i = 0; i <= len1 && i <= len2; i++) {
        if (hashana(i, len1, len2)) res = i;
    }
    printf("%d\n", res);
    return 0;
}