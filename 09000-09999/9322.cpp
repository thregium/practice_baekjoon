#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;

/*
문제 : N(N <= 1000)개의 문자열로 된 세 문장이 주어질 때, 첫 번째 문장과 두 번째 문장은 서로 다른 단어로만 이루어져 있고,
구성이 같다. 세 번째 문장에 대응하는 두 번째 문장에서 같은 위치에 있든 첫 번째 문장의 단어들로 옮겼을 때의
순서들을 출력한다.

해결 방법 : 맵에 첫 번째 문장의 단어들마다 위치를 저장한 다음, 세 번째 문장까지 입력받고, 그 위치를 맵에서 찾아서
넣어야 할 위치에 넣는다. 그리고 출력하면 된다.

주요 알고리즘 : 자료 구조, 맵, 문자열

출처 : BAPC 2013P E번
*/

char buff[16], scnd[1024][16], res[1024][16];
map<string, int> mp;

int main(void) {
    int t, n;
    string s;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            s.assign(buff);
            mp.insert(pair<string, int>(s, i));
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", scnd[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%s", buff);
            s.assign(scnd[i]);
            strcpy(res[mp.find(s)->second], buff);
        }

        for (int i = 0; i < n; i++) {
            printf("%s ", res[i]);
        }
        printf("\n");
        mp.clear();
    }
    return 0;
}