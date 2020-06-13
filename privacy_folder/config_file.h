#pragma once

#include "common.h"

#include <thread>

extern std::thread config_thread;

void init_config_thread();
void update_config();
