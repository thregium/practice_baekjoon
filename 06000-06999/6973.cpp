#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
문제 : 주어진 문자열에서 이미 나왔던 단어라면 몇 번째 고유한 단어인지 번째수를 적고,
나오지 않은 단어라면 그대로 하여 출력한다.

해결 방법 : 해시맵을 이용한다. 입력 형식이 특이하므로 주의한다.

주요 알고리즘 : 문자열, 파싱, 해시맵

출처 : CCC 1997 4번
*/

char buff[128];
unordered_map<string, int> mp;

int main(void) {
    int n, wcnt;
    char* tok;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        wcnt = 0;
        mp.clear();
        while (1) {
            if (!fgets(buff, 100, stdin)) return 0;
            if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
            if (buff[0] == '\0') break;
            
            tok = strtok(buff, " ");
            while (tok) {
                if (mp.find(tok) != mp.end()) printf("%d ", mp[tok]);
                else {
                    printf("%s ", tok);
                    mp.insert({ tok, ++wcnt });
                }
                tok = strtok(NULL, " ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}