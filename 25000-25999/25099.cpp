#include <stdio.h>
#include <vector>;
#include <set>
using namespace std;

/*
���� : N(N <= 100000)���� 100�� ���� �ҹ��ڷ� �̷���� ���ڿ����� �־�����.
�̶�, ���ڿ��� �ռ� ���ڿ��� �Ƴ��׷� �� �ϳ��� �ƴ� ���ڿ��鸸 ����Ѵ�.

�ذ� ��� : �¿� ���� �ٸ� �Ƴ��׷����� �� ������ ������ �����ϰ�, ���ڿ��� �Էµ� �� ����
���� ���ڿ��� �� ���� ������ �¿� ����Ǿ��� �� Ȯ���Ѵ�. ����Ǿ��ٸ� �Ѿ��,
������� �ʾҴٸ� ���� ���ڿ��� ����ϰ� �� �������� �¿� �߰��ϴ� �۾��� �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : �ڷᱸ��, ��, ���ڿ�

��ó : CERC 2021 X��
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