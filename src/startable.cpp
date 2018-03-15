#include <vector>
#include <iostream>
#include <csv_reader.h>
#include <logger.h>
#include <fstream>
#include <map>
#include <vector>
#include <startable.h>
#include <iomanip>

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

vector<vector<string> >  StarTable :: compress_star_table(vector<vector<string> >& table){

	vector<vector<string> > compressed_table;
	vector<vector<string> >::iterator  it;
	map<string, int>  row_count;
	map<string, int>::iterator  row_count_it;
	string key ;

	for(it = table.begin() ; it != table.end() ; it++){
		key = generate_key(*it);
		//cout << "key : " <<  key <<  endl;
		row_count[key]++;
	}

	for(row_count_it = row_count.begin() ; row_count_it != row_count.end(); row_count_it++){
		cout <<  setw(30) << row_count_it->first << " : "  << row_count_it->second<<endl;
	}




	return compressed_table;
}

string StarTable :: generate_key(vector<string> row){
	string key = row[0];
	for(int i = 1 ; i <  row.size() ; i++){
		key = key + "," + row[i];

	}

	return key;



}






