#pragma once
#include <string>
#include <sstream>

#include <3ds.h>

// More general utility
std::string uiFormatBytes(u64 bytes);

// Files
u64 getFreeSpace();
bool fileExists(const std::string path);