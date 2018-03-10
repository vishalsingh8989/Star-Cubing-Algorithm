#ifndef _STAR_TABLE_H
#define _STAR_TABLE_H


#include <map>
#include <vector>
#include <string>

class StarTable
{

public:

	void generate_attrs_stars( std::map<std::string, int> & attrs_freq, std::vector<std::vector<std::string> > &csv_data, int attr_index, std::string star_val, int iceberg_condition);


};

#endif
