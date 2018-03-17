#include <vector>
#include <iostream>
#include <csvreader.h>
#include <logger.h>
#include <fstream>
#include <map>
#include <vector>
#include <startable.h>
#include <iomanip>

using namespace std;



void StarTable ::  generate_attrs_stars( map<string, int> & attrs_freq, vector<vector<string> > &csv_data, int attr_index, string star_val, int iceberg_condition){

	map<string, string>  star_table;
	//map<string, string>::iterator it;
	//map<string, int>::iterator innerit;

	for(auto innerit = attrs_freq.begin() ; innerit != attrs_freq.end() ; innerit++){
		if(DEBUG){
			const char *log_string = (innerit->first).c_str();
			INFOLOG(" %s : %d \n",log_string ,innerit->second);
		}
		if(innerit->second < iceberg_condition || innerit->first.compare("NA") == 0 )
			star_table[innerit->first] = star_val;
		else
			star_table[innerit->first] = innerit->first;
	}


	if(DEBUG){
		for(auto it = star_table.begin(); it != star_table.end() ;it++){
			cout << star_val << " >> "  << it->first << " : "<<it->second<<endl;
		}
	}

	for(int i = 0 ;i < csv_data.size() ; i++){
		csv_data[i][attr_index] = star_table[csv_data[i][attr_index]];
	}

}


/*
 *
 * compress table and replace values with stars when not met condition
 *
 *
 */
vector<vector<string> >  StarTable :: compress_star_table(vector<vector<string> >& table){

	vector<vector<string> > compressed_table;
	vector<string> row;
	//vector<vector<string> >::iterator  it;
	map<string, int>  row_count;
	//map<string, int>::iterator  row_count_it;
	string key ;
	string sep = ",";
	size_t pos = 0;
	string val;

	for(auto it = table.begin() ; it != table.end() ; it++){
		key = generate_key(*it);
		row_count[key]++;
	}

	for(auto row_count_it = row_count.begin() ; row_count_it != row_count.end(); row_count_it++){
		if(DEBUG)
			cout <<  setw(30) << row_count_it->first << " : "  << row_count_it->second<<endl;
		key = row_count_it->first;
		row.clear();
		while ((pos = key.find(sep)) != string::npos) {
				val = key.substr(0 , pos);
				row.push_back(val);
			    key.erase(0 ,  pos + sep.length());
			}
			row.push_back(key);
			row.push_back(to_string(row_count_it->second));
			compressed_table.push_back(row);
			if(DEBUG)
				cout << row_count_it->second << std::endl;

	}

	return compressed_table;
}


/*
 * generate key for base table compression using hashing.
 */
string StarTable :: generate_key(vector<string> row){
	string sep = ",";
	string key = row[0];
	for(int i = 1 ; i <  row.size() ; i++){
		key = key + sep + row[i];

	}
	//cout << "key "<< key << endl;
	return key;



}
