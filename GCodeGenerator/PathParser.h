#pragma once
#include <string>
using namespace std;
class PathParser
{
public:
	PathParser();
	~PathParser();
	
	
	void parsePath(string content,string& output);
};

