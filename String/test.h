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

    Test();
    bool constructorTest() const;
    bool lenTest() const;
    bool getStrTest() const;
    bool getCharTest() const;
    bool substringTest() const;
    bool equalsStringTest() const;
    bool equalsCharPointerTest() const;
    bool copyStringTest() const;
    bool copyCharPointerTest() const;
    bool appendStringTest() const;
    bool appendCharPointerTest() const;
    bool appendSelfStringTest() const;
    bool appendSelfCharPointerTest() const;
    bool reserveAndCopyTest() const;
    bool operatorEqualStringTest() const;
    bool operatorEqualCharPointerTest() const;
    bool operatorStringPlusStringTest() const;
    bool operatorStringPlusCharPointerTest() const;
    bool operatorCharPointerPlusStringTest() const;
    bool operatorPlusEqualStringTest() const;
    bool operatorPlusEqualCharPointerTest() const;
    bool operatorCinTest() const;
};
#endif //STRING_TEST_H
