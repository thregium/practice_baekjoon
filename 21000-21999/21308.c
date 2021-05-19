#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MOD 102983

/*
문제 : 다음과 같은 3진법 프로그램의 인터프리터를 작성한다. 프로그램 전체가 할 줄에 주어지고, 아래로는 입력들이 주어진다.
언어의 문법은 다음과 같은 연산자들(생략)과 연산자에 따라서는 있을 수도 있는 추가 값들이 주어진다.
대부분의 경우 스택을 이용해 연산을 하며, 라벨로 점프를 통해 제어 가능하다.
힙 영역은 임의의 수를 주소로 갖는 메모리 영역이다.
만약, (스택 언더플로 / 오버플로, 0으로 나누기, 라벨 재정의, 라벨 확인 불가, 해독 불가 등) 런타임 에러가 발생하는 경우
중간에 프로그램을 종료한다.

해결 방법 : 생략

주요 알고리즘 : 구현, 시뮬레이션, 스택

출처 : GNY 2020 I번
*/

/*
어디서 많이 본 언어같다면 기분 탓..?
    
    
            
    
            
                
                    
    



*/

char program[10240], labels[2048][192], labeldump[10240][192], isheapin[103000];
int operation[10240][2], labelpos[2048], stack[1024], substack[1024], heap[103000], stacks[1024];
int op = 0, lp = 1, sp = 1, sttop = 0, len;

void parse(void);
int parsenum(int* p, int o);
char* parselabel(int* p);
int getoper(int);
int operate(int o, int par, int pos);
int push(int num);
int dup(void);
int swap(void);
int discard(void);
int compute(int o);
int hash(int);
int heapin(void);
int heapout(void);
int findlabel(char* label);
int subroutine(int lnum, char* label);
int jump(int lnum, char* label);
int jumpif(int mode, int lnum, char* label);
int endsubroutine(int lnum, char* label);
int printchar(void);
int printnum(void);
int readchar(void);
int readnum(void);

int main(void) {
    fgets(program, 10000, stdin);
    if (program[strlen(program) - 1] == '\n') program[strlen(program) - 1] = '\0';
    len = strlen(program);
    parse();
    for (substack[sp - 1] = 0; substack[sp - 1] < op; substack[sp - 1]++) {
        if (operation[substack[sp - 1]][0] == 36) return 0;
        if (operate(operation[substack[sp - 1]][0], operation[substack[sp - 1]][1], substack[sp - 1]) < 0) {
            printf("RUN-TIME ERROR"); //오류 코드가 반환된 경우
            break;
        }
    }
    return 0;
}

void parse(void) {
    int p = 0, o;
    while (p < len) {
        o = getoper(p);
        operation[op][0] = o;

        if (o < 0) break;
        else if (o / 10 == 1 || o / 10 == 4) p += 4;
        else p += 3;
        if (o <= 2) operation[op][1] = parsenum(&p, o); //숫자를 파싱한다.
        else if (o >= 30 && o <= 34) {
            char* tmplbl = parselabel(&p); //라벨을 파싱한다.
            if (o == 30) {
                for (int i = 1; i < lp; i++) {
                    if (!strcmp(tmplbl, labels[i])) {
                        operation[op][0] = -1; //이미 정의된 라벨인 경우
                        break;
                    }
                }
                strcpy(labels[lp], tmplbl); //라벨 목록에 추가한다.
                operation[op][1] = lp;
                labelpos[lp] = op;
                lp++;
            }
            else {
                for (int i = 1; i < lp; i++) {
                    if (!strcmp(tmplbl, labels[i])) {
                        operation[op][1] = i;
                        break;
                    }
                }
                if (operation[op][1] == 0) {
                    //라벨을 찾지 못한 경우
                    operation[op][1] = -1;
                    strcpy(labeldump[op], tmplbl); //미확인 라벨 배열에 넣어둔다.
                }
            }
            free(tmplbl);
        }
        op++;
    }
}

int parsenum(int* p, int o) {
    int r = 0;
    while (program[*p] != '2') {
        //2가 나오는 지점까지 수 입력
        r *= 2;
        r += program[*p] - '0';
        (*p)++;
    }
    (*p)++;
    if (o == 2) return -r;
    else return r;
}

char* parselabel(int* p) {
    int i = 0;
    char* a = calloc(1, sizeof(char) * 192);
    while (program[*p] != '2') {
        //2가 나오는 지점까지 라벨 입력
        a[i] = program[*p];
        i++;
        (*p)++;
    }
    (*p)++;
    return a;
}

