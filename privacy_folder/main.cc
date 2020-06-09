#include <iostream>
#include "CrossProcessMessage.h"
#include  "common.h"

char* USER_HOME;

void parse_arguments(char** args);
void show_usage(bool exit);

int	main(int argc, char** argv) {
	parse_arguments(argv);
	init_user_home();

}

void parse_arguments(char** args) {

}

void show_usage(bool exit) {

	std::cout << std::endl << 
		"Syntax : privacy_folder <operation> [arguments...]" << std::endl <<
		"\t Operations:" << std::endl <<
		"\t\t add: privacy_folder add [path to folder] || Add encrypted folder" << std::endl <<
		"\t\t rem: privacy_folder rem [path to folder] || Remove encrypted folder ( /!\\ doesn't decrypt the files)" << std::endl << 
		"\t\t ser: privacy_folder ser [install / uninstall] || Install or remove service (Windows only)"
		<< std::endl;

	if(exit) std::exit(-1);
}