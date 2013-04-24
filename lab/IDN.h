#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;

class IDN{
public:
	IDN();
	void GetIdn(string idns){_idn=idns;}
	void GetKeyword(char *keyword[5]){
		for(int i=0;i<5;i++)
			_keyword[i]=keyword[i];

	}
	string ReturnTuple();
private: 
	string _idn;
	char *_keyword[5];
	string _attr;
};

