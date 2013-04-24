#pragma once
#include<string>
using namespace std;
class OP
{
public:
	OP(void);
	~OP(void);
	void GetOp(int op){_op=op;}
	string GetReturn();
private:
	string _op;

};

