//
// Created by benja on 15.03.2018.
//

#include "cstring.h"



String::String(){
    str = new char;
    *str = '\0';
}

String::String(std::string str) {
    this->str = (char*) &str;
}

String::String(String str){
    str = new char[str.len()];
    memcpy(this->str, str.getStr(), str.len());
}

String::String(char c){
    str = new char[2];
    *str = c;
    *(str + 1) = '\0';
}

String::String(int i){
    str = new char[2];
    *str = std::to_string(i);
    *(str + 1) = '\0';
}

String::String(double){
    str = new char[2];

    *(str + 1) = '\0';
}

String::String(bool b){
    if(b){
        str = new char[5];
        memcpy(this->str, "True", 5);
    }else{
        str = new char[6];
        memcpy(this->str, "False", 6);
    }
}

size_t String::len() const{
    return std::strlen(str);
}
char& String::getChar(size_t i){
    return *(str + i);
}

String String::subString(size_t begin, size_t end) const{
    return String();
}


String& String::operator = (const String& lhs){
    str = lhs.getStr();
}

void String::operator +=(const char* other){
    std::append();
}
