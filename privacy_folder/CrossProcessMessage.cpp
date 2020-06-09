#include "CrossProcessMessage.h"

CrossProcessMessage::CrossProcessMessage(std::string message) {
	this->message = message;
}

void CrossProcessMessage::send() {
	if (message_already_in_queue) {
		std::cout << "Could not send the message since there was another message queued already." << std::endl;
		return;
	}

}

void wait_for_confirmation()
{
}
