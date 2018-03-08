#include<vector>
#include<iostream>
#include<csv_reader.h>
#include<logger.h>
#include <fstream>
using namespace std;

vector<vector<int> > CsvReader :: read_csv(){
	INFOLOG("Start reading csv file for input.\n");
	vector<vector<int> > csv_data;


	ifstream csv_file("/Users/vishaljasrotia/eclipse-workspace/star_cubing_algorithm/input/PRSA_data_2010_2014.csv");

	string value;

	string number;
	string year;
	string month;
	string day;
	string hour;
	string pm_value;
	string dwep;
	string temperature;
	string pressure;
	string cbwd;
	string iws;
	string is;
	string ir;

	if(!csv_file.is_open()){
		ERRORLOG("ERROR: Problem in file open()\n");
		return csv_data;
	}else{
		INFOLOG("Start reading csv file\n");
	}

	int idx  = 0;

	while ( csv_file.good() )
	{


	     getline ( csv_file, number, ',' );
	     getline ( csv_file, year, ',' );
	     getline ( csv_file, month, ',' );
	     getline ( csv_file, day, ',' );
	     getline ( csv_file, hour, ',' );
	     getline ( csv_file, pm_value, ',' );
	     getline ( csv_file, dwep, ',' );
	     getline ( csv_file, temperature, ',' );
	     getline ( csv_file, pressure, ',' );
	     getline ( csv_file, cbwd, ',' );
	     getline ( csv_file, iws, ',' );
	     getline ( csv_file, is, ',' );
	     getline ( csv_file, ir, '\n' );


	     //INFOLOG("Value :  %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n", number, year, month, day, hour, pm_value, dwep,temperature, pressure, cbwd,iws, is, ir);
	     cout << "Value : " << number << ", " <<  year << ", " << month << ", " << day << ", " << hour << ", " << pm_value << ", " << dwep << ", " << temperature<<", " << pressure << ", " << cbwd <<", " << iws <<"," << is << ", " << ir <<endl;
	     //INFOLOG("Value :  %s, %s, %s, %s, %s\n",number, year, month, day, hour);

	     idx++;
	     if(idx == 100){
	    	 	 break;
	     }

	}

	return csv_data;
}

void CsvReader :: printname(){
	cout << "Hello World from csv_reader.cpp\n"<<endl;
}

