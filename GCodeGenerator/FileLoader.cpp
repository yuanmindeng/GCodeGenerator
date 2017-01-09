#include "FileLoader.h"
#include <io.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

FileLoader::FileLoader()
{
}


FileLoader::~FileLoader()
{
}

void FileLoader::loadFileIntoString(string path, string& content){
	ifstream ifile(path);
	//���ļ����뵽ostringstream����buf��
	ostringstream buf;
	char ch;
	while (buf&&ifile.get(ch))
		buf.put(ch);
	//������������buf�������ַ���
	content = buf.str();
}






void FileLoader::loadFileName(string path, vector<string>& files){

	getFiles(path, "path", files);
	cout << "sss" << endl;
	int size = files.size();
	for (int i = 0; i < size; i++)
	{
		cout << files[i].c_str() << endl;
	}
}



void FileLoader::getFiles(string path, string exd, vector<string>& files)
{
	//�ļ����
	long   hFile = 0;
	//�ļ���Ϣ
	struct _finddata_t fileinfo;
	string pathName, exdName;

	if (0 != strcmp(exd.c_str(), ""))
	{
		exdName = "\\*." + exd;
	}
	else
	{
		exdName = "\\*";
	}

	if ((hFile = _findfirst(pathName.assign(path).append(exdName).c_str(), &fileinfo)) != -1)
	{
		do
		{
			
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFiles(pathName.assign(path).append("\\").append(fileinfo.name), exd, files);
			}
			else
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					files.push_back(pathName.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}