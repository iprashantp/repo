#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<conio.h>
using namespace std;

class Comparator
{
	public:
		Comparator();
		~Comparator();
		void CompareFiles(string inFile1,string inFile2);
		
	private:
		ifstream inFile1;
		ifstream inFile2;
		ofstream outFile;
		
		bool file1HasLine;
		bool file2HasLine;
		
		void CompareLine(string,string,int);
		void WriteToFile(int,int,char,char);
		void CloseFiles();
		int CharCompare(int lineNumber,int lineIndex,string line,int fileNumber);
};

