/* 
 * File:   main.cpp
 * Author: corealugly
 *
 * Created on November 2, 2015, 8:44 PM
 */

#include <CPassGen.h>
#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    CPassGen test_object;
//#--------------
    test_object.setChrStr("absd");
    test_object.setLength(3);
//#--------------
    Vstr tmp = test_object.PpassGen();
    cout << "char_mass: "  << test_object.getChrStr() << endl;
    cout << "pass_gen: " << test_object.getCountPass() << endl;
    int tmp2;
    test_object.contPass(tmp2);
    cout << "math_pass: " << tmp2 << endl;
//    (tmp == NULL) ? cout << "return: пусто" << endl : cout << "return: массив" << endl;
    test_object.printMassPass();
//#--------------
//#продсчет комбинаций пароля    
//    test_object.setChrStr("absdfghsgjdgjh");
//    int tmp;
//    for (int i = 1; i<=10; i++ )
//    {
//        test_object.setLength(i);
//        test_object.contPass(tmp, test_object.Chrstr.length(), i);
//        printf ( "pass number[%d]: %d \n", i,tmp);        
//    }
//#--------------    
    return 0;
}

