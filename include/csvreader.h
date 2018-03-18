#ifndef _CSV_READER_H
#define _CSV_READER_H


#include <map>
#include <vector>
#include <string>
class CsvReader
{

public:
	std::string file_name;


	CsvReader(std::string file_name);
	std::vector<std::vector<std::string> > read_csv(std::map<std::string, std::map<std::string, int> >& freq_table);
	void printdata(std::vector<std::vector<std::string> > &csvdata);
};

#endif
