#include <stdio.h>
#include <string>
#include <unordered_set>
using namespace std;

/*
문제 : N(N <= 100000)번의 끝말잇기에서 말한 단어가 주어질 때, 누가 이겼는 지 또는 계속 진행중인 지 구한다.
각 단어는 120자 이하의 소문자로 이루어져 있고, 이미 사용한 단어를 사용하면 진다.

해결 방법 : 해시셋을 이용해 이미 사용한 단어를 관리하고, 마지막 문자와 함께 확인하며
현재 단어가 쓸 수 있는 단어인 지 확인한다. 쓸 수 없는 단어를 사용하는 사람이 있다면 그 사람을
지는 것으로 처리하면 되고, 없다면 계속 진행하게 된다.

주요 알고리즘 : 문자열, 해시셋, 구현

출처 : VTH 2017 A번
*/

char buff[128];
unordered_set<string> wd;

int main(void) {
    int n;
    char last;
    string s;
    scanf("%d", &n);
    scanf("%s", buff);
    s.assign(buff);
    wd.insert(buff);
    last = s[s.length() - 1];
    for (int i = 1; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        if (wd.find(s) != wd.end() || buff[0] != last) {
            if (i & 1) printf("Player 2 lost");
            else printf("Player 1 lost");
            return 0;
        }
        else wd.insert(s);
        last = s[s.length() - 1];
    }
    printf("Fair Game");
    return 0;
}