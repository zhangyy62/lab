#pragma once
#include "StdAfx.h"
#include "INT16.h"
#include<string>
#include"str_to_int.h"

using namespace std;

INT16::INT16(void)
{
	_attr="INT16";
}


INT16::~INT16(void)
{
}

string INT16::GetReturn(){
	string tempreturn;
	tempreturn+="(";
	tempreturn+=_attr;
	tempreturn+=",";
	char t[10];
	itoa(StrToInt(_inthex.c_str()),t,10);
	tempreturn+=t;
	tempreturn+=')';
	
	return tempreturn;

}