#pragma once

#include "common.h"

#define OP_ADD "add"
#define OP_REMOVE "rem"
#define OP_SERVICE "svc"
#define OP_INTERNAL "itl"

inline void handle_service_operation(const bool& path);
inline void handle_add_operation(const char* path);
inline void handle_remove_operation(const char* path);

inline void show_usage(const bool& quit);
bool parse_arguments(const int& argc, char** args);