#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
���� : 100000�� ������ ��ǥ���� ���� ��� �̸����� �־��� ��, �����ϰ� ���� ���� ����� �ִ� �� ���ϰ�,
�ִٸ� �� �̸���, ���ٸ� 'Runoff!'�� ����Ѵ�.

�ذ� ��� : �� ����� �̸��� ���� Ƚ���� �ؽøʿ� �����Ѵ�. ������ ���� �̸��� �ִٸ�
�� �̸��� �ؽøʿ� 1ȸ�� �߰��ϰ�, ���� �̸��� �ִٸ� ���� Ƚ���� 1�� �÷� ������.
�̸� �ݺ��� ����, ��� ��� ��� ���� Ƚ���� �ִ��� ã��, ���ÿ� �׿� ���� Ƚ���� ������ �ٸ� �����
�ִ� �� Ȯ���Ѵ�. ���ٸ� �� ����� �̸���, �ִٸ� 'Runoff!'�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �ؽø�

��ó : VTH 2015 B��
*/

char buff[103000];
unordered_map<string, int> cand;

int main(void) {
    int bcnt = 0, major = 0;
    string s;
    while (1) {
        fgets(buff, 101300, stdin);
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        if (buff[0] == '*') break;
        s.assign(buff);
        if (cand.find(s) != cand.end()) cand[s]++;
        else cand.insert({ s, 1 });
    }
    for (auto& i : cand) {
        if (i.second > bcnt) {
            major = 1;
            bcnt = i.second;
            s = i.first;
        }
        else if (i.second == bcnt) major = 0;
    }
    if (major) printf("%s", s.c_str());
    else printf("Runoff!");
    return 0;
}
