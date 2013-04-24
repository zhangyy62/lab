#include "StdAfx.h"
#include "INT10.h"


INT10::INT10(void)
{
	_attr="INT10";
}


INT10::~INT10(void)
{
}

string INT10::GetReturn(){
	string tempreturn;
	tempreturn+="(";
	tempreturn+=_attr;
	tempreturn+=",";
	tempreturn+=_intdec;
	tempreturn+=")";
	
	return tempreturn;
}