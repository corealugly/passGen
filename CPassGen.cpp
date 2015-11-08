/* 
 * File:   CPassGen.cpp
 * Author: corealugly
 * 
 * Created on November 2, 2015, 8:46 PM
 */

#include "CPassGen.h"

using namespace std; 

CPassGen::CPassGen() {
    this->Chrstr = "";
    this->begin_pass = "";
    this->end_pass = "";
    this->count = 0;
    this->length = 0;
}

CPassGen::CPassGen(const CPassGen& orig) {
}

CPassGen::~CPassGen() {
}

bool CPassGen::setBeginPass(std::string bgn) {
    this->begin_pass = bgn;
}

bool CPassGen::setEndPass(std::string end) {
    this->end_pass = end;
}

int CPassGen::getCountPass() {
    return this->count;     
}

std::string CPassGen::getBeginPass() {
    return this->begin_pass;     
}

std::string CPassGen::getEndPass() {
    return this->end_pass;     
}

bool CPassGen::setLength(int length) {
    this->length = length;
}

int  CPassGen::getLength() {
    return this->length;
}

bool CPassGen::setChrStr(std::string str) {
    this->Chrstr = str;
}

std::string CPassGen::getChrStr() {
    return this->Chrstr;
}

bool CPassGen::contPass(int& output) {
    if (this->Chrstr == "" or this->length == 0) { return false; }
    output = pow(this->Chrstr.length(), this->length);
    return  true;
}

bool CPassGen::contPass(int& output ,int count_chars, int length_pass) {
    if (count_chars == 0 or length_pass ==0 ) { return false; }
    output = pow(count_chars, length_pass);
    return true; 
}

Vstr CPassGen::PpassGen(int beg_n, int cur_num) {
    
}

//Vstr* CPassGen::PpassGen(int lenght_pass) {
//    std::string cur_pass = "1";
//    if (this->Chrstr == "") { return NULL; }
//    std::cout << cur_pass.length() << std::endl;
//    for (int idx = 0; idx < this->Chrstr.length() ; idx++)
//    {
//        iterCharPassIndex("hgyuuyc",0);        
//    }
//    
////    std::cout << this->Chrstr << std::endl;
////    std::cout << this->Chrstr[this->Chrstr.length()-1] << std::endl;
////    std::string str1 = new  std::string();
////    std::string str2 = new  std::string();
//    
//    
//}

Vstr CPassGen::PpassGen() {
     std::string cur_pass = "";
     if (this->Chrstr != "" or this->length != 0) 
     { 
        for (int i = 0; i < this->length; i++) { cur_pass.append("*"); } 
//#-------
        int scope_pass;
        this->contPass(scope_pass);
        this->passMass.resize(scope_pass);
//#-------    
        iterCharPassIndexV2(cur_pass,1, false, true);
     }
}

bool CPassGen::iterCharPassIndexV2(std::string cur_pass, int index, bool debug_rec, bool debug_end) {
    
    if (cur_pass.length() == 0) 
    {
        if (index > 1) { index = 1; }
        iterCharPassIndexV2(cur_pass.append("^"), index);
    }
    
    if (index > cur_pass.length())
    {
        iterCharPassIndexV2(cur_pass.append("*"), index);
    }
    
    if (index < cur_pass.length()) 
    { 
        for (int i = 0; i < this->Chrstr.length(); i++ )
        {
            cur_pass[index-1] = this->Chrstr[i];
            if (debug_rec) { cout << "pass: "<< cur_pass << endl; } 
            iterCharPassIndexV2(cur_pass, index+1, debug_rec, debug_end);
        }
    }
    
    if (index == cur_pass.length())
    {
        for (int i = 0; i < this->Chrstr.length(); i++ )
        {
            cur_pass[index-1] = this->Chrstr[i];
//          #внесенние в массив
            this->passMass[this->count] = cur_pass;
            if (debug_end) { this->count++; cout << "pass: "<< cur_pass << endl; } 
        }
    }
}


bool CPassGen::iterCharPassIndex(std::string cur_pass, int index, bool view) {
    if (index < 0 or index>cur_pass.length()-1) { return false; }
    for (int idx = 0; idx<this->Chrstr.length(); idx++) 
    {
        cur_pass[index] = this->Chrstr[idx];
//        #занесение пароля в массив.
        if (view) { std::cout << "password:  " << cur_pass << std::endl; }       
    }
    return true;
}

void CPassGen::printMassPass() {
    for (int i = 0; i<this->passMass.size(); i++)
    {
        std::cout << "pass: " << this->passMass[i] << ";" << std::endl; 
    }
}

//bool CPassGen::PpassGen() {
// setCh   
//}