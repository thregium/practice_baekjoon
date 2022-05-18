#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

/*
���� : N(N <= 26)���� ���ÿ� M(M <= 15)���� ���� ���� �־�����. �־��� ���� ���� Ʈ�� ���·�
������ �Ǿ��ٸ�, �� ���� �ֿ� ���� �ִ� ��θ� ������ �ձ��ڷ� ǥ���Ѵ�.
�־����� ���� ���� �̹� �տ� �־��� ���� ��� �ϳ����̰� ���� �ٸ���.

�ذ� ��� : �� ������ ������ �ؽø����� ������ ����, �÷����ʰ� �������� ���� �ִ� ��θ� ã���� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷�����, Ʈ��, �ؽø�, ������

��ó : CCO 1996 5��
*/

char buffa[103000], buffb[103000];
unordered_map<string, vector<string>> ed;

string getdist(string stt, string edd, string par) {
    string tres = "";
    if (stt == edd) return tres + edd[0];
    for (auto& i : ed[stt]) {
        if (i == par) continue;
        tres = getdist(i, edd, stt);
        if (tres.size() > 0) return tres + stt[0];
    }
    return "";
}

int main(void) {
    int n, m;
    string sa, sb;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s %s", buffa, buffb);
        sa.assign(buffa);
        sb.assign(buffb);
        if (ed.find(sa) == ed.end()) ed.insert({ sa, {sb} });
        else ed[sa].push_back(sb);
        if (ed.find(sb) == ed.end()) ed.insert({ sb, {sa} });
        else ed[sb].push_back(sa);
    }

    for (int i = 0; i < m; i++) {
        scanf("%s %s", buffa, buffb);
        sa = getdist(buffa, buffb, "");
        for (int i = (signed)sa.size() - 1; i >= 0; i--) {
            printf("%c", sa[i]);
        }
        printf("\n");
    }
    return 0;
}