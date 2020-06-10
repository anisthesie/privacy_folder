#include <iostream>

#include "CrossProcessMessage.h"
#include "operation_handler.h"

char* USER_HOME;

int	main(int argc, char** argv) {

	init_user_home();
	CrossProcessMessage message("EL ZEB", "chof kho matheblnich");
	message.send();
	//parse_arguments(argc, argv);
}

