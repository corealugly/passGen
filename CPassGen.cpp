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

int CPassGen::contPass() {
//    if (this->Chrstr == "" or this->length == 0) { return NULL; }
    return  pow(this->Chrstr.length(), this->length);
}

int CPassGen::contPass(int count_chars, int length_pass) {
    return  pow(count_chars, length_pass);
}

Vstr* CPassGen::PpassGen(int beg_n, int cur_num) {
    
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

Vstr* CPassGen::PpassGen() {
    std::string cur_pass = "";
    if (this->Chrstr == "" or this->length == 0) { return NULL; }
    for (int i = 0; i < this->length; i++) { cur_pass.append("*"); } 
    iterCharPassIndexV2(cur_pass,1, false, true);
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
            if (debug_end) { this->count++; /* cout << "pass: "<< cur_pass << endl; */ } 
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
    std::cout << "test" << std::endl; 
}

//bool CPassGen::PpassGen() {
// setCh   
//}