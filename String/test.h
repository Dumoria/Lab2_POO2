/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 14
File        : test.h
Author      : Thomas Benjamin, Gobet Alain
Date        : 22.03.2018
Class       : POO - A

Goal        : Declaration of a class Test to test all the features of the class String

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#ifndef STRING_TEST_H
#define STRING_TEST_H


class Test{

public:

    //Goal: Test constructor
    //Arguments: -
    //Exceptions: -
    Test();

    //Goal: Test the constructors
    //Arguments: -
    //Exceptions: -
    bool constructorTest() const;

    //Goal: Test the len() method
    //Arguments: -
    //Exceptions: -
    bool lenTest() const;

    //Goal: Test the getStr() method
    //Arguments: -
    //Exceptions: -
    bool getStrTest() const;

    //Goal: Test the getChar() method
    //Arguments: -
    //Exceptions: invalid_argument
    bool getCharTest() const;

    //Goal: Test the subString() method
    //Arguments: -
    //Exceptions: invalid_argument
    bool substringTest() const;

    //Goal: Test the equals() method with a String
    //Arguments: -
    //Exceptions: -
    bool equalsStringTest() const;

    //Goal: Test the equals() method with a char*
    //Arguments: -
    //Exceptions: -
    bool equalsCharPointerTest() const;

    //Goal: Test the copy() method with a String
    //Arguments: -
    //Exceptions: -
    bool copyStringTest() const;

    //Goal: Test the copy() method with a char*
    //Arguments: -
    //Exceptions: -
    bool copyCharPointerTest() const;

    //Goal: Test the append() method with a String
    //Arguments: -
    //Exceptions: -
    bool appendStringTest() const;

    //Goal: Test the append() method with a char*
    //Arguments: -
    //Exceptions: -
    bool appendCharPointerTest() const;

    //Goal: Test the appendSelf() method with a String
    //Arguments: -
    //Exceptions: -
    bool appendSelfStringTest() const;

    //Goal: Test the appendSelf() method with a char*
    //Arguments: -
    //Exceptions: -
    bool appendSelfCharPointerTest() const;

    //Goal: Test the reserveAndCopy() method with
    //Arguments: -
    //Exceptions: -
    bool reserveAndCopyTest() const;

    //Goal: Test the overload of the = operator with a String
    //Arguments: -
    //Exceptions: -
    bool operatorEqualStringTest() const;

    //Goal: Test the overload of the = operator with a char*
    //Arguments: -
    //Exceptions: -
    bool operatorEqualCharPointerTest() const;

    //Goal: Test the overload of the + operator with String + String
    //Arguments: -
    //Exceptions: -
    bool operatorStringPlusStringTest() const;

    //Goal: Test the overload of the + operator with String + char*
    //Arguments: -
    //Exceptions: -
    bool operatorStringPlusCharPointerTest() const;

    //Goal: Test the overload of the + operator with char* + String
    //Arguments: -
    //Exceptions: -
    bool operatorCharPointerPlusStringTest() const;

    //Goal: Test the overload of the += operator with a String
    //Arguments: -
    //Exceptions: -
    bool operatorPlusEqualStringTest() const;

    //Goal: Test the overload of the += operator with a char*
    //Arguments: -
    //Exceptions: -
    bool operatorPlusEqualCharPointerTest() const;

    //Goal: Test the overload of the operator <<
    //Arguments: -
    //Exceptions: -
    bool operatorCinTest() const;
};
#endif //STRING_TEST_H
