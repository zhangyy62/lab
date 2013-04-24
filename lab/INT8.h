#pragma once
#include<string>
#include<stdio.h>

using namespace std;
class INT8
{
public:
	INT8(void);
	~INT8(void);
	string GetReturn();
	void GetValue(string int8){_intoct=int8;}
private:
	string _attr;
	string _intoct;
};

