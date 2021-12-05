#include <stdio.h>
#include <ctype.h>
#include <string>
#include <set>
#include <map>
using namespace std;

/*
���� : ������ ���̷� �̷���� ���� ���� ���ڿ��� �־��� ��, ���ӵ� 1��, 2��, 3��, 4��, 5���� ���ĺ��� ����
���� �󵵰� ���� 5���� ���� ���ĺ����� �󵵿� �� ���� ���ĺ����� ���� ����Ѵ�. ��ҹ��ڴ� �������� �ʴ´�.
���� ���� ���ĺ����� ���� ���� ��� �ش� ���� ���� ���ĺ����� ���������� ����ϰ� ���� �󵵷� ����.

�ذ� ��� : �� �� �� ���ĺ����� ���� �̿��� �����Ѵ�. �� �ٸ��� ���ӵ� 1��, 2��, 3��, 4��, 5���� ���ĺ�����
�ִ��� Ȯ���ϰ�, �׷��� ��� �� ���ĺ����� �ʿ� �߰��Ѵ�. �̶�, ���ĺ��� �󵵸� �� ������ �����д�.
�󵵸� Ȯ���ؼ� �ʿ� ���� ��쿡�� �ʿ� �� 1�� �߰��ϰ�, �ִٸ� �󵵸� 1�� �÷� �ʿ� �߰��Ѵ�.
�̶�, ���ĺ��� �߰��Ͽ� ���� ���ĺ��� ������ٸ� �� ��带 �����Ѵ�.
�� �� �� ���ĺ����� �� ���·� �����ϰ�, ū ���� ���� ������ �Ѵ�.

��� ���ĺ����� �߰������� �� ���̸��� �󵵰� ���� 5���� ��带 �����´�. �� ��忡 ���� ���������� ���ĺ����� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ��, ��, ����

��ó : MidC 1995 6��
*/

map<int, set<string>, greater<int>> mp[8];
map<string, int> mp2;
char s[103000], buff[8];

void put_to_map(int l) {
    int cnt;
    string str;
    str.assign(buff);
    if (mp2.find(str) == mp2.end()) {
        mp2.insert(pair<string, int>(str, 1));
        mp[l][1].insert(str);
    }
    else {
        cnt = (mp2.find(str)->second)++;
        mp[l][cnt].erase(str);
        if (mp[l][cnt].empty()) mp[l].erase(cnt);
        mp[l][cnt + 1].insert(str);
    }
}

int main(void) {
    int c, c2;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1995\\sequence.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\1995\\sequence_t.out", "w", stdout);
    while (fgets(s, 101300, stdin)) {
        for (int i = 0; s[i]; i++) {
            for (int j = 0; j < 5; j++) {
                if (!isalpha(s[i + j])) break;
                buff[j] = toupper(s[i + j]);
                buff[j + 1] = '\0';
                put_to_map(j + 1);
            }
        }
    }
    for (int i = 1; i <= 5; i++) {
        printf("Analysis for Letter Sequences of Length %d\n", i);
        printf("-----------------------------------------\n");
        c = 0;
        for (auto j : mp[i]) {
            printf("Frequency = %d, Sequence(s) = (", j.first);
            c2 = 0;
            for (string k : mp[i][j.first]) {
                if (c2) printf(",");
                printf("%s", k.c_str());
                c2++;
            }
            printf(")\n");
            c++;
            if (c == 5) break;
        }
        if (i < 5) printf("\n");
    }
    return 0;
}