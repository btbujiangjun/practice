//Copyright 2016 xx Inc. All Rights Reserved.
//Author: Jun Jiang (jiangjun@baidu.com)
//
//Load the Configure File.

#ifndef PRACTICE_CONFIGLOADER_H
#define PRACTICE_CONFIGLOADER_H

#include <string>

#define DISALLOW_COPY_AND_ASSIGN(TypeName)\
		TypeName(const TypeName&);\
		TypeName& operator=(const TypeName&)

namespace practice{

enum FieldType{
	BUILT_IN = 1,
	POINTER,
	ARRAY,
	FIELDTYPE_COUNT
};

struct FieldInfo{
	std::string field_name;
	std::string field_class;
	FieldType field_type;
};

class ConfigLoader{
public:
	//use default symbol ":" and "#"
    explicit ConfigLoader(const std::string& file_name) : 
			_file_name(file_name), \
			_delimiter(":"), \
			_commit("#") {};
	//customized delimiter symbol and commit symbol
	ConfigLoader(const std::string& file_name,\
			const std::string& delimiter,\
			const std::string& commit):
			_file_name(file_name), \
			_delimiter(delimiter), \
			_commit(commit) {};
	~ConfigLoader();

    int load();

	//FieldInfo* field_config(int* field_size);
private:
	void trim(std::string& io_str);

	std::string _file_name;
	std::string _delimiter;
	std::string _commit;

	FieldInfo* _fields;
	//DISALLOW_COPY_AND_ASSIGN(ConfigLoader);
};// ConfigLoader
} // practice
#endif //PRACTICE_CONFIGLOADER_H
