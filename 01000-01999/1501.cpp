#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

/*
���� : N(N <= 10000)���� �ܾ�� M(M <= 10000)���� ������ �־��� ��, ��� ���忡 ����
������ �ؼ��� �������� ���� ���Ѵ�. �� �ܾ�� �������� ������ ���ٸ� �߰� ���ڵ��� ������ �������
�ٲپ� �ؼ� �����ϴ�. ��, �ؼ��� �ܾ�� �ܾ��忡 �ִ� ���̾�� �Ѵ�.

�ذ� ��� : �� �ܾ��� �߰� ���ڵ��� �� ������ �� ��, �� ���ڸ� ���Ϳ� �ְ� �ʿ� �ٽ� �־�
�� ��쿡 ���� ������ �����Ѵ�.
�ٽ� ������� �Է¹����� ������ �ܾ� ������ �ٲ� �� �� �ܾ� ���� ������ �ؼ��� �������� ���� ���ϰ�,
�� ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �ڷ� ����, ��

��ó : TUD 2005 7��
*/

char buff[10240], s[128];
map<vector<int>, int> mp;

int main(void) {
    int n, m, r;
    char* ss;
    vector<int> v;
    for (int i = 0; i < 130; i++) v.push_back(0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        v[128] = s[0];
        v[129] = s[strlen(s) - 1];
        for (int j = 0; j < 128; j++) v[j] = 0;
        for (int j = 0; s[j]; j++) {
            v[s[j]]++;
        }

        if (mp.find(v) == mp.end()) mp.insert({ v, 1 });
        else mp[v]++;
    }
    scanf("%d\n", &m);
    for (int i = 0; i < m; i++) {
        fgets(buff, 10130, stdin);
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        
        r = 1;
        ss = strtok(buff, " ");
        while (ss) {
            v[128] = ss[0];
            v[129] = ss[strlen(ss) - 1];
            for (int j = 0; j < 128; j++) v[j] = 0;
            for (int j = 0; ss[j]; j++) {
                v[ss[j]]++;
            }
            if (mp.find(v) == mp.end()) r = 0;
            else r *= mp[v];

            ss = strtok(NULL, " ");
        }
        printf("%d\n", r);
    }
    return 0;
}