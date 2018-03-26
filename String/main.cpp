#include <iostream>
#include "cstring.h"

using namespace std;

int main() {
    String* str = new String("String De Test");
    String* strch = new String('?');
    String* strint = new String(17456);
    String* strdbl = new String(-1.144);
    String* strbool = new String(false);
    String* stregl;

    String stregl2;
    String stregl3;
    String stregl4;
    String inputstr;

    String* str2;
    char * chr = str->getStr();

    inputstr = "1234";

    cout << "Enter your string" << endl;
    cin >> inputstr;
    cout << "Vous avez entré : " << inputstr << endl;

    stregl = str;

    cout << strch << endl;
    cout << strint << endl;
    cout << strdbl << endl;
    cout << strbool << endl;
    cout << str->len() << endl;
    cout << str->getChar(3) << endl;
    cout << stregl << endl;

    stregl2 = "test";
    stregl3 = stregl2;
    stregl4 = "tesr";

    cout << (stregl2.equals(stregl2)) << endl;
    cout << (stregl2.equals(stregl3)) << endl;
    cout << (stregl2.equals(stregl4)) << endl;

    cout << stregl2 << endl;

    stregl4 = stregl2.append(stregl3);

    cout << stregl4 << endl;

    printf("\n");
    printf(chr);
    printf("\n");

    str->getChar(6) = 'r';

    chr = str->getStr();

    cout << chr << endl;

    str2 = new String(str->subString(3, 7));

    cout << str2 << endl;

    stregl3 = "test de";
    stregl4 = " concatenation";

    stregl3 += stregl4 + " reussie";

    cout << stregl3 << endl;

    delete str;
    delete str2;
    delete chr;
    delete strch;
    delete strint;
    delete strdbl;
    delete strbool;
    delete stregl;

    return EXIT_SUCCESS;
}