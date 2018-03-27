/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 14
File        : main.cpp
Author      : Thomas Benjamin, Gobet Alain
Date        : 22.03.2018
Class       : POO - A

Goal        : Definition of a main class that will test all the  the features of the class
              String

Remark(s)   : -
----------------------------------------------------------------------------------------
*/


#include <iostream>
#include <stdexcept>
#include <cstring>
#include "cstring.h"


//------------------------Constructor/Destructor---------------------------

//Goal: Constructor
//Arguments: -
//Exceptions: -
String::String(){
    str = new char[1];                        //array for the delete[] in the destructor
    *str = '\0';
}

//Goal: Constructor
//Arguments: the value to assign to str
//Exceptions: -
String::String(const char* s){
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

//Goal: Constructor
//Arguments: the value to assign to str
//Exceptions: -
String::String(const String& s) {
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}

//Goal: Constructor
//Arguments: the value to assign to str
//Exceptions: -
String::String(char c){
    str = new char[2];
    *str = c;
    *(str + 1) = '\0';
}

//Goal: Constructor
//Arguments: the value to assign to str
//Exceptions: -
String::String(int i){
    int len = snprintf(nullptr, 0, "%d", i);
    str = new char[len + 1];
    sprintf(str, "%d", i);
    str[len] = '\0';
}

//Goal: Constructor
//Arguments: the value to assign to str
//Exceptions: -
String::String(double d){
    int len = snprintf(nullptr, 0, "%f", d);        //memory leak
    str = new char[len + 1];
    sprintf(str, "%f", d);
    str[len] = '\0';
}

//Goal: Constructor
//Arguments: the value to assign to str
//Exceptions: -
String::String(bool b){
    if(b) {
        str = new char[5];
        memcpy(str, "true", 5);     //ev const
    } else {
        str = new char[6];
        memcpy(str, "false", 6);
    }
}

//Goal: Constructor
//Arguments: the value to assign to str, the number of char to copy
//Exceptions: -
String::String(const String& s, size_t nb){ //test si nb > size (memory leak)
    str = new char[nb + 1];
    strncpy(str, s.str, nb);
    *(str + nb) = '\0';
}

//Goal: Destructor
//Arguments: -
//Exceptions: -
String::~String(){
    delete[] str;
}

//------------------------Methods-----------------------------------------

//Goal: Return the length of str
//Arguments: -
//Exceptions: -
size_t String::len() const{
    return strlen(str);
}

//Goal: Return str
//Arguments: -
//Exceptions: -
char* String::getStr() const {
    return str;
}

//Goal: Return the ith char of str (reassignable)
//Arguments: the position of the char in str
//Exceptions: invalid_argument
char& String::getChar(size_t i){
    if(i < strlen(str))
        return *(str + i);
    throw std::invalid_argument("The index value must be inferior to str's length");
}


//Goal: Return the substring of str between begin and end (limits included)
//Arguments: the position of the first char, the position of the last
//Exceptions: invalid_argument
String String::subString(size_t begin, size_t end) const {
    if(end < begin){
        size_t tmp = end;
        end = begin;
        begin = tmp;
    }
    if(end < strlen(str)){
        return  String(str + begin, end - begin + 1);
    }

    throw std::invalid_argument("The index values must be inferior to str's length");
}

//Goal: Return true if s and this are equals
//Arguments: The String to compare with this
//Exceptions: -
bool String::equals(const String& s) const{

    if(&s != this) {
        return equals(s.str);
    }

    return true;
}

//Goal: Return true if c and str are equals
//Arguments: The char* to compare str with
//Exceptions: -
bool String::equals(const char* c) const{

    if(c == str){
        return true;
    }else{
        size_t i = 0;

        while (*(str + i) == *(c + i)) {
            if(*(str + i) == '\0')
                return true;
            i++;
        }

        return false;
    }

}

//Goal: Copy the content of s in this and return a reference to this
//Arguments: The String that need to be copy in this
//Exceptions: -
String& String::copy(const String& s) {
    if (&s != this) {
        copy(s.str);
    }
    return *this;
}

//Goal: Copy the content of c in this and return a reference to this
//Arguments: The char* that need to be copy in this
//Exceptions: -
String& String::copy(const char* c) {
    if (str != c) {
        delete[] str;
        str = new char[strlen(c) + 1];
        strcpy(str, c);
    }
    return *this;
}

//Goal: Return a new String resulting from the concatenation of this and s
//Arguments: The String that need to be append
//Exceptions: -
String String::append(const String& s) const{
    return append(s.str);
}

//Goal: Return a new String resulting from the concatenation of this and c
//Arguments: The char* that need to be append
//Exceptions: -
String String::append(const char* c) const{
    char* newStr = new char[strlen(str) + strlen(c) + 1];
    strcpy(newStr, str);
    strcat(newStr, c);

    String newString = String(newStr);
    delete[] newStr;

    return newString;
}

//Goal: Append to this the content of s
//Arguments: -
//Exceptions: -
void String::appendSelf(const String& s) {
    char* tmp = new char[strlen(s.str) + 1];
    strcpy(tmp, s.str);
    appendSelf(tmp);
    delete[] tmp;
}

//Goal: Append to this the content of c (used only if c != str.this)
//Arguments: -
//Exceptions: -
void String::appendSelf(const char* c) {
    size_t strSize = strlen(str);
    char* tmp = new char[strlen(str) + 1];
    strcpy(tmp, str);
    if(str != c){
        delete[] str;
        str = new char[strSize + strlen(c) + 1];
        strcpy(str, tmp);
        strcat(str, c);
    }else{
        str = new char[strSize + strSize + 1];
        strcpy(str, tmp);
        strcat(str, c);
        delete[] c;
    }
    delete[] tmp;
}

//Goal: Reserve the size of s char to str and copy the content in str
//Arguments: The char to copy in str
//Exceptions: -
void String::reserveAndCopy(const char* s){
    delete[] str;
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

//------------------------Opertor overload-------------------------------

//Goal: Overload of the operator +
//Arguments: The String to concatenate with this
//Exceptions: -
String String::operator + (const String& s) const{
    return append(s);
}

//Goal: Overload of the operator +
//Arguments: The char* to concatenate with this
//Exceptions: -
String String::operator + (const char* c) const{
    return append(c);
}

//non present dans .h, prob friend (ou pas)
String operator + (const char* c, const String& s) {
    String newString = String(c);
    return newString.append(s);
}

//Goal: Overload of the operator =
//Arguments: The String to assign to this
//Exceptions: -
String& String::operator = (const String& s){
    if(s.str != str){
        return copy(s);
    }
    return *this;
}

//Goal: Overload of the operator =
//Arguments: The char* to assign to this
//Exceptions: -
String& String::operator = (const char* c){
    return copy(c);
}

//Goal: Overload of the operator +=
//Arguments: The String to concatenate with this
//Exceptions: -
void String::operator += (const String& s){
    appendSelf(s);
}

//Goal: Overload of the operator +=
//Arguments: The char* to concatenate with this
//Exceptions: -
void String::operator += (const char* c){
    appendSelf(c);
}

//Goal: Overload of the operator <<
//Arguments: the output stream, the String to print
//Exceptions: -
std::ostream& operator << (std::ostream& os, const String& s) {
    os << s.str;
    return os;
}

//Goal: Overload of the operator <<
//Arguments: the output stream, the String* to print
//Exceptions: -
std::ostream& operator << (std::ostream& os, const String* s) {
    os << s->str;
    return os;
}

//Goal: Overload of the operator >>
//Arguments: the input stream, the String to assign
//Exceptions: -
std::istream& operator >> (std::istream& is, String& s){
    is >> s.str;
    return is;
}