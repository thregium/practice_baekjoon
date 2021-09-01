#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

/*
���� : 10^6�� ������ ���ڿ����� �־��� ��, ���ڿ����� �����ϰ� �� ���ڿ����� ������ ������ ����� ���·� ����Ѵ�.

�ذ� ��� : ���� �̿��� �� ���ڿ����� ���� Ƚ���� ���� �����Ѵ�. �� ����, ��� ���ڿ����� �Է��� ������
���� ��ȸ�ϸ� �� ���ڿ����� ���� ������ ����� ���ϸ� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ��

��ó : Waterloo 20020126 C��
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