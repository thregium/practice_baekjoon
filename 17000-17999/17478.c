#include <stdio.h>

/*
문제 : 주어진 문장을 N회 재귀하여 출력한다.

해결 방법 : 문제대로 구현한다. 실제로 재귀를 할 필요는 없다.

주요 알고리즘 : 구현

출처 : 중앙대 2019 A번
*/

void printstrike(int n) {
    for (int i = 0; i < n; i++) {
        printf("____");
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
    for (int i = 0; i < n; i++) {
        printstrike(i);
        printf("\"재귀함수가 뭔가요?\"\n");
        printstrike(i);
        printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
        printstrike(i);
        printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
        printstrike(i);
        printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
    }
    printstrike(n);
    printf("\"재귀함수가 뭔가요?\"\n");
    printstrike(n);
    printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
    for (int i = n; i >= 0; i--) {
        printstrike(i);
        printf("라고 답변하였지.\n");
    }
    return 0;
}