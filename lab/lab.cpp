// lab.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include"stdafx.h"
#include <stdio.h> 
#include<cctype>
#include <stdlib.h>
#include<string.h> 
#include<iostream>
#include"IDN.h"
#include"INT8.h"
#include"INT10.h"
#include"INT16.h"
#include"OP.h"
#include"Error.h"
#include"str_to_int.h"
using namespace std;

bool ctnkeyword=false,ctndigit=false,isop=false;//

int num;
IDN idn;
INT8 into;
INT10 intd;
INT16 inth;
OP op;
Error error;
FILE* stream;

int ch;  //�洢���ڶ�ȡ���ַ�
string token;//��ŵ���

int scan(FILE* file);
bool Isop(int ch);
//bool IsKeyword(int ch);
bool IsDigit(int ch);
bool IsAlpha(int ch);
bool IsInt8(string token);
bool IsInt10(string token);
bool IsInt16(string token);


int main(int argc, char** argv) { 


	bool End=false;
	char buf[500];
	int i=0;
	stream = stdin;     // stdin: ��׼����, Ĭ��Ϊ����. ���ϣ�����ļ��ж�ȡ,fp = fopen(...)
	if(argc==1){

		while (!feof(stream)) {

			// ���Գ��԰��������д���ע��, ��������кβ�ͬ. ���ܹ�����ô?
			if (ch == EOF) {
				break;
			}

			switch(scan(stream)){
			case 1:  cout<<idn.ReturnTuple()<<endl;
				break;
			case 2:  cout<<into.GetReturn()<<endl;
				break;
			case 3:  cout<<intd.GetReturn()<<endl; 
				break;
			case 4:  cout<<inth.GetReturn()<<endl;
				break;
			case 5: cout<<op.GetReturn()<<endl;
				break;
			case 6: cout<<error.GetReturn()<<endl;
				break;
			case 7: End=true;
				break;
			}

		}

		//while(End==false){

		//	}

	}
	else{
		stream=fopen(argv[1],"r");
		while(End==false){
			switch(scan(stream)){
			case 1:  cout<<idn.ReturnTuple()<<endl;
				break;
			case 2:  cout<<into.GetReturn()<<endl;
				break;
			case 3:  cout<<intd.GetReturn()<<endl; 
				break;
			case 4:  cout<<inth.GetReturn()<<endl;
				break;
			case 5: cout<<op.GetReturn()<<endl;
				break;
			case 6: cout<<error.GetReturn()<<endl;
				break;
			case 7: End=true;
				break;
			}
		}

	}
	fclose(stream);                  //�ر��ļ�
	return 0; 
}

int scan(FILE* file) {
	/**********************************************/

	//**********************************************/
	// while((ch=getc(stream))!=EOF){
	//switch(scan(stream));

	//	}
	ch=getc(stream);

	while(ch==' '){	              //�����ո�
		ch=getc(stream);
	}

	if(ch=='\n') return 7;

	 if(IsDigit(ch)){
			token+=ch;
			ch=getc(stream);

			while(IsDigit(ch)||IsAlpha(ch)){
				token+=ch;
				ch=getc(stream);
			}
			ungetc(ch,file);
			if(IsInt8(token)){
				into.GetValue(token);
			token.clear();
			return 2;
			}
			else if(IsInt10(token)){
				intd.GetValue(token);
			token.clear();
			return 3;
			}
			else if(IsInt16(token)){
				inth.GetValue(token);
			token.clear();
			return 4;
			}
			else{
				error.GetValue(token);
				token.clear();
				return 6;
			}
		 }

		if(IsAlpha(ch)){
			token+=ch;
			ch=getc(stream);
			while(isalpha(ch)||isdigit(ch)){
				token+=ch;
				ch=getc(stream);
			}
			ungetc(ch,file);
			idn.GetIdn(token);
			token.clear();
			return 1;
		}


		switch(ch){             //��ʼƥ��
 
		case ':':
			ch=getc(stream);
			if(ch=='='){
				return 5;
			}
			else return 6;

		case '+': op.GetOp(ch);

		case '-': op.GetOp(ch);

		case '*': op.GetOp(ch);

		case '/': op.GetOp(ch);

		case '>': op.GetOp(ch);

		case '<': op.GetOp(ch);

		case '=': op.GetOp(ch);

		case ';': op.GetOp(ch);

		case '(': op.GetOp(ch);

		case ')': op.GetOp(ch);
			token.clear();

			return 5;
		default: error.GetValue(token);
			token.clear();
			return 6;


		}              //����ƥ��
}


bool Isop(int ch){                            //�Ƿ�Ϊ��ʶ��
	if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='>'||ch=='<'||ch==';'||ch=='('||ch==')'||ch=='=') return true;

	return false;
}

bool IsDigit(int ch){
	if(ch>='0'&&ch<='9') return true;
	else return false;
}

bool IsAlpha(int ch){
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) return true;
	else return false;
}

bool IsInt8(string token){
	  
	if(token[0]=='0'&&token.length()!=1){
		   int n=1;
		   while(n<token.length()){
			   if((token[n]>='0'&&token[n]<='8')){n++;}
			   else {
				   return false;
			   }
		   }
		   if(n==token.length()) return true;
	  }
  return false;
}

bool IsInt10(string token){
	  
	  if(token[0]!='0'){
		   int n=1;
		   while(n<token.length()){
			   if((token[n]>='0'&&token[n]<='9')){n++;}
			   else {
				   return false;
			   }
		   }
		   if(n==token.length()) return true;		  
	  }
	  else if(token=="0") return true;
  return false;
}

bool IsInt16(string token){
	  
	  if(token[0]=='0'){
		  if(token[1]=='X'||token[1]=='x'){
		   int n=2;
		   while(n<token.length()){
			   if((token[n]>='0'&&token[n]<='9')||(token[n]>='A'&&token[n]<='F')||(token[n]>='a'&&token[n]<='f')){n++;}
			   else {
				   return false;
			   }
		   }
		   if(n==token.length()) return true;
		  }
	  }
  return false;
}


