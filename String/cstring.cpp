//
// Created by benja on 15.03.2018.
//

#include <iostream>
#include "cstring.h"

using namespace std;

String::String(){
    str = new char;
    *str = '\0';
}

String::String(const char* s){
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

String::String(const String& s) {
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}

String::String(const char c){
    str = new char[2];
    str[0] = c;
    str[1] = '\0';
}

String::String(const int i){
    int len = snprintf(nullptr, 0, "%d", i) + 1;
    str = new char[len];
    sprintf(str, "%d", i);
    str[len - 1] = '\0';
}

String::String(const double d){
    int len = snprintf(nullptr, 0, "%f", d) + 1;
    str = new char[len];
    sprintf(str, "%f", d);
    str[len - 1] = '\0';
}

String::String(const bool b){
    if(b) {
        str = new char[5];
        memcpy(str, "true", 5);
    } else {
        str = new char[6];
        memcpy(str, "false", 6);
    }
}

String::~String(){
    delete[] str;
}

size_t String::len() const{
    return strlen(str);
}

char* String::getStr() const {
    char* strChar = new char[strlen(str) +1];
    strcpy(strChar, str);

    return strChar;
}

char& String::getChar(size_t i){
    return str[i-1];
}

// Retourne les bornes comprises
String String::subString(size_t begin, size_t end) const {
    size_t tmpEnd = (end - begin + 1);
    char * tmp = new char[tmpEnd];

    for (size_t i = begin - 1 ; i < end ; i++) {
        tmp[(i + 1) - begin] = str[i];
    }

    tmp[tmpEnd] = '\0';

    return  String(tmp);
}

bool String::equals(const String& s) {
    bool eq = &s == this;

    if (!eq)
        eq = equals(s.str);

    return eq;
}

bool String::equals(const char* c) {
    int i = 0;
    bool eq = strlen(str) == strlen(c);

    while (eq && i < strlen(str)) {
        eq = str[i] == c[i];
        i++;
    }

    return eq;
}

String& String::copy(const String& s) {
    if (&s != this) {
        copy(s.str);
    }
    return *this;
}

String& String::copy(const char* c) {
    delete[] str;
    str = new char[strlen(c) + 1];
    strcpy(str, c);

    return *this;
}

String String::append(const String& s) {
    String newString;

    newString = append(s.str);

    return newString;
}

String String::append(const char* c) {
    String newString;
    char* newStr = new char[strlen(str) + strlen(str) + 1];
    strcpy(newStr, str);
    strcat(newStr, c);

    newString = String(newStr);

    return newString;
}

void String::appendSelf(const String& s) {
    // permet de fonctionner, même si s = this
    char* app = new char[strlen(str) + 1];
    strcpy(app, s.str);

    appendSelf(app);
}

void String::appendSelf(const char* c) {
    char* tmp = new char[strlen(str) + 1];
    strcpy(tmp, str);

    delete[] str;
    str = new char[strlen(str) + strlen(str) + 1];
    strcpy(str, tmp);
    strcat(str, c);
}

String& String::operator = (const String& s){
    return copy(s);
}

String& String::operator = (const char* c){
    return copy(c);
}

String String::operator + (const String& s){
    return append(s);
}

String String::operator + (const char* c){
    return append(c);
}

void String::operator += (const String& s){
    appendSelf(s);
}

void String::operator += (const char* c){
    appendSelf(c);
}

String operator + (const char* c, const String& s) {
    String newString = String(c);

    return newString.append(s);
}

ostream& operator << (ostream& os, const String& s) {
    os << s.str;

    return os;
}

ostream& operator << (ostream& os, const String* s) {
    os << s->str;

    return os;
}

istream& operator >> (istream& is, String& s){
    is >> s.str;
    return is;
}