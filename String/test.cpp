/*
-----------------------------------------------------------------------------------------
Laboratory  : POO2 - Laboratoire 14
File        : test.cpp
Author      : Thomas Benjamin, Gobet Alain
Date        : 22.03.2018
Class       : POO - A

Goal        : Definition of a class Test to test all the features of the class String

Remark(s)   : -
----------------------------------------------------------------------------------------
*/

#include <iostream>
#include <stdexcept>
#include "test.h"
#include "cstring.h"

using namespace std;

//si temps, créer fct avec lamba expr pour
//pour le return bool
//      if equals return true, else attendu/obtenu return false

//si temps, facto deux-trois prem op avec constante string pour affich
//plus choisir nb char print pour affichage homogene


Test::Test() {
    constructorTest();
    lenTest();
    getStrTest();
    getCharTest();
    substringTest();
    equalsStringTest();
    equalsCharPointerTest();
    copyStringTest();
    copyCharPointerTest();
    appendStringTest();
    appendCharPointerTest();
    appendSelfStringTest();
    appendSelfCharPointerTest();
    reserveAndCopyTest();
}

bool Test::constructorTest() const{
    cout << "------------Constructor test------------" << endl << endl;

    cout << "1) String(): " << endl;
    String emptyStr = String();
    cout << "Expected value: "  << endl;
    cout << "Obtained value: " << emptyStr.getStr() << endl << endl;


    cout << "2) String(const char* s): " << endl;
    char* charPtr = new char[4];
    *(charPtr) = 'h';
    *(charPtr + 1) = 'e';
    *(charPtr + 2) = 'y';
    *(charPtr + 3) = '\0';
    String strCharPtr = String(charPtr);
    cout << "Expected value: "  << charPtr << endl;
    cout << "Obtained value: " << (strCharPtr.getStr()) << endl << endl;
    delete[] charPtr;

    cout << "3) String(const String& s): " << endl;
    String strString = String(strCharPtr);
    cout << "Expected value: " << (strCharPtr.getStr()) << endl;
    cout << "Obtained value: " << (strString.getStr()) << endl << endl;

    cout << "4) String(char): " << endl;
    String strChar = String('?');
    cout << "Expected value: ?" << endl;
    cout << "Obtained value: " << (strChar.getStr()) << endl << endl;

    cout << "5) String(int): " << endl;
    String strInt = String(17456);
    cout << "Expected value: 17456" << endl;
    cout << "Obtained value: " << (strInt.getStr()) << endl << endl;

    cout << "6) String(double): " << endl;
    String strDouble = String(-1.144);
    cout << "Expected value: -1.144" << endl;
    cout << "Obtained value: " << (strDouble.getStr()) << endl << endl;

    cout << "7) String(bool): " << endl;
    String strBool = String(true);
    cout << "Expected value: true" << endl;
    cout << "Obtained value: " << (strBool.getStr()) << endl << endl;

    cout << "8) String(bool): " << endl;
    String strnCopy = String(strBool, 3);
    cout << "Expected value: tru" << endl;
    cout << "Obtained value: " << (strnCopy.getStr()) << endl << endl;
}

bool Test::lenTest() const{
    String strInt(17456);
    cout << "------------len() test------------" << endl << endl;
    cout << "Expected value: 5" << endl;
    cout << "Obtained value: " << strInt.len() << endl << endl;
}

bool Test::getStrTest() const{
    String strInt(17456);
    cout << "------------getStr() test------------" << endl << endl;
    cout << "Expected value: 17456" << endl;
    cout << "Obtained value: " << (strInt.getStr()) << endl << endl;
}

bool Test::getCharTest() const{
    String strInt(17456);
    cout << "------------getChar() test------------" << endl << endl;

    cout << "1) Basic test" << endl;
    cout << "Expected value: 4" << endl;
    cout << "Obtained value: " << strInt.getChar(2) << endl << endl;

    cout << "2) Modification test" << endl;
    strInt.getChar(2) = '5';
    cout << "Expected value: 5" << endl;
    cout << "Obtained value: " << strInt.getChar(2) << endl << endl;

    cout << "3) Out of limit test" << endl;
    cout << "Expected value: The index value must be inferior to str's length" << endl;
    cout << "Obtained value: ";

    try{
        strInt.getChar(10);
    }catch(const invalid_argument& e){
        cout << e.what() << endl << endl;
    }

}

bool Test::substringTest() const{
    String strInt(17456);
    cout << "------------substring() test------------" << endl << endl;
    cout << "1) Basic test:" << endl;
    cout << "Expected value: 45" << endl;
    cout << "Obtained value: " << strInt.subString(2, 3) << endl << endl;

    cout << "2) Inverted limits test:" << endl;
    cout << "Expected value: 45" << endl;
    cout << "Obtained value: " << strInt.subString(3, 2) << endl << endl;

    cout << "3) Out of limits test:" << endl;
    cout << "Expected value: The index values must be inferior to str's length" << endl;
    cout << "Obtained value: ";

    try{
        strInt.subString(2, 10);
    }catch(const invalid_argument& e){
        cout << e.what() << endl << endl;
    }
}

