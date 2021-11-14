#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_set>
using namespace std;

/*
문제 : 1000자 이하의 문자열이 주어질 때, 서로 다른 부분 문자열의 개수를 구한다.

해결 방법 : 모든 부분 문자열들을 확인하며 아직 나오지 않은 부분 문자열들을 해시셋에 넣는다.
모두 확인한 후 해시셋의 크기가 답이 된다.

주요 알고리즘 : 자료 구조, 해시셋, 문자열
*/

char s[1024], buff[1024];
unordered_set<string> us;

int main(void) {
    string st;
    scanf("%s", &s);
    while (s[0]) {
        for (int i = 0; s[i]; i++) {
            strcpy(buff, &s[i]);
            st.assign(buff);
            if (us.find(st) == us.end()) us.insert(st);
        }
        s[strlen(s) - 1] = '\0';
    }
    printf("%d", us.size());
    return 0;
}