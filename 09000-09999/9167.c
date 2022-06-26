#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 길이 72 이하의 문자열이 여러 줄 주어진다. 각 문자열의 내용을 가공하여 기사의 말로 출력한 후,
단어 3개마다 도발꾼의 말을 문제에 주어진 규칙대로 출력한다. 단, theholygrail이라는 부분 수열이
등장하는 경우(대소문자 무시), 첫 번째 도발은 "(A childish hand gesture)." 가 되어야 한다.

해결 방법 : 주어진 문자열을 파싱한 다음 원하는 형태의 문자열로 바꾸는 동시에 단어의 수와 theholygrail이라는
부분 수열의 등장 여부를 확인한다. 그리고 기사의 말을 출력하고
단어의 수, theholygrail 등장 여부에 맞춰 현재 상태에서의 도발을 출력한다.
도발에서 도발이 파생되는 경우에 유의한다.

주요 알고리즘 : 구현, 재귀, 파싱

출처 : PacNW 2006 I번
*/

char knight[128], knightmod[128];
char taunt[1024];

const char* theholygrail = "theholygrail";
const int rulecnt[17] = { 4, 3, 1, 2, 2, 1, 1, 3, 5, 11, 2, 2, 1, 7, 5, 1, 1 };
int state[17] = { 0, };

const int rule[7][5][4] = {
    {{1, 1}, {2, 0, 1}, {2, 9, 15}, {1, 1}},
    {{2, 6, 2}, {2, 5, 2}, {3, 6, 12, 9}},
    {{2, 12, 3}},
    {{1, 9}, {2, 4, 9}},
    {{1, 13}, {2, 14, 13}},
    {{3, 16, 7, 10}},
    {{3, 16, 8, 11}}
};

const char* word[17][11] = {
    {""}, {""}, {""}, {""}, {""}, {""}, {""},
    {" steed", " king", " first-born"},
    {" mother", " father", " grandmother", " grandfather", " godfather"},
    {" hamster", " coconut", " duck", " herring", " newt", " peril",
    " chicken", " vole", " parrot", " mouse", " twit"},
    {" is", " masquerades as"},
    {" was", " personified"},
    {" a"},
    {" silly", " wicked", " sordid", " naughty", " repulsive", " malodorous", " ill-tempered"},
    {" conspicuously", " categorically", " positively", " cruelly", " incontrovertibly"},
    {"!"},
    {" your"}
};

void maketaunt(int rulenum) {
    int chk = 0;
    if (rulenum < 7) {
        for (int i = 1; i <= rule[rulenum][state[rulenum]][0]; i++) {
            if (rule[rulenum][state[rulenum]][i] == 0) {
                state[0]++;
                maketaunt(0);
                state[0] -= 2;
            }
            else maketaunt(rule[rulenum][state[rulenum]][i]);
        }
    }
    else strcat(taunt, word[rulenum][state[rulenum]]);
    state[rulenum]++;
    if (state[rulenum] == rulecnt[rulenum]) state[rulenum] = 0;
}

int main(void) {
    int wcnt, pwd, kpos, thg, cap;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2006\\input\\i.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2006\\output\\i_t.out", "w", stdout);
    while (fgets(knight, 100, stdin)) {
        if (knight[strlen(knight) - 1] == '\n') knight[strlen(knight) - 1] = '\0';
        wcnt = 0, pwd = 0, kpos = 0, thg = 0;
        for (int i = 0; knight[i]; i++) {
            if (knight[i] == ' ') {
                if (kpos == 0 || knightmod[kpos - 1] == ' ') continue;
                else knightmod[kpos++] = ' ';
            }
            else {
                if (kpos == 0 || knightmod[kpos - 1] == ' ') pwd = 1;
                if (pwd && isalpha(knight[i])) {
                    wcnt++;
                    pwd = 0;
                }
                knightmod[kpos++] = knight[i];
            }

            if (thg < 12 && tolower(knight[i]) == theholygrail[thg]) thg++;
        }
        knightmod[kpos] = '\0';
        printf("Knight: %s\n", knightmod);

        if (thg == 12) thg = 1;
        else thg = 0;
        if (thg) {
            printf("Taunter: (A childish hand gesture).\n");
        }

        for (int i = thg * 3; i < wcnt; i += 3) {
            maketaunt(0);
            if (state[0] == 2) {
                state[0]++;
                i += 3;
            }
            cap = 1;
            for (int j = 0; taunt[j]; j++) {
                if (isalpha(taunt[j])) {
                    if (cap) {
                        taunt[j] = toupper(taunt[j]);
                        cap = 0;
                    }
                    else taunt[j] = tolower(taunt[j]);
                }
                else if (taunt[j] == '.' || taunt[j] == '!' || taunt[j] == '?') cap = 1;
            }

            printf("Taunter:%s.\n", taunt);
            taunt[0] = '\0';
        }
        printf("\n");
    }
    return 0;
}