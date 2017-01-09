#pragma once
#include <string>
#include <vector>

using namespace std;

class FileLoader
{
public:
	FileLoader();
	~FileLoader();

	void loadFileName(string path, vector<string>& files);
	void loadFileIntoString(string path, string& content);

private:
	void getFiles(string path, string exd, vector<string>& files);
};

