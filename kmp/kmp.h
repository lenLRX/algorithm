#ifndef __KMP_H__
#define __KMP_H__
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int kmp(string text, string pattern);
vector<int> BuildNext(string pattern);

#endif//__KMP_H__