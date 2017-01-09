#include "FileLoader.h"
#include "PathParser.h"
#include <iostream>
#include <fstream>
using namespace std;
void main(){
	FileLoader* fileLoader = new FileLoader();
	PathParser* pathParser = new PathParser();
	vector<string> files;
	string output;
	fileLoader->loadFileName("D:\\Code\\irc\\CNC\\GCodeGenerator\\GCodeGenerator\\path", files);
	

	for (int i = 0; i < files.size(); i++){
		string content;
		fileLoader->loadFileIntoString(files[i], content);

		//cout << content << endl;
		pathParser->parsePath(content, output);
		ofstream of("test.txt");
		streambuf* fileBuf = of.rdbuf();
		of << output << endl;
		//pathParser->
		//sd


	}
	delete fileLoader;
	delete pathParser;
}