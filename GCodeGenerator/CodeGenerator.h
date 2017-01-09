#pragma once
#include <string>
using namespace std;

class CodeGenerator
{
public:
	//default
	string lineNumberPre ="N" ;
	string lineNumberPost = " ";
	
	string lineEnding = "*\n";

	CodeGenerator();
	~CodeGenerator();
	
	void setLineNumberPre(string pre);
	void setLineNumberPost(string post);
	void setLineEnding(string ending);
	
	//G1
	string linearMotion(int index, bool isFirst, double x, double y, double z, double i, double j, double k);
	//G30
	string returnToHome(int index, double x, double y, double z, double a, double b, double c);

	//M03
	string spindleOn(int index);
	//M05
	string spindleStop(int index);
	//M08
	string coolantOn(int index);

	//M30
	string endProgram(int index);

private:
	string writeLineNumber(int i);
};

