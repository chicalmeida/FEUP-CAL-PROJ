//
// Created by ultra on 23/05/2021.
//
#include "utils.h"
using namespace std;
bool isNumber(const string &str){
    for(int i=0; i<str.length(); i++){
        if(str.charAt(i) > '9' || str.charAt(i) < '0'){
            return false;
        }
    }
    return true;
}


