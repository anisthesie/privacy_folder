#include <iostream>

#include "operation_handler.h"
#include "encryption_worker.h"

char* USER_HOME;

int	main(int argc, char** argv) {
	info("hh");
	init_user_home();
	init_folder_list();
	info("d");
	if (1) return 1;
	init_user_home();
	if (parse_arguments(argc, argv)) return 0;
}
