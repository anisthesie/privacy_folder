#include "operation_handler.h"
#include "config_file.h"

inline void handle_service_operation(const bool & do_install) {
	if (do_install) { // TODO: Install the service

		return;
	}				  // TODO: Uninstall the service				
	
}

inline void handle_add_operation(const char * path) {
	
}

inline void handle_remove_operation(const char * path) {

}


 bool parse_arguments(const int& argc, char** args) {
	if (argc == 3) {
		const std::string operation = std::string(args[1]);
		if (operation.compare(OP_ADD)) {
			handle_add_operation(args[2]);
			return true;
		}
		if (operation.compare(OP_REMOVE)) {
			handle_remove_operation(args[2]);
			return true;
		}
		if (operation.compare(OP_SERVICE)) {
			bool do_install;
			if (args[2] == "install") do_install = true;
			else if (args[2] == "uninstall") do_install = false;
			else show_usage(true);
			handle_service_operation(do_install);
			return true;
		}
		if (operation.compare(OP_ADD)) {
			init_config_thread();
			return false;
		}
	}
	show_usage(true);
	return true;
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

