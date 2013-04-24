#pragma once
#include<string>
using namespace std;
class Error
{
public:
	Error(void);
	~Error(void);
	void GetValue(string error){_error=error;}
	string GetReturn();
private:
	string _attr;
	string _error;
};

