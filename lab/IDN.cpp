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

	  for(int n=0;n<5;n++)                  //��ʶ��������ַ����Ѷ���ı�ʾ�����Ƚϣ� 
		  if(stricmp(_idn.c_str(), _keyword[n])==0)      //��Сд�޹ص���ؼ��ֱȽ�
            {
				string idnr="(";              //���ֵ
				idnr+=_idn;
				idnr+=",_)";
                  return idnr;
                break;
            }
		  
		  
			  string idnr="(";              //���ֵ
				idnr+=_attr;
				idnr+=",";
				idnr+=_idn;
				idnr+=")";
                  return idnr;

		  

	}