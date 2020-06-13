#pragma once
#include <iostream>

#define CONFIG_DIRECTORY "\\privacy_folder"
#define CONFIG_FILE "\\directories.pfr"

typedef unsigned char byte;

extern char* USER_HOME;


inline void init_user_home() { // https://stackoverflow.com/a/2552458
	USER_HOME = getenv("HOMEDRIVE");
	const char* Homepath = getenv("HOMEPATH");
	malloc(strlen(USER_HOME) + strlen(Homepath) + 1);
	strcat(USER_HOME, Homepath);
}

inline bool file_exists(const std::string& name) { //https://stackoverflow.com/a/12774387
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

inline void error(const char* str) {
	std::cout << "[ERROR] : " << str << std::endl;
}

inline void info(const char* str) {
	std::cout << "[INFO] : " << str << std::endl;
}

#include <Windows.h>
inline bool dirExists(const std::string& dirName_in) {
	DWORD ftyp = GetFileAttributesA(dirName_in.c_str());
	if (ftyp == INVALID_FILE_ATTRIBUTES) {
		return false;
	}
	return (ftyp & FILE_ATTRIBUTE_DIRECTORY);
}
