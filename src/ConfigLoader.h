//Copyright 2016 xx Inc. All Rights Reserved.
//Author: Jun Jiang (jiangjun@baidu.com)
//
//Load the Configure File.

#ifndef PRACTICE_CONFIGLOADER_H
#define PRACTICE_CONFIGLOADER_H
namespace practice{
enum FieldType{
	BUILT-IN = 1,
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
		explicit ConfigLoader(const std::string& config_name) : _config_name(config_name) {}
		~ConfigLoader();
		int init();
		FieldInfo* field_config(int* field_size);
	private:
		std::string _config_name;
		int _field_size;
		FieldInfo* _fields;
};// ConfigLoader
} // practice
#endif //PRACTICE_CONFIGLOADER_H
