#include <iostream>
#include <cstdio>

const int SIZE = 500;
void getInput (char *a) {
    char single_char;
    int length_count = 0;
    while(length_count < SIZE && !std::cin.eof()) {
        std::cin >> single_char;
        if(single_char == '\n') break;
        *(a+length_count) = single_char;
        length_count++;
    }

}

void initStr (char *a) {
    for (int i = 0; i < SIZE; ++i) {
        *(a+i) = '\0';
    }
}


int countLength (char* a) {
    int length = 0;
    while(a[length] != '\0') length++;
    return length;
}

void output (char* a,int length) {
    std::cout << '"';
    for (int i = 0 ; i < length; ++i) std::cout << *(a+i);
    std::cout << '"';
    std::cout << '\n';
}

void rev (char *a, int length) {
    for (int i = 0; i < length/2; i++) {
        char tmp = *(a+i);
        *(a+i) = *(a+length-i-1);
        *(a+length-i-1) = tmp;
    }
}

void delc(char* a, char c, int& length) {
    int i = 0;
    while (i < length) {
        if (*(a+i) == c) {
            length--;
            for (int j = i; j < length; j++) *(a+j) = *(a+j+1);
        } else {
            i++;
        }
    }
}

int main() {
    char a[SIZE];
    initStr(a);
    getInput(a);
    int length = countLength(a);
    std::cout << "Raw: ";
    output(a,length);

    rev(a,length);
    std::cout << "Rev: ";
    output(a,length);

    std::cout << "Del char: ";
    char c;
    std::cin >> c;
    delc(a,c,length);
    std::cout << "After del char: ";
    output(a,length);
}


