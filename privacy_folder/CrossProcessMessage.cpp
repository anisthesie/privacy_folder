#include "CrossProcessMessage.h"

CrossProcessMessage::CrossProcessMessage(const std::string& title, const std::string &message) {
	this->message = message;
	this->title = title;
}


void CrossProcessMessage::send() {
	if (message_already_in_queue()) {
		error("Could not send the message since there was another message queued already.");
		return;
	}
	std::string file_path(USER_HOME); 
	file_path.append("\\privacy_folder");

	if (!dirExists(file_path))
		_mkdir(file_path.c_str());

	file_path.append("\\current_message.cpm");
	std::ofstream file(file_path);
	file << title.c_str() << std::endl << message.c_str();
	file.close();

	this->confirmation_thread = std::thread(wait_for_confirmation);
	confirmation_thread.join();
}

void wait_for_confirmation() {
	info("Waiting for confirmation...");
	while (true) {
		if (!message_already_in_queue()) {
			info("Message successfully delivered");
			break;
		}
	}
}
