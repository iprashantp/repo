#include "comparator.h"

void Comparator::CompareFiles(string file1str,string file2str){
	string file1line;
	string file2line;
	int line_number=1;
	
	cout<<"hello\n";
	inFile1.open(file1str.c_str());
	inFile2.open(file2str.c_str());
	
		if(!inFile1.is_open() || !inFile2.is_open()){
			if(!inFile1.is_open()){
				cout<<"file1 can not be open\n";
			}
			if(!inFile2.is_open()){
				cout<<"file2 can not be open\n";
			}
		}
		
		else{
			do{
				file1HasLine=getline(inFile1,file1line);
				file2HasLine=getline(inFile2,file2line);
				
				//both has lines
			if(file1HasLine&&file2HasLine){
				//cout<<"file1line:"<<file1line<<"\nfile2line:"<<file2line<<endl;
				//cout<<"f1line1:"<<line1<<"\n"<<"f2line2"<<line2<<endl;
       		 	CompareLine(file1line,file2line,line_number);
				line_number++;
			}
			//file2 end
    		else if(file1HasLine){
    			//cout<<"file1line:"<<file1line<<endl;
				//cout<<"f1line1:"<<line1<<endl;
        		CompareLine(file1line,"",line_number);
				line_number++;
				//cout<<"line change\n";
			}
    		//file1 end
    		else if(file2HasLine){
    			//cout<<"file2line:"<<file2line<<endl;
				//cout<<"f1line2:"<<line2<<endl;
        		CompareLine("",file2line,line_number);
				line_number++;
				//cout<<"line change\n";
		    }
    		//both files end
    		else{
        		break;
    		}
				
			}while(file1HasLine||file2HasLine);
		}
	CloseFiles();
}
void Comparator::CompareLine(string file1line,string file2line,int lineNumber){
	int lineIndex=0;
	int line1length=file1line.length();
	int line2length=file2line.length();
	//loop breaks if either of line ends
	while(lineIndex<line1length && lineIndex<line2length){
		if(file1line[lineIndex]!=file2line[lineIndex]){
			cout<<"line:"<<lineNumber<<" column:"<<lineIndex+1<<"\tfile1: "<<file1line[lineIndex]<<"\tfile2: "<<file2line[lineIndex]<<endl;
			WriteToFile(lineNumber,lineIndex+1,file1line[lineIndex],file2line[lineIndex]);
		}
		lineIndex++;
	 }
	 //file2line end
	 if(lineIndex<line1length){
        /*while(lineIndex<line1length){
            cout<<"line:"<<lineNumber<<" column:"<<lineIndex+1<<"\tfile1: "<<file1line[lineIndex]<<"\tfile2: "<<"$"<<endl;
			WriteToFile(lineNumber,lineIndex+1,file1line[lineIndex],'$');
            lineIndex++;
        }*/
		
		lineIndex=CharCompare(lineNumber,lineIndex,file1line,0);
	}
	//file1line ends
  	else if(lineIndex<line2length){
      /*while(lineIndex<line2length){
            cout<<"line:"<<lineNumber<<" column:"<<lineIndex+1<<"\tfile1: "<<"$"<<"\tfile2: "<<file2line[lineIndex]<<endl;
			WriteToFile(lineNumber,lineIndex+1,'$',file2line[lineIndex]);
            lineIndex++;
        }*/
	  lineIndex=CharCompare(lineNumber,lineIndex,file2line,1);
  	}
return;
}

int Comparator::CharCompare(int lineNumber,int lineIndex,string line,int fileNumber){
	//$-->null value(line has no character at the index which we are talking about)
	int linelength=line.length();
	char lineChar[2]={'$','$'};
	if(lineIndex<linelength){
        while(lineIndex<linelength){
			lineChar[fileNumber]=line[lineIndex];
            cout<<"line:"<<lineNumber<<" column:"<<lineIndex+1<<"\tfile1: "<<lineChar[0]<<"\tfile2: "<<lineChar[1]<<endl;
			WriteToFile(lineNumber,lineIndex+1,lineChar[0],lineChar[1]);
            lineIndex++;
        }
	}
return lineIndex;
}

void Comparator::WriteToFile(int lineNumber,int columnNumber,char file1char,char file2char){
	outFile<<"line:"<<lineNumber<<"\t"<<"column:"<<columnNumber<<"\t"<<"file1:"<<file1char<<"\t"<<"file2:"<<file2char<<"\n";
	return;
}

void Comparator::CloseFiles(){
	inFile1.close();
	inFile2.close();
	outFile.close();
	cout<<"files closed";
	return;
}

Comparator::Comparator()
{
	outFile.open("D:\\outfile.txt");
}

Comparator::~Comparator()
{
}
