#include "StdAfx.h"
#include "OP.h"
#include<string>
using namespace std;

OP::OP(void)
{
}


OP::~OP(void)
{
}

string OP::GetReturn(){
	string tempreturn;
	tempreturn+="(";
	tempreturn+=_op;
	tempreturn+=",";
	tempreturn+="_";
	tempreturn+=")";
	
	return tempreturn;
}