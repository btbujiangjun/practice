//Copyright 2016 xx Inc. All Rights Reserved.
//Author:Jun Jiang (jiangjun@baidu.com)
//
//Load the configure file.

#include "ConfigLoader.h"
#include <fstream>
#include <iostream>

using std::string;


practice::ConfigLoader::~ConfigLoader(){
	//delete[] _fields;
}

//failed if return less than zero, otherwise success.
int practice::ConfigLoader::load(){

	std::ifstream in(_file_name.c_str(), std::ios::in);
	if(!in) return -2;//File not exists, return -2.
	
	const string::size_type delimiter_len = _delimiter.length();

	string buff;
	string key;
	string value;

	string name_str;
	string class_str;
	string type_str;
	
	FieldInfo* field = NULL;

	while(std::getline(in, buff)){

		this->trim(buff);

		//ignore commit line
		size_t commit_index = buff.find(_commit);
		if(commit_index != string::npos){
			std::cout << "commit:" << buff << std::endl;
			buff = '\0';
			continue;
		}

		//new config node
		size_t field_index = buff.find("[field]");
		if(field_index != string::npos){
			buff = '\0';
			continue;
		}

		size_t d_idx = buff.find(_delimiter);

		//config data
		if(d_idx > 1 && \
				d_idx != string::npos && \
				d_idx + delimiter_len < buff.length()){
			key = buff.substr(0, d_idx);
			value = buff.substr(d_idx + delimiter_len);
			this->trim(key);
			this->trim(value);
			std::cout << "key:" << key << " \tvalue:" << value << std::endl;
		}
	}

	FieldInfo* fi = NULL;

	return -1;
}

void practice::ConfigLoader::trim(string& io_str){
	const char whitespace[] = "\n\t\v\r\f";
	io_str.erase(0, io_str.find_first_not_of(whitespace));
	io_str.erase(io_str.find_last_not_of(whitespace) + 1U);  
}
