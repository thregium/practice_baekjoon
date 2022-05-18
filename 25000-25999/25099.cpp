#include <stdio.h>
#include <vector>;
#include <set>
using namespace std;

/*
문제 : N(N <= 100000)개의 100자 이하 소문자로 이루어진 문자열들이 주어진다.
이때, 문자열이 앞선 문자열의 아나그램 중 하나가 아닌 문자열들만 출력한다.

해결 방법 : 셋에 서로 다른 아나그램마다 각 문자의 개수를 저장하고, 문자열이 입력될 때 마다
현재 문자열의 각 문자 개수가 셋에 저장되었는 지 확인한다. 저장되었다면 넘어가고,
저장되지 않았다면 현재 문자열을 출력하고 그 개수들을 셋에 추가하는 작업을 반복하면 된다.

주요 알고리즘 : 자료구조, 셋, 문자열

출처 : CERC 2021 X번
*/

char s[128];
vector<short> apr;
set<vector<short>> st;

int main(void) {
    int n;
    for (int i = 0; i < 26; i++) apr.push_back(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        for (int i = 0; i < 26; i++) apr[i] = 0;
        for (int j = 0; s[j]; j++) apr[s[j] - 'a']++;
        if (st.find(apr) != st.end()) continue;
        else {
            printf("%s\n", s);
            st.insert(apr);
        }
    }
    return 0;
}