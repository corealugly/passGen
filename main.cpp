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
//    test_object.printMassPass();
    test_object.setChrStr("123abc");
    cout << "char_mass: "  << test_object.getChrStr() << endl;
    
    
    Vstr* tmp = test_object.PpassGen(3);
    cout << "pass_gen: " << test_object.getCountPass() << endl;
    
    (tmp == NULL) ? cout << "return: пусто" << endl : cout << "return: массив" << endl;
//    for (int i = 1; i<10; i++ )
//    {
//        std::cout << test_object.contPass(test_object.Chrstr, i) <<std::endl;        
//    }
    return 0;
}