int getoper(int p) {
    if (program[p] == '0' && program[p + 1] == '0' && program[p + 2] == '0') return 1; //스택에 양수 추가
    if (program[p] == '0' && program[p + 1] == '0' && program[p + 2] == '1') return 2; //스택에 음수 추가
    if (program[p] == '0' && program[p + 1] == '2' && program[p + 2] == '0') return 3; //최상위 원소 복제
    if (program[p] == '0' && program[p + 1] == '2' && program[p + 2] == '1') return 4; //최상위 2원소 교환
    if (program[p] == '0' && program[p + 1] == '2' && program[p + 2] == '2') return 5; //최상위 원소 삭제

    if (program[p] == '1' && program[p + 1] == '0' && program[p + 2] == '0' && program[p + 3] == '0') return 10; //+
    if (program[p] == '1' && program[p + 1] == '0' && program[p + 2] == '0' && program[p + 3] == '1') return 11; //-
    if (program[p] == '1' && program[p + 1] == '0' && program[p + 2] == '0' && program[p + 3] == '2') return 12; //*
    if (program[p] == '1' && program[p + 1] == '0' && program[p + 2] == '1' && program[p + 3] == '0') return 13; //(/)
    if (program[p] == '1' && program[p + 1] == '0' && program[p + 2] == '1' && program[p + 3] == '1') return 14; //%

    if (program[p] == '1' && program[p + 1] == '1' && program[p + 2] == '0') return 20; //메모리에 원소 저장
    if (program[p] == '1' && program[p + 1] == '1' && program[p + 2] == '1') return 21; //메모리에서 원소 인출

    if (program[p] == '2' && program[p + 1] == '0' && program[p + 2] == '0') return 30; //라벨 생성
    if (program[p] == '2' && program[p + 1] == '0' && program[p + 2] == '1') return 31; //서브루틴 호출
    if (program[p] == '2' && program[p + 1] == '0' && program[p + 2] == '2') return 32; //해당 라벨로 점프
    if (program[p] == '2' && program[p + 1] == '1' && program[p + 2] == '0') return 33; //스택 최상위 원소가 0인 경우 점프
    if (program[p] == '2' && program[p + 1] == '1' && program[p + 2] == '1') return 34; //스택 최상위 원소가 음수인 경우 점프
    if (program[p] == '2' && program[p + 1] == '1' && program[p + 2] == '2') return 35; //서브루틴 종료
    if (program[p] == '2' && program[p + 1] == '2' && program[p + 2] == '2') return 36; //프로그램 종료

    if (program[p] == '1' && program[p + 1] == '2' && program[p + 2] == '0' && program[p + 3] == '0') return 40; //문자 출력
    if (program[p] == '1' && program[p + 1] == '2' && program[p + 2] == '0' && program[p + 3] == '1') return 41; //수 출력
    if (program[p] == '1' && program[p + 1] == '2' && program[p + 2] == '1' && program[p + 3] == '0') return 42; //문자 입력
    if (program[p] == '1' && program[p + 1] == '2' && program[p + 2] == '1' && program[p + 3] == '1') return 43; //수 입력

    return -1;
}

int operate(int o, int par, int pos) {
    int r = 0;
    if (o < 0) return -100; //구문 오류
    else if (o <= 2) r = push(par);
    else if (o == 3) r = dup();
    else if (o == 4) r = swap();
    else if (o == 5) r = discard();
    else if (o < 20) r = compute(o - 10);
    else if (o == 20) r = heapin();
    else if (o == 21) r = heapout();
    else if (o == 30); //라벨 생성, 프로그램 필요 X
    else if (o == 31) r = subroutine(par, labeldump[pos]);
    else if (o == 32) r = jump(par, labeldump[pos]);
    else if (o <= 34) r = jumpif(o - 32, par, labeldump[pos]);
    else if (o == 35) r = endsubroutine(par, labeldump[pos]);
    else if (o == 36); //프로그램 종료, 외부에 구현
    else if (o == 40) r = printchar();
    else if (o == 41) r = printnum();
    else if (o == 42) r = readchar();
    else if (o == 43) r = readnum();

    if (r > 0) operation[pos][1] = r; //라벨 갱신
    return r;
}

int push(int num) {
    if (sttop == 1024) return -1; //스택 오버플로
    else stack[sttop++] = num;
    return 0;
}

