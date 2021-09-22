#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
문제 : 각 사용자의 접속 기록을 통해 N(N <= 100000)개의 쿼리에 응답한다.
1. 주어진 이름의 사용자가 접속한다.
2. 주어진 이름의 사용자의 최근 접속 시각과 접속 횟수를 이용하여 해당 사용자가 어디에 해당하는지 출력한다. (분류 생략)
모든 사용자의 이름은 길이 10 이하의 소문자로 이루어져 있다.

해결 방법 : 각 사용자가 접속할 때 마다 해당 사용자의 접속 여부를 해시맵에 저장되었는지를 통해 확인한다.
접속한 적이 있다면 접속 기록을 업데이트하고, 없다면 해당하는 정보를 해시맵에 추가한다.
2번 쿼리가 들어온 경우에는 마찬가지로 해시맵을 통해 접속 여부를 확인한다. 접속한 적이 없다면 "None"을 출력하면 되고,
접속한 적이 있다면 해시맵에서 정보를 찾아 최근 접속 시각과 접속 횟수가 어디에 속하는지를 찾고,
속하는 곳의 분류를 찾아 출력하면 된다. 분류는 배열에서 정수형으로 미리 저장해두는 것이 좋다.

주요 알고리즘 : 구현, 해시맵

출처 : KAIST 2018 S번
*/

char buff[16];
int freq[4], rec[4];
int cat[5][5] = { {1, 2, 3, 5, 5}, {6, 6, 3, 4, 5}, {6, 6, 7, 8, 8}, {10, 10, 10, 8, 8}, {9, 10, 10, 8, 11} };
const char* cats[] = { "None", "New Customer", "Promising", "About to Sleep", "Hibernating", "Lost", "Potential Loyalist",
"Need Attention", "About to Leave", "Champion", "Loyal Customer", "Can't Lose Them" };
unordered_map<string, pair<int, int>> um;

int main(void) {
    int n, o, f, r, fc, rc;
    string name;
    for (int i = 0; i < 4; i++) scanf("%d", &rec[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &freq[i]);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %s", &o, buff);
        name.assign(buff);
        if (o == 1) {
            if (um.find(name) == um.end()) {
                um.insert(pair<string, pair<int, int>>(name, pair<int, int>(1, i)));
            }
            else {
                (um.find(name)->second.first)++;
                um.find(name)->second.second = i;
            }
        }
        else {
            if (um.find(name) == um.end()) {
                printf("None\n");
            }
            else {
                f = um.find(name)->second.first;
                r = i - (um.find(name)->second.second);
                fc = -1, rc = -1;
                for (int j = 0; j < 4; j++) {
                    if (f <= freq[j]) {
                        fc = j;
                        break;
                    }
                }
                if (fc < 0) fc = 4;
                for (int j = 0; j < 4; j++) {
                    if (r <= rec[j]) {
                        rc = j;
                        break;
                    }
                }
                if (rc < 0) rc = 4;
                printf("%s\n", cats[cat[fc][rc]]);
            }
        }
    }
    return 0;
}