#pragma once
#include <iostream>
#include <thread>
class Folder {

private:
	std::thread encryption_thread;
	std::string path;

public: 
	Folder(const std::string &path);
	const std::string getPath();
};

