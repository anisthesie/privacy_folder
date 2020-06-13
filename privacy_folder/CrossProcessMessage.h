#pragma once

#include <iostream>
#include <vector>
#include <thread>
#include <fstream>

#include <direct.h>

#include "common.h"

extern char* USER_HOME;

class CrossProcessMessage {

private: 
	std::thread confirmation_thread;
	std::string message;
	std::string title;

public:
	CrossProcessMessage(const std::string& title, const std::string& message);
	void send();
};

void wait_for_confirmation();
inline bool message_already_in_queue();
//std::thread waiting_for_confirmation;
