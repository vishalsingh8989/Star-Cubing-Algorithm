#include <vector>
#include <iostream>
#include <csv_reader.h>
#include <logger.h>
#include <fstream>
#include <map>
#include <startable.h>

using namespace std;



void StarTable ::  generate_attrs_stars( map<string, int> & attrs_freq, vector<vector<string> > &csv_data, int attr_index, string star_val, int iceberg_condition){

	map<string, string>  star_table;
	map<string, string>::iterator it;
	map<string, int>::iterator innerit;

	for(innerit = attrs_freq.begin() ; innerit != attrs_freq.end() ; innerit++){
		if(INFO){
			const char *log_string = (innerit->first).c_str();
			INFOLOG(" %s : %d \n",log_string ,innerit->second);
		}
		if(innerit->second < iceberg_condition || innerit->first.compare("NA") == 0 )
			star_table[innerit->first] = star_val;
		else
			star_table[innerit->first] = innerit->first;
	}


	if(INFO){
		for(it = star_table.begin(); it != star_table.end() ;it++){
			cout << star_val << " >> "  << it->first << " : "<<it->second<<endl;
		}
	}

	for(int i = 0 ;i < csv_data.size() ; i++){
		csv_data[i][attr_index] = star_table[csv_data[i][attr_index]];
	}

}
