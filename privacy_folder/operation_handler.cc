#include "operation_handler.h"

inline void handle_service_operation(const bool & do_install) {
	if (do_install) { // TODO: Install the service

		return;
	}				  // TODO: Uninstall the service				
	
}

inline void handle_add_operation(const char * path) {
	
}

inline void handle_remove_operation(const char * path) {

}


 void parse_arguments(const int& argc, char** args) {
	if (argc == 3) {
		const char* operation = args[1];
		if (operation == OP_ADD) {
			handle_add_operation(args[2]);
			return;
		}
		if (operation == OP_REMOVE) {
			handle_remove_operation(args[2]);
			return;
		}
		if (operation == OP_SERVICE) {
			bool do_install;
			if (args[2] == "install") do_install = true;
			else if (args[2] == "uninstall") do_install = true;
			else show_usage(true);
			handle_service_operation(do_install);
			return;
		}

		return;
	}
	show_usage(true);
}

inline void show_usage(const bool& exit) {
	std::cout << std::endl <<
		"Syntax : privacy_folder <operation> [arguments...]" << std::endl <<
		"\t Operations:" << std::endl <<
		"\t\t add: privacy_folder " << OP_ADD << " [path to folder] || Add encrypted folder" << std::endl <<
		"\t\t rem: privacy_folder " << OP_REMOVE << " [path to folder] || Remove encrypted folder ( /!\\ doesn't decrypt the files)" << std::endl <<
		"\t\t ser: privacy_folder " << OP_SERVICE << " [install / uninstall] || Install or remove service (Windows only)"
		<< std::endl;

	if (exit) std::exit(-1);
}

