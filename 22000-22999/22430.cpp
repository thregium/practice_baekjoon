#include <stdio.h>
#include <string>
using namespace std;

/*
���� : ���� 80 ������ ���ڿ��� ��ȣ ���� ����� �־�����. '?'���� ������ ���ĺ����� �ٲ� ����,
�����Ǵ� ��ȣ ��� ���� ���������� ���� ��ȣ�� ����Ѵ�.

�ذ� ��� : ��� '?'���� 'A'�� �ٲٸ� ���������� ���� ���� ��ȣ�� �ȴ�. ��ȣ�� �Ľ��� ����,
�� ������ ���� ���ϸ� �ȴ�. ��, �� �������� ��ȣ ó���� �����Ѵ�. ��ü ������ ��ȣ�� �ο��ִ� ��
���θ� �� Ȯ���ؾ� �Ѵ�. ����, ����Ǵ� ���ĺ��� 'A'�� �Ǿ�� �ϹǷ� �ٷ� 'A'�� �ٲ㼭�� �� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, �׸��� �˰���, ���

��ó : JAG 2014D C��
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