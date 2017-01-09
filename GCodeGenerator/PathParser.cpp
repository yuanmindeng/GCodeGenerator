#include "PathParser.h"
#include "CodeGenerator.h"
#include <sstream>
#include <iostream>
#include <vector>

PathParser::PathParser()
{
}


PathParser::~PathParser()
{
}

struct Point{
	double x;
	double y;
	double z;
	double u;
	double v;
	double w;
};

void PathParser::parsePath(string content,string& output){
	vector<Point> points;
	int count = 1;
	points.clear();
	istringstream is(content); //���������ַ��������������ݳ�ʼ��Ϊ��12�����ַ��� 
	int lineNumber;
	is >> lineNumber; //��is���ж���һ��int��������i��
	int pointNumber;
	is >> pointNumber;
	for (int i = 0; i < lineNumber; i++){
		for (int j = 0; j < pointNumber; j++){
			double x, y, z, u, v, w;
			is >> x;	is >> y;	is >> z;	is >> u;	is >> v;	is >> w;
			Point point;	
			point.x = x;	point.y = y;	point.z = z;	point.u = u;	point.v = v;	point.w = w;
			points.push_back(point);
			//cout << point.x << " " << point.y << " " << point.z << " " << point.u << " " << point.v << " " << point.w << endl;
		}


	}
		
	CodeGenerator* codeGenerator = new CodeGenerator();

	output += codeGenerator->spindleOn(count++);

	for (int i = 0; i < points.size(); i++){
		output += codeGenerator->linearMotion(count, true, points[i].x, points[i].y, points[i].z, points[i].u, points[i].v, points[i].w);
		count++;
	}

	//cout << output << endl;
	
	output += codeGenerator->spindleStop(count++);
	output += codeGenerator->endProgram(count++);

	delete codeGenerator;

}