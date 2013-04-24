#pragma once
#include<string>
using namespace std;
class INT10
{
public:
	INT10(void);
	~INT10(void);
	void GetValue(string int10){_intdec=int10;}
	string GetReturn();
private:
	string _attr;
	string _intdec;
};

