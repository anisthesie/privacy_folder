#include "config_file.h"


std::thread config_thread;

void init_config_thread() {
	config_thread = std::thread(update_config);
	config_thread.join();
}
void update_config() {
	
}
