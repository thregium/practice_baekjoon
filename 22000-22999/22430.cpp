#include <stdio.h>
#include <string>
using namespace std;

/*
문제 : 길이 80 이하의 문자열로 암호 생성 방법이 주어진다. '?'들을 적당한 알파벳으로 바꾼 다음,
생성되는 암호 가운데 가장 사전순으로 빠른 암호를 출력한다.

해결 방법 : 모든 '?'들을 'A'로 바꾸면 사전순으로 가장 빠른 암호가 된다. 암호를 파싱한 다음,
이 방법대로 답을 구하면 된다. 단, 이 과정에서 괄호 처리에 유의한다. 전체 구간의 괄호에 싸여있는 지
여부를 잘 확인해야 한다. 또한, 적용되는 알파벳이 'A'가 되어야 하므로 바로 'A'로 바꿔서는 안 된다.

주요 알고리즘 : 문자열, 파싱, 그리디 알고리즘, 재귀

출처 : JAG 2014D C번
*/

char s[128];

string getres(string s) {
    int lv = 0, lp = -1, off = 0, par = 1;
    string res = "", rev = "";
    for (int i = 0; i < (int)s.size() - 1; i++) {
        if (s[i] == '[') lv++;
        if (s[i] == ']') lv--;
        if (lv == 0) par = 0;
    }
    if (s.size() < 2) par = 0;
    lv = 0;
    for (int i = 0; i < s.size(); i++) {
        if (par) {
            if (i == 0 || i + 1 == s.size()) continue;
        }
        if (s[i] == '[') {
            if (lv == 0) lp = i;
            lv++;
        }
        else if (s[i] == ']') {
            lv--;
            if (lv == 0) res += getres(s.substr(lp, i - lp + 1));
        }
        else if (lv) continue;
        else if (s[i] == '+') off++;
        else if (s[i] == '-') off--;
        else if (s[i] == '?') {
            res += 'A';
            off = 0;
        }
        else {
            res += ((s[i] - 'A') + off + 2600) % 26 + 'A';
            off = 0;
        }
    }
    if (par) {
        for (int i = (int)res.size() - 1; i >= 0; i--) {
            rev += res[i];
        }
        return rev;
    }
    else return res;
}

int main(void) {
    string res;
    while (1) {
        scanf("%s", s);
        if (s[0] == '.') break;
        res.assign(s);
        res = getres(res);
        printf("%s\n", res.c_str());
    }
    return 0;
}