/* 
 * File:   main.cpp
 * Author: corealugly
 *
 * Created on November 2, 2015, 8:44 PM
 */

#include <CPassGen.h>
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    CPassGen test_object;
//#--------------
    test_object.setChrStr("absdfghsgjdgjh");    
    test_object.setLength(5);
//#--------------
    Vstr* tmp = test_object.PpassGen();
    cout << "char_mass: "  << test_object.getChrStr() << endl;
    cout << "pass_gen: " << test_object.getCountPass() << endl;
//    cout << "score_pass: " << test_object.contPass(test_object.getChrStr().length(), test_object.getLength()) << endl;
//    (tmp == NULL) ? cout << "return: пусто" << endl : cout << "return: массив" << endl;

//#--------------
//#продсчет комбинаций пароля    
        for (int i = 1; i<10; i++ )
    {
        std::cout << test_object.contPass(test_object.Chrstr, i) <<std::endl;        
    }
//#--------------    
    return 0;
}

