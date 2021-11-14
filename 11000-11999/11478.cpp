#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_set>
using namespace std;

/*
���� : 1000�� ������ ���ڿ��� �־��� ��, ���� �ٸ� �κ� ���ڿ��� ������ ���Ѵ�.

�ذ� ��� : ��� �κ� ���ڿ����� Ȯ���ϸ� ���� ������ ���� �κ� ���ڿ����� �ؽü¿� �ִ´�.
��� Ȯ���� �� �ؽü��� ũ�Ⱑ ���� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽü�, ���ڿ�
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