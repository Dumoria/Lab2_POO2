//
// Created by benja on 15.03.2018.
//

#ifndef STRING_CSTRING_H
#define STRING_CSTRING_H

#include <cstdio>
#include <iosfwd>

class String{

private:

    const char* str;

public:

    String();
    String(string);
    String(String);
    String(char);
    String(int);
    String(double);
    String(bool);

    int len() const;
    char& getChar(size_t i);
    String subString(size_t begin, size_t end);




    //Surcharge d'operateur

    friend std::ostream& operator << (std::ostream& lhs, const String& rhs);


};

#endif //STRING_CSTRING_H
