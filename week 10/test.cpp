#include <iostream>

int main() {
    char *str = "hello";
    int length = 0;
    while(*(str+length)!='\0'){
        length++;
    }
    std::cout << length;
}
