#include "Folder.h"

Folder::Folder(const std::string &path) {
	this->path = path;
}

const std::string Folder::getPath() {
	return this->path;
}
