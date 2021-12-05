#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
#include <set>
using namespace std;

/*
문제 : 100개 이하의 문자열(소문자, 6자 이하)이 주어진다. 그리고 "XXXXXX"가 주어진 후, 다시 문자열들이 주어진다.
문자열마다 해당 문자열의 순서를 바꾸어 만들 수 있는 앞의 문자열들을 사전 순으로 출력한다.
없는 경우 "NOT A VALID WORD"를 출력한다.

해결 방법 : 문자열의 문자들을 정렬한 것과 원래 문자열들의 셋을 맵으로 만들어 저장하고 있는다.
주어진 문자열마다 정렬한 후 맵에서 해당 정렬된 문자열에서 원래 문자열들의 셋을 출력하면 된다.

주요 알고리즘 : 문자열, 자료 구조, 셋, 맵, 정렬

출처 : MidC 1998 F번
*/

char buff[16], sorted[16];
map<string, set<string>> dict;

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    string a, b;
    while (1) {
        scanf("%s", buff);
        if (!strcmp(buff, "XXXXXX")) break;
        strcpy(sorted, buff);
        qsort(sorted, strlen(sorted), sizeof(char), cmp1);
        a.assign(buff);
        b.assign(sorted);
        if (dict.find(b) == dict.end()) dict.insert(pair<string, set<string>>(b, set<string>()));
        dict[b].insert(a);
    }
    while (1) {
        scanf("%s", sorted);
        if (!strcmp(sorted, "XXXXXX")) break;
        qsort(sorted, strlen(sorted), sizeof(char), cmp1);
        a.assign(sorted);
        if (dict.find(a) == dict.end()) printf("NOT A VALID WORD\n");
        else {
            for (auto i : dict[a]) {
                printf("%s\n", i.c_str());
            }
        }
        printf("******\n");
    }
    return 0;
}