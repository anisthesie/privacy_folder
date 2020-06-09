#pragma once

#include <iostream>
#include <vector>
#include <thread>

#include "common.h"

extern char* USER_HOME;

class CrossProcessMessage {
private: 
	std::thread waiting_for_confirmation;
	std::string message;

public:
	CrossProcessMessage(std::string message);
	void send();
};

//void wait_for_confirmation();
//std::thread waiting_for_confirmation;
