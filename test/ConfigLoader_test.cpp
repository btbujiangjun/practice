#include "../src/ConfigLoader.h"
#include "glog/logging.h"
#include <iostream>

using namespace practice;

int main(int argc, char* argv[]){
	google::InitGoogleLogging(argv[0]);
	LOG(INFO) << "Init Config Loader.";
	ConfigLoader* cl = new ConfigLoader("../conf/dict.conf");
	int ret = cl->load();
	if(ret == -2){
		std::cout << "File not found." << std::endl;
	}
}
