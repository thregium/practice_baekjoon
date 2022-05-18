#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

/*
���� : 4000�� ������ �ҹ��ڷ� �̷���� �� ���ڿ��� �־��� ��, �� ���ڿ��� ���� ��
���� �Ƴ��׷��� ���̸� ���Ѵ�. ���� �Ƴ��׷��� �κ� ���ڿ� ��� ���� �Ƴ��׷� ������ ���̴�.

�ذ� ��� : �� ���̸��� �ش� ������ ��� �κ� ���ڿ����� �� ���ĺ��� ������ ���� �迭��
�¿� ������ ����, �� ��° ���ڿ��� ���� ���� ����� �迭�� �Ź� �ִ� �� �˻��Ѵ�.
�� ���̶� �ִ� ��� �� ������ ���ڿ��� ���� �Ƴ��׷��� �ִ� ���̴�.
�̸� ��� ���̿� ���� �˻��ϰ�, ���� ū ���� ���ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ���Ʈ ����, ��

��ó : Tsukuba 2016 D��
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