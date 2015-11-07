/* 
 * File:   CPassGen.h
 * Author: corealugly
 *
 * Created on November 2, 2015, 8:46 PM
 */

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

#ifndef CPASSGEN_H
#define	CPASSGEN_H

typedef std::vector<std::string> Vstr;

class CPassGen {
public:
    std::string Chrstr;      //exist chars
    int length;              //length password
    std::string begin_pass; //start combination
    std::string end_pass;   //end combination
    Vstr* passMass;          //mass passwords
    int count;               //count password
//---------------------
    
//---------------------    
    CPassGen();
    CPassGen(const CPassGen& orig);
    virtual ~CPassGen();
    bool setBeginPass(std::string bgn); 
    bool setEndPass(std::string end);
    std::string getBeginPass();
    std::string getEndPass();
    bool setLength(int length);
    int  getLength();
    bool setChrStr(std::string str);
    std::string getChrStr();
    int  getCountPass();                   // получение количества сгенерированных паролей за цикл
    int  contPass(std::string str, int count_chars);       //подсчет количества возможных комбинаций пароля.
    int  contPass(int  length_pass, int count_chars);              //подсчет количества возможных комбинаций пароля.
//---------------------
    Vstr* PpassGen(int beg_n, int cur_num);
    Vstr* PpassGen();
//---------------------
    void printMassPass();    //!!!!
private:
    bool iterCharPassIndex(std::string cur_pass, int index, bool view = false);       //на удаление
    bool iterCharPassIndexV2(std::string cur_pass, int index = 1, bool debug_rec = false, bool debug_end = false);
};

#endif	/* CPASSGEN_H */

