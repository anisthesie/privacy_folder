#pragma once

#include <vector>
#include <direct.h>
#include <fstream>
#include <string>

#include "common.h"
#include "Folder.h"

extern std::vector<Folder> folder_list;

void init_folder_list();
void check_loop();
inline void process_folder(const std::string& path);