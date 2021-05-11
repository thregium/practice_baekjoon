#include <stdio.h>
#include <ctype.h>

/*
문제 : 4비트 단위의 간단한 마이크로 프로세서를 설명에 맞게 구현하고 입력에 따른 출력 결과를 구한다.

해결 방법 : 설명에 맞게 구현한다.

주요 알고리즘 : 구현

출처 : GNY 2001 F번
*/

char memory[320], a, b;

int getdata(char c) {
    //워드를 수로 변환한다.
    if (isdigit(c)) return c - '0';
    else return c - 'A' + 10;
}

char makeword(int d) {
    //수를 워드로 변환한다.
    if (d < 10) return d + '0';
    else return d + 'A' - 10;
}

int getaddress(int x) {
    //해당하는 위치의 값들을 주소(수)로 변환한다.
    return getdata(memory[x]) * 16 + getdata(memory[x + 1]);
}

void swapacc(void) {
    //A와 B를 교환한다.
    char t = a;
    a = b;
    b = t;
}

void addacc(void) {
    //A와 B를 더하고 값들을 각각 저장한다.
    int t = getdata(a) + getdata(b);
    a = makeword(t % 16);
    b = makeword(t / 16);
}

int main(void) {
    while (scanf("%s", memory) != EOF) {
        if (memory[0] == '8') return 0;
        a = '0';
        b = '0';
        for (int p = 0; p < 256; p++) {
            if (memory[p] == '8') {
                //프로그램을 종료한다.
                break;
            }
            switch (memory[p]) {
            case '0':
                //메모리에서 값을 불러와 A에 저장한다.
                a = memory[getaddress(p + 1)];
                p += 2;
                break;
            case '1':
                //A에 있던 값을 메모리에 저장한다.
                memory[getaddress(p + 1)] = a;
                p += 2;
                break;
            case '2':
                //A와 B를 교환한다.
                swapacc();
                break;
            case '3':
                //A와 B를 더하고 값을 각각 저장한다.
                addacc();
                break;
            case '4':
                //A에 1을 더한다. 오버플로가 나는 경우 0으로 바꾼다.
                a = makeword((getdata(a) + 1) % 16);
                break;
            case '5':
                //A에서 1을 뺀다. 오버플로가 나는 경우 F로 바꾼다.
                a = makeword((getdata(a) + 15) % 16);
                break;
            case '6':
                //A가 0인 경우 주어진 주소로 이동한다.
                if (a == '0') {
                    p = getaddress(p + 1) - 1;
                }
                else p += 2;
                break;
            case '7':
                //주어진 주소로 이동한다.
                p = getaddress(p + 1) - 1;
            }
        }
        
        for (int i = 0; i < 256; i++) printf("%c", memory[i]);
        printf("\n");
    }
    return 0;
}