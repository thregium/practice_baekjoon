#include <stdio.h>

/*
문제 : 두 명이 두 손으로 가위바위보를 했다. 한 손을 정할 때, 다른 사람이 정한 것에 상관 없이
무조건 이기는 방법이 있는 사람이 있는지, 있다면 누구인지 구한다.

해결 방법 : 각 사람에 대해 왼손으로 정했을 때, 상대가 정한 것에 상관 없이 이기는지, 또는 오른손을 정했을 때
이기는지를 확인한다. 그랬을 때가 무조건 이기는 것이고, 그러한 사람이 나오면 그 사람을 출력하면 된다.

주요 알고리즘 : 브루트 포스, 케이스 워크

출처 : 고려대 2018B C번
*/

int rps(char a, char b) {
    //두 사람의 가위바위보 결과를 출력한다.
    if (a == b) return 0;
    if ((a == 'R' && b == 'P') || (a == 'P' && b == 'S') || (a == 'S' && b == 'R')) return -1;
    return 1;
}

int main(void) {
    char ml, mr, tl, tr, m = 0, t = 0;
    scanf("%c %c %c %c", &ml, &mr, &tl, &tr);
    if ((rps(ml, tl) + rps(ml, tr) == 2) || (rps(mr, tl) + rps(mr, tr) == 2)) m = 1;
    if ((rps(ml, tl) + rps(mr, tl) == -2) || (rps(ml, tr) + rps(mr, tr) == -2)) t = 1;
    if (m && !t) printf("MS");
    else if (t && !m) printf("TK");
    else printf("?");
    return 0;
}