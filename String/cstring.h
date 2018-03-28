/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 14
File        : cstring.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 22.03.2018
Class       : POO - A

Goal        : Declaration of a class String similar to std::string

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef STRING_CSTRING_H
#define STRING_CSTRING_H


//Pre-declaration of the class String for the << overload
class String;

//Declaration of the operator << overload
std::ostream& operator << (std::ostream& os, const String& s);
std::ostream& operator << (std::ostream& os, const String* s);
std::istream& operator >> (std::istream& is, String& s);


class String{

private:

    char* str;          //Contains the string value of this

public:

//------------------------Constructor/Destructor---------------------------
    //Goal: Constructor
    //Arguments: -
    //Exceptions: -
    String();

    //Goal: Constructor
    //Arguments: the value to assign to str
    //Exceptions: -
    String(const char* s);

    //Goal: Constructor
    //Arguments: the value to assign to str
    //Exceptions: -
    String(const String& s);

    //Goal: Constructor
    //Arguments: the value to assign to str
    //Exceptions: -
    String(char);

    //Goal: Constructor
    //Arguments: the value to assign to str
    //Exceptions: -
    String(int);

    //Goal: Constructor
    //Arguments: the value to assign to str
    //Exceptions: -
    String(double);

    //Goal: Constructor
    //Arguments: the value to assign to str
    //Exceptions: -
    String(bool);

    //Goal: Constructor
    //Arguments: the value to assign to str, the number of char to copy
    //Exceptions: -
    String(const String& s, size_t nb);

    //Goal: Destructor
    //Arguments: -
    //Exceptions: -
    ~String();

//------------------------Methods-----------------------------------------
    //Goal: Return the length of str
    //Arguments: -
    //Exceptions: -
    size_t len() const;

    //Goal: Return str
    //Arguments: -
    //Exceptions: -
    char* getStr() const;

    //Goal: Return the ith char of str (reassignable)
    //Arguments: the position of the char in str
    //Exceptions: invalid_argument
    char& getChar(size_t i);

    //Goal: Return the substring of str between begin and end (limits included)
    //Arguments: the position of the first char, the position of the last
    //Exceptions: invalid_argument
    String subString(size_t begin, size_t end) const;

    //Goal: Return true if s and this are equals
    //Arguments: The String to compare with this
    //Exceptions: -
    bool equals(const String& s) const;

    //Goal: Return true if c and str are equals
    //Arguments: The char* to compare str with
    //Exceptions: -
    bool equals(const char* c) const;

    //Goal: Copy the content of s in this and return a reference to this
    //Arguments: The String that need to be copy in this
    //Exceptions: -
    String& copy(const String& s);

    //Goal: Copy the content of c in this and return a reference to this
    //Arguments: The char* that need to be copy in this
    //Exceptions: -
    String& copy(const char* c);

    //Goal: Return a new String resulting from the concatenation of this and s
    //Arguments: The String that need to be append
    //Exceptions: -
    String append(const String& s) const;

    //Goal: Return a new String resulting from the concatenation of this and c
    //Arguments: The char* that need to be append
    //Exceptions: -
    String append(const char* c) const;

    //Goal: Append to this the content of s
    //Arguments: -
    //Exceptions: -
    void appendSelf(const String& s);

    //Goal: Append to this the content of c
    //Arguments: -
    //Exceptions: -
    void appendSelf(const char* c);

    //Goal: Reserve the size of s char to str and copy the content in str
    //Arguments: The char to copy in str
    //Exceptions: -
    void reserveAndCopy(const char* s);

//------------------------Opertor overload-------------------------------

    //Goal: Overload of the operator +
    //Arguments: The String to concatenate with this
    //Exceptions: -
    String operator + (const String&) const;

    //Goal: Overload of the operator +
    //Arguments: The char* to concatenate with this
    //Exceptions: -
    String operator + (const char*) const;

    //Goal: Overload of the operator +
    //Arguments: The char*, the String to concatenate
    //Exceptions: -
    friend String operator + (const char* c, const String& s);

    //Goal: Overload of the operator =
    //Arguments: The String to assign to this
    //Exceptions: -
    String& operator = (const String&);

    //Goal: Overload of the operator =
    //Arguments: The char* to assign to this
    //Exceptions: -
    String& operator = (const char*);

    //Goal: Overload of the operator +=
    //Arguments: The String to concatenate with this
    //Exceptions: -
    void operator += (const String&);

    //Goal: Overload of the operator +=
    //Arguments: The char* to concatenate with this
    //Exceptions: -
    void operator += (const char*);

    //Goal: Overload of the operator <<
    //Arguments: the output stream, the String to print
    //Exceptions: -
    friend std::ostream& operator << (std::ostream& os, const String& s);

    //Goal: Overload of the operator <<
    //Arguments: the output stream, the String* to print
    //Exceptions: -
    friend std::ostream& operator << (std::ostream& os, const String* s);

    //Goal: Overload of the operator >>
    //Arguments: the input stream, the String to assign
    //Exceptions: -
    friend std::istream& operator >> (std::istream& is, String& s);
};

#endif //STRING_CSTRING_H
