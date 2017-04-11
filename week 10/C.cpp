#include <iostream>

const int INIT_LENGTH = 10;

class MyString {
public:
    MyString(const char* initStr);
    void append (const char* appendStr);
    void printStr();
    ~MyString();
private:
    char* _str = nullptr;
    int _n;
    int _arr_length;
};

char* realloc (const char* oldStr, int old_length,int new_length){
    char* newStr = new char(new_length);
    for(int i = 0; i < old_length; ++ i) {
            newStr[i] = *(oldStr+i);
    }
    delete oldStr;
    return newStr;
}


void MyString::append(const char* appendStr) {
     int appendItr = 0;
     while(*(appendStr+appendItr) != '\0') {
            if( (_n+appendItr) < _arr_length) {
                _str[_n+appendItr] = *(appendStr+appendItr);
                appendItr++;
            } else {
                _arr_length = _arr_length*2;
                _str = realloc (_str,_n+appendItr,_arr_length);
            }
    }
    _n = _n+appendItr;
}

MyString::MyString(const char* initStr) {
    if(!initStr) std::cout << "Passed null string";
    else {
        _n = 0;
        _arr_length = INIT_LENGTH;
        _str = new char(_arr_length);
        append(initStr);
    }
}

void MyString::printStr() {
    for(int i = 0; i < _n; ++i) {
        std::cout << *(_str + i);
    }
}

MyString::~MyString() {
    delete _str;
}

int main(){
    MyString greeting("Hello");
    greeting.printStr();
    std::cout << '\n';
    greeting.append(" Phong! cho no qua 20 ky tu di!");
    greeting.printStr();
}
