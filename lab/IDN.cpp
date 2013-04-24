#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include"IDN.h"
using namespace std;


IDN::IDN(){
	_attr="IDN";
	_keyword[0]="if";
	_keyword[1]="else";
	_keyword[2]="while";
	_keyword[3]="then";
	_keyword[4]="do";
}


 string IDN::ReturnTuple(){

	  for(int n=0;n<5;n++)                  //将识别出来的字符和已定义的标示符作比较， 
		  if(stricmp(_idn.c_str(), _keyword[n])==0)      //大小写无关的与关键字比较
            {
				string idnr="(";              //输出值
				idnr+=_idn;
				idnr+=",_)";
                  return idnr;
                break;
            }
		  
		  
			  string idnr="(";              //输出值
				idnr+=_attr;
				idnr+=",";
				idnr+=_idn;
				idnr+=")";
                  return idnr;

		  

	}