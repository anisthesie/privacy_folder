#pragma once
#include <iostream>

extern char* USER_HOME;

inline void init_user_home() { // https://stackoverflow.com/a/2552458

#ifdef unix
	USER_HOME = getenv("HOME");

#elif defined(_WIN32)
	USER_HOME = getenv("HOMEDRIVE");
	const char* Homepath = getenv("HOMEPATH");
	malloc(strlen(USER_HOME) + strlen(Homepath) + 1);
	strcat(USER_HOME, Homepath);
#endif
		
	}

inline bool file_exists(const std::string& name) { //https://stackoverflow.com/a/12774387
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

inline bool message_already_in_queue() {
	std::string path(USER_HOME);
	path.append("\\privacy_folder\\current_message.cpm");
	return file_exists(path);
}