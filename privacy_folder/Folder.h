#pragma once
#include <iostream>
#include <thread>
class Folder {

private:
	std::thread* encryption_thread;

public: 
	Folder(std::string path);

};

