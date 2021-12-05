#include <stdio.h>
#include <ctype.h>
#include <string>
#include <set>
#include <map>
using namespace std;

/*
문제 : 임의의 길이로 이루어진 여러 줄의 문자열이 주어질 때, 연속된 1개, 2개, 3개, 4개, 5개의 알파벳에 대해
가장 빈도가 높은 5개의 연속 알파벳들의 빈도와 그 연속 알파벳들을 각각 출력한다. 대소문자는 구별하지 않는다.
같은 빈도의 알파벳들이 여러 개인 경우 해당 빈도의 연속 알파벳들을 사전순으로 출력하고 다음 빈도로 간다.

해결 방법 : 각 빈도 별 알파벳들을 맵을 이용해 관리한다. 각 줄마다 연속된 1개, 2개, 3개, 4개, 5개의 알파벳들이
있는지 확인하고, 그러한 경우 그 알파벳들을 맵에 추가한다. 이때, 알파벳별 빈도를 또 맵으로 만들어둔다.
빈도를 확인해서 맵에 없는 경우에는 맵에 빈도 1로 추가하고, 있다면 빈도를 1개 올려 맵에 추가한다.
이때, 알파벳을 추가하여 맵의 알파벳이 사라졌다면 그 노드를 삭제한다.
각 빈도 별 알파벳들은 셋 형태로 관리하고, 큰 수가 먼저 오도록 한다.

모든 알파벳들을 추가했으면 각 길이마다 빈도가 높은 5개의 노드를 가져온다. 각 노드에 대해 사전순으로 알파벳들을 출력하면 된다.

주요 알고리즘 : 문자열, 맵, 셋, 구현

출처 : MidC 1995 6번
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