bool Test::equalsStringTest() const{
    String strInt1(17456);
    String strInt2(17456);
    String strInt3(174456);

    cout << "------------equals(const String&) test------------" << endl << endl;
    cout << "1) True result test: " << endl;
    cout << "Expected value: 1" << endl;
    cout << "Obtained value: " << strInt1.equals(strInt2) << endl << endl;

    cout << "2) False result test: " << endl;
    cout << "Expected value: 0" << endl;
    cout << "Obtained value: " << strInt1.equals(strInt3) << endl << endl;
}

bool Test::equalsCharPointerTest() const{

    String strInt(17);

    char* charPtr1 = new char[3];
    *(charPtr1) = '1';
    *(charPtr1 + 1) = '7';
    *(charPtr1 + 2) = '\0';

    char* charPtr2 = new char[2];
    *(charPtr2) = 'h';
    *(charPtr2 + 1) = '\0';

    cout << "------------equals(const char*) test------------" << endl << endl;
    cout << "1) True result test: " << endl;
    cout << "Expected value: 1" << endl;
    cout << "Obtained value: " << strInt.equals(charPtr1) << endl << endl;

    cout << "2) False result test: " << endl;
    cout << "Expected value: 0" << endl;
    cout << "Obtained value: " << strInt.equals(charPtr2) << endl << endl;

    delete[] charPtr1;
    delete[] charPtr2;
}

bool Test::copyStringTest() const{
    String strInt1(17456);
    String strInt2(1235);
    cout << "------------copy(const String&) test------------" << endl << endl;
    cout << "Expected value: 1235" << endl;
    cout << "Obtained value: " << strInt1.copy(strInt2) << endl << endl;
}

bool Test::copyCharPointerTest() const{
    String strInt(2342);

    char* charPtr = new char[3];
    *(charPtr) = '1';
    *(charPtr + 1) = '7';
    *(charPtr + 2) = '\0';

    cout << "------------copy(const char*) test------------" << endl << endl;
    cout << "Expected value: 17" << endl;
    cout << "Obtained value: " << strInt.copy(charPtr) << endl << endl;

    delete[] charPtr;
}

bool Test::appendStringTest() const{
    String strInt(17456);
    cout << "------------append(const String&) test------------" << endl << endl;
    cout << "Expected value: 1745617456" << endl;
    cout << "Obtained value: " << strInt.append(strInt) << endl << endl;
}

bool Test::appendCharPointerTest() const{
    String strInt(2342);

    char* charPtr = new char[3];
    *(charPtr) = '1';
    *(charPtr + 1) = '7';
    *(charPtr + 2) = '\0';

    cout << "------------append(const char*) test--------------" << endl << endl;
    cout << "Expected value: 234217" << endl;
    cout << "Obtained value: " << strInt.append(charPtr) << endl << endl;

    delete[] charPtr;
}

bool Test::appendSelfStringTest() const{
    String strInt1(17456);
    String strInt2(1235);

    cout << "------------appendSelf(const String&) test----------" << endl << endl;
    cout << "1) Basic test: " << endl;
    cout << "Expected value: 174561235" << endl;
    strInt1.appendSelf(strInt2);
    cout << "Obtained value: " << strInt1 << endl << endl;

    cout << "2) Append this to this test: " << endl;
    cout << "Expected value: 12351235" << endl;
    strInt2.appendSelf(strInt2);
    cout << "Obtained value: " << strInt2 << endl << endl;
}

bool Test::appendSelfCharPointerTest() const{
    String strInt(2342);

    char* charPtr = new char[3];
    *(charPtr) = '1';
    *(charPtr + 1) = '7';
    *(charPtr + 2) = '\0';

    cout << "------------appendSelf(const char*) test--------------" << endl << endl;
    cout << "Expected value: 234217" << endl;
    strInt.appendSelf(charPtr);
    cout << "Obtained value: " << strInt << endl << endl;

    delete[] charPtr;

}

bool Test::reserveAndCopyTest() const{
    String strInt(2342);

    char* charPtr = new char[3];
    *(charPtr) = '1';
    *(charPtr + 1) = '7';
    *(charPtr + 2) = '\0';

    cout << "------------reserveAndCopy(const char* s) test----------" << endl << endl;
    cout << "Expected value: 17" << endl;
    strInt.reserveAndCopy(charPtr);
    cout << "Obtained value: " << strInt << endl << endl;

    delete[] charPtr;

}
