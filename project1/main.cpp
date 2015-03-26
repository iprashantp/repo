#include <iostream>
#include<conio.h>
#include<stdio.h>
#include "comparator.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	string file1="D:\\file1.txt";
	string file2="D:\\file2.txt";
	Comparator obj;
	obj.CompareFiles(file1,file2);
	getch();
	return 0;
}
