#include <iostream>
#include <string>
#include <sstream>

#define IS_NUM(c) ((c>='0') && (c<='9'))
#define TO_NUM(c) (c-='0')
#define IS_MLP(c) (c=='*') || (c=='/')
#define st "  "
#define PRINTV { std::cout << st; }
#define PRINT(a) { std::cout << (a); }
#define PRINTL(a) { std::cout << (a) << std::endl; }
#define PRINTLL(a) { std::cout << std::endl << (a) << std::endl; }
#define PRINTT(a) { std::cout << (a) << st; }


int expressionEnd (const char* expression, int index){
    for (int braces{1}; braces; ++index) {
        switch(expression[index]){
            case '[':
                ++braces; break;
            case ']':
                --braces; break;                           
        };
    }
    return --index;
}

double result(char* expression, int start, int end){
    int i {start};
    double tempResult {0};
    char lastOperation {'\0'};
    while (i<end) {
        int num {0};
        if (expression[i] == '[') {
            start = ++i; i = expressionEnd(expression, i);
            //[=](){for (int j {start}; j<i; ++j) {PRINT(expression[j])} }(); PRINTV;
            num = result(expression, start, i);
        // } else if ([expression, end, i](){
        //     for (; i<end; ++i) {
        //         char ex{expression[i]};
        //         if (!IS_NUM(ex) && !IS_MLP(ex)) return false;
        //         if (IS_MLP(ex)) {; return true;}
        //         }
        //     return false;
        //     }()) {
        } else {
            for (; i<end && IS_NUM(expression[i]); ++i) num = num*10+TO_NUM(expression[i]);
        }
        switch(lastOperation) {
            case '+':
                tempResult += num; break;
            case '-':
                tempResult -= num; break;
            case '*':
                tempResult *= num; break;
            case '/':
                tempResult /= num; break;
            case '\0':
                tempResult = num; break;
            default:
                break;
        }
        if (i<end) {
            lastOperation = expression[i++];
        }
    }
    return tempResult;
}



int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "No expression provided" << std::endl;
        return 1;
    }

    char* expression = argv[1];
    int ln = [expression](){int i{0}; while (expression[i++] != '\0') ;return i;}();
    //auto len = [](char* expression){int i{0}; while(expression[i]!='\0')++i ;return i;};
    double res = result(argv[1], 0, ln);
    PRINTLL(res);
    return 0;
}
