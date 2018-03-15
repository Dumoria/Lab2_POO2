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
    String(std::string);
    String(String);
    String(char);
    String(int);
    String(double);
    String(bool);

    size_t len() const;
    char& getChar(size_t i);
    String subString(size_t begin, size_t end) const;
    char* getStr() const;




    //Surcharge d'operateur

    friend std::ostream& operator << (std::ostream& lhs, const String& rhs);
    String& operator = (const String&);
    void operator +=(const char* other);



};

#endif //STRING_CSTRING_H
