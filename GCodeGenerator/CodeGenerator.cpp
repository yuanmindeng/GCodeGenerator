#include "CodeGenerator.h"
#include <sstream>

template <class T>
std::string ConvertToString(T value) {
	std::stringstream ss;
	ss << value;
	return ss.str();
}


CodeGenerator::CodeGenerator()
{
}


CodeGenerator::~CodeGenerator()
{
}


string CodeGenerator::writeLineNumber(int index){
	//set output format
	return lineNumberPre + to_string(index)+lineNumberPost;
}

void CodeGenerator::setLineNumberPre(string pre){
	lineNumberPre = pre;
}

void CodeGenerator::setLineNumberPost(string post){
	lineNumberPost = post;

}

void CodeGenerator::setLineEnding(string ending){
	lineEnding = ending;
}



//G1
string CodeGenerator::linearMotion(int index, bool isFirst, double x, double y, double z, double i, double j, double k){
	string command = writeLineNumber(index);
	string commandCode = "G1";

	if (isFirst){
		command += commandCode;
		
	}

	command += " ";

	command += "X" + ConvertToString(x) + " Y" + ConvertToString(y) + " Z" + ConvertToString(z) 
		+ " I" + ConvertToString(i) + " J" + ConvertToString(x) + " K" + ConvertToString(k);
	
	command += lineEnding;

	return command;
}


//G30
string CodeGenerator::returnToHome(int index, double x, double y, double z, double i, double j, double k){
	string command = writeLineNumber(index);
	string commandCode = "G30 ";
	command += "X" + ConvertToString(x) + " Y" + ConvertToString(y) + " Z" + ConvertToString(z)
		+ " I" + ConvertToString(i) + " J" + ConvertToString(x) + " K" + ConvertToString(k);
	
	command += commandCode;
	command += lineEnding;

	return command;

}


//M instruct

//M03
string CodeGenerator::spindleOn(int index){
	string command = writeLineNumber(index);
	string commandCode = "M03";
	
	command += commandCode;
	command += lineEnding;

	return command;
}

//M05
string CodeGenerator::spindleStop(int index){
	string command = writeLineNumber(index);
	string commandCode = "M05";

	command += commandCode;
	command += lineEnding;

	return command;
}

//M08
string CodeGenerator::coolantOn(int index){
	string command = writeLineNumber(index);
	string commandCode = "M08";

	command += commandCode;
	command += lineEnding;

	return command;
}

//M30
string CodeGenerator::endProgram(int index){
	string command = writeLineNumber(index);
	string commandCode = "M30";

	command += commandCode;
	command += lineEnding;

	return command;
}


