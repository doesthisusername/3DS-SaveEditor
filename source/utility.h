#pragma once
#include <string>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>

#include <3ds.h>

// More general utility
std::string uiFormatBytes(u64 bytes);

// Files
u64 getFreeSpace();
bool fileExists(const std::string path);
bool fileOrDirExists(const char* path);