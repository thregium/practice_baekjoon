#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

/*
문제 : N(N <= 26)개의 도시와 M(M <= 15)개의 도시 쌍이 주어진다. 주어진 도시 사이 트리 형태로
연결이 되었다면, 각 도시 쌍에 대해 최단 경로를 도시의 앞글자로 표현한다.
주어지는 도시 쌍은 이미 앞에 주어진 도시 가운데 하나씩이고 서로 다르다.

해결 방법 : 각 도시의 연결을 해시맵으로 저장한 다음, 플러드필과 역추적을 통해 최단 경로를 찾으면 된다.

주요 알고리즘 : 그래프 이론, 플러드필, 트리, 해시맵, 역추적

출처 : CCO 1996 5번
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