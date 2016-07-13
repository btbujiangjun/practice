#include "../src/ConfigLoader.h"
#include <iostream>

using namespace practice;

int main(){
	ConfigLoader* cl = new ConfigLoader("../conf/field.conf");
	int ret = cl->load();
	if(ret == -2){
		std::cout << "File not found." << std::endl;
	}
}
