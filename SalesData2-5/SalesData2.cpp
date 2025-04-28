#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

class SALESREC
{
    public:
	char     date[12];
	char     region[16];
	char     rep[16];
	char     item[16];
	int      units;
	float    unitCost;
	float    Total;
};

void simpleSortTotal(SALESREC* s[], int c);

int main()
{
	ifstream infile;
	int i = 0;
	char cNum[10] ;
	SALESREC salesArr[40];
	int   salesArrayCount;
	SALESREC* s[40];

    char empty[10];

    infile.open ("SalesDataP2.csv", ifstream::in);
    if (infile.is_open()) {
        int c=0;
        infile.getline(empty, 256, '\n');
        while (infile.good()) {
            infile.getline(salesArr[c].date, 256, ',');
            infile.getline(salesArr[c].region, 256, ',');
            infile.getline(salesArr[c].rep, 256, ',');
            infile.getline(salesArr[c].item, 256, ',');
            infile.getline(cNum, 256, ',');
            salesArr[c].units = atoi(cNum);
            infile.getline(cNum, 256, '\n');
            salesArr[c].unitCost = atof(cNum);
            // cout << salesArr[c].Total;
            salesArr[c].Total = (float) salesArr[c].unitCost * (float) salesArr[c].units;
            i++; c++;
            
        }
        salesArrayCount = c-1;
        infile.close();
        // Initialize the sort array pointers
        for (int i=0; i < salesArrayCount; i++)
            s[i] = &salesArr[i];
        
        simpleSortTotal(s, salesArrayCount);
        
        for (int i=0; i < salesArrayCount; i++)
            cout << "Record: " << s[i]->date <<", " << s[i]->region << ", " << s[i]->rep << ", " << s[i]->item << ", " << s[i]->units << ", " << s[i]->unitCost << ", " << s[i]->Total << endl;
    } else {
		cout << "Error opening file";
	}	
  
}
 
// arguments will be an array of pointers and a count
void simpleSortTotal(SALESREC* s[] , int c) {
	for (int i=0; i < c; i++)
		for (int j=i; j < c; j++)
			if (s[i]->Total < s[j]->Total) {
				SALESREC* temp;
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
} 
