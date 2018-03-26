//
// Created by benja on 15.03.2018.
//

#ifndef STRING_CSTRING_H
#define STRING_CSTRING_H

#include <cstdio>
#include <iosfwd>
#include <string>
#include <cstring>

class String{

private:

    char* str;

public:
    String();
    String(const char* s);
    String(const String& s);
    String(const char);
    String(const int);
    String(const double);
    String(const bool);

    ~String();

    size_t len() const;
    char* getStr() const;
    char& getChar(size_t i);
    String subString(size_t begin, size_t end) const;

    bool equals(const String& s);
    bool equals(const char* c);
    String& copy(const String& s);
    String& copy(const char* c);

    String append(const String& s);
    String append(const char* c);
    void appendSelf(const String& s);
    void appendSelf(const char* c);

    //Surcharge d'operateur
    String operator + (const String&);
    String operator + (const char*);
    String& operator = (const String&);
    String& operator = (const char*);
    void operator += (const String&);
    void operator += (const char*);

    friend std::ostream& operator << (std::ostream& os, const String& s);
    friend std::ostream& operator << (std::ostream& os, const String* s);
    friend std::istream& operator >> (std::istream& is, String& s);
};

#endif //STRING_CSTRING_H
