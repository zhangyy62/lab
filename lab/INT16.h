#pragma once
#include<string>
using namespace std;
class INT16
{
public:
	INT16(void);
	~INT16(void);
	void GetValue(string int16){_inthex=int16;}
	string GetReturn();
private:
	string _attr;
	string _inthex;
};

