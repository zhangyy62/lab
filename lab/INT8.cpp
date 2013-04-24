#pragma once
#include "StdAfx.h"
#include "INT8.h"
#include"str_to_int.h"
//#include<stdio.h>
INT8::INT8(void)
{
	_attr="INT8";
}


INT8::~INT8(void)
{
}

string INT8::GetReturn(){
	string tempreturn;
	tempreturn+="(";
	tempreturn+=_attr;
	tempreturn+=",";
	char t[10];
	itoa(StrToInt(_intoct.c_str()),t,10);
	tempreturn+=t;
	tempreturn+=")";
	
	return tempreturn;
}
