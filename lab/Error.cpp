#include "StdAfx.h"
#include "Error.h"


Error::Error(void)
{
	_attr="Error";
}


Error::~Error(void)
{
}

string Error::GetReturn(){
	string tempreturn;
	tempreturn+="(";
	tempreturn+=_attr;
	tempreturn+=",";
	tempreturn+=_error;
	tempreturn+=")";
	return tempreturn;

}

