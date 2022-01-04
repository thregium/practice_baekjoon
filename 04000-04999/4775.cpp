#include <stdio.h>
#include <string.h>
#include <set>
#include <string>
using namespace std;

/*
문제 : N개의 단어로 이루어진 단어장과 M개의 이메일 문장들이 주어질 때, 단어장에 있는 단어들만으로 이메일을 썼는 지 확인하고,
아니라면 단어장에 없는 문장들을 전부 출력한다.

해결 방법 : 셋을 이용해 단어장의 내용들을 저장한 뒤, 이메일의 단어들마다 단어장에 있는 지 살핀다.
없는 단어들을 전부 출력해 나가면 된다.

주요 알고리즘 : 문자열, 자료 구조, 셋

출처 : MidAtl 2002 C번
*/

set<string> dict;
char buff[103000];

int main(void) {
    int n, r;
    string s;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Atlantic\\2002\\MidAtlantic2002-Solutions+Data\\problem-C\\pC1.dat", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Atlantic\\2002\\MidAtlantic2002-Solutions+Data\\problem-C\\pC1_t.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        s.assign(buff);
        dict.insert(s);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        r = 1;
        while (1) {
            scanf("%s", buff);
            if (!strcmp(buff, "-1")) break;
            s.assign(buff);
            if (dict.find(s) == dict.end()) {
                if (r) {
                    printf("Email %d is not spelled correctly.\n", i);
                    r = 0;
                }
                printf("%s\n", buff);
            }
        }
        if (r) printf("Email %d is spelled correctly.\n", i);
    }
    printf("End of Output");
    return 0;
}