int dup(void) {
    if (sttop == 1024 || sttop == 0) return -3; //스택 오버/언더플로
    else stack[sttop++] = stack[sttop - 1];
    return 0;
}

int swap(void) {
    if (sttop < 2) return -2; //스택 언더플로
    int temp = stack[sttop - 2];
    stack[sttop - 2] = stack[sttop - 1];
    stack[sttop - 1] = temp;
    return 0;
}

int discard(void) {
    if (sttop == 0) return -2; //스택 언더플로
    sttop--;
    return 0;
}

int compute(int o) {
    if (sttop < 2) return -2; //스택 언더플로
    int val = 0;
    switch (o) {
    case 0:
        val = stack[sttop - 2] + stack[sttop - 1];
        break;
    case 1:
        val = stack[sttop - 2] - stack[sttop - 1];
        break;
    case 2:
        val = stack[sttop - 2] * stack[sttop - 1];
        break;
    case 3:
        if (stack[sttop - 1] == 0) return -10; //블랙홀 생성
        val = stack[sttop - 2] / stack[sttop - 1];
        break;
    case 4:
        if (stack[sttop - 1] == 0) return -10; //블랙홀 생성
        val = stack[sttop - 2] % stack[sttop - 1];
        break;
    }
    discard();
    discard();
    push(val);
    return 0;
}

int hash(int a) {
    //나머지 연산을 통해 값을 압축한다.
    if (a < 0) return (a % MOD + MOD) % MOD;
    return a % MOD;
}

int heapin(void) {
    if (sttop < 2) return -2;
    int address = hash(stack[sttop - 2]);
    heap[address] = stack[--sttop];
    isheapin[address] = 1;
    sttop--;
    return 0;
}

int heapout(void) {
    if (sttop == 0) return -2;
    int address = hash(stack[sttop - 1]);
    //if (!isheapin[address]) return -21; //힙 주소에 메모리 없음 - 오류 아님
    stack[sttop - 1] = heap[address];
    return 0;
}

int findlabel(char* label) {
    for (int i = 1; i < lp; i++) {
        if (!strcmp(label, labels[i])) return i;
    }
    return -1; //라벨 확인 실패
}

int subroutine(int lnum, char* label) {
    if (sp == 1024) return -31; //서브루틴 스택 오버플로
    if (lnum < 0) lnum = findlabel(label);
    if (lnum < 0) return -33; //라벨 불명
    substack[sp++] = labelpos[lnum];
    return lnum;
}

int endsubroutine(int lnum, char* label) {
    if (sp == 1) return -32; //서브루틴 스택 언더플로
    if (lnum < 0) lnum = findlabel(label);
    if (lnum < 0) return -33; //라벨 불명
    sp--;
    return lnum;
}

int jump(int lnum, char* label) {
    if (lnum < 0) lnum = findlabel(label);
    if (lnum < 0) return -33; //라벨 불명
    substack[sp - 1] = labelpos[lnum];
    return lnum;
}

int jumpif(int mode, int lnum, char* label) {
    if (lnum < 0) lnum = findlabel(label);
    if (lnum < 0) return -33; //라벨 불명
    if ((mode == 1 && stack[sttop - 1] == 0) || (mode == 2 && stack[sttop - 1] < 0)) jump(lnum, label);
    sttop--;
    return lnum;
}

int printchar(void) {
    if (sttop == 0) return -2; //스택 언더플로
    if (stack[sttop - 1] > 127 || stack[sttop - 1] < 0) return -41; //잘못된 문자
    printf("%c", stack[--sttop]);
    return 0;
}

int printnum(void) {
    if (sttop == 0) return -2; //스택 언더플로
    printf("%d", stack[--sttop]);
    return 0;
}

int readchar(void) {
    if (sttop == 0 || sttop == 1024) return -3; //스택 오버/언더플로
    int address = hash(stack[--sttop]);
    char c;
    int r = scanf("%c", &c);
    if (r == 0) return -42; //입력 확인 실패
    heap[address] = c;
    isheapin[address] = 1;
    return 0;
}

int readnum(void) {
    if (sttop == 0 || sttop == 1024) return -3; //스택 오버/언더플로
    int address = hash(stack[--sttop]);
    int n;
    int r = scanf("%d", &n);
    if (r == 0) return -42; //입력 확인 실패
    heap[address] = n;
    isheapin[address] = 1;
    return 0;
}