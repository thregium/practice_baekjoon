#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
문제 : 주어진 XML 문서가 규칙에 맞는지 검사하는 프로그램을 만든다.

해결 방법 : 각 태그들을 전부 분리해서 키워드들과 태그의 종류(종료 여부, 매개 변수 등)를 얻는다.
키워드들은 순서대로 스택에 저장하고 만약 스택에서 빼는 과정에서 맞지 않는 값이 나오거나 스택이 빈 상태에서 빼려고 하는
등의 상황이 나오면 규칙에 맞지 않음을 알 수 있다. 또한, 스택에 있던 값들을 다시 넣거나 프로그램이 종료되고도
스택에 값이 남아있는 경우, 아니면 메인 태그가 2개 이상인 경우 등도 전부 체크한다.

주요 알고리즘 : 구현, 파싱, 스택

출처 : GNY 2000 E번
*/

char buff[1024], temp[64], stack[1024][64];//, lastelems[1024][16][64];
int sttop = 0;

int parse(void) {
    int bracket = 0, ends = 0, tp = 0, at = 0, fin = 0;
    for (int i = 0; buff[i]; i++) {
        if (buff[i] == '<') {
            if (bracket || fin) return 0;
            bracket = 1;
        }
        else if (buff[i] == '>') {
            if (!bracket) return 0;
            if (at > 0 && at % 2 == 0) return 0;
            if (ends == 0) {
                //새로운 태그인 경우
                for (int j = 0; j < sttop; j++) {
                    if (!strcmp(temp, stack[j])) return 0; //만약 스택에 이미 존재하던 태그라면 규칙 위반
                }
                strcpy(stack[sttop], temp);
                sttop++;
            }
            else if (ends == 1) {
                //닫는 태그인 경우
                if (strcmp(temp, stack[sttop - 1])) return 0; //스택의 꼭대기와 값이 다르다면 규칙 위반
                else {
                    sttop--;
                    if (sttop < 0) {
                        sttop = 0;
                        return 0; //스택이 0인데 닫는 태그가 나온 경우 규칙 위반
                    }
                    else if (sttop == 0) fin = 1;
                }
            }
            else {
                //독립된 태그인 경우
                for (int j = 0; j < sttop; j++) {
                    if (!strcmp(temp, stack[j])) return 0; //스택에 존재하던 태그라면 규칙 위반
                }
            }
            ends = 0;
            at = 0;
            bracket = 0;
            tp = 0;
        }
        if (buff[i] == '/' && bracket) {
            if (tp) ends = 2; //끝에 /이 있는 경우
            else ends = 1; //시작에 /이 있는 경우
        }
        else if (bracket && (isalpha(buff[i]) || isdigit(buff[i]) || buff[i] == '-') && at == 0) {
            //키워드 추가
            temp[tp++] = buff[i];
            temp[tp] = '\0';
        }
        else if (bracket && buff[i] == ' ') {
            at = 1; //이후로는 매개 변수
        }
        else if (bracket && at && buff[i] == '\"') at++; //"가 짝수개 있어야 함
    }
    return 1;
}

int main(void) {
    int r;
    //freopen("C:\\1_공부\\PS\\ICPC\\North America\\Greater New York\\2000\\probleme.in", "r", stdin);
    //freopen("C:\\1_공부\\PS\\ICPC\\North America\\Greater New York\\2000\\probleme_check.out", "w", stdout);
    for (int tt = 0;; tt++) {
        if (tt == 0) fgets(buff, 1000, stdin);
        if (strstr(buff, "<?end?>")) break;
        r = 1;
        sttop = 0;
        fgets(buff, 1000, stdin);
        r = parse();
        while (r && sttop) {
            //규칙에 맞다면 스택이 빌 때 까지 파싱
            fgets(buff, 1000, stdin);
            if (strstr(buff, "<?xml version=\"1.0\"?>") || strstr(buff, "<?end?>")) break;
            r = parse();
        }

        while (!strstr(buff, "<?xml version=\"1.0\"?>") && !strstr(buff, "<?end?>")) {
            //규칙에 맞지 않는 경우 다음 테스트 케이스의 시작 지점까지의 문자열은 버림
            fgets(buff, 1000, stdin);
            if (strstr(buff, "<?xml version=\"1.0\"?>") || strstr(buff, "<?end?>")) break;
            if (!strcmp(buff, "\n")) continue;
            r = 0;
        }
        if (sttop) {
            //스택에 값이 남아있는 경우 규칙 위반
            r = 0;
            sttop = 0;
        }
        if (!r) printf("non ");
        printf("well-formed\n");
        continue;
    }
    return 0;
}