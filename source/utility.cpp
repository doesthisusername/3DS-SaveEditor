#include "utility.h"

// Stolen from CTRX, thanks d0k3
std::string uiFormatBytes(u64 bytes) {
	const char* units[] = { " bytes", " kilobytes", " megabytes", " gigabytes" };
	std::stringstream result;

	if (bytes < 1024) result << bytes << units[0];
	else {
		int scale = 1;
		u64 bytes100 = (bytes * 100) >> 10;

		for (; (bytes100 >= 1024 * 100) && (scale < 3); scale++, bytes100 >>= 10);
		result << (bytes100 / 100) << "." << ((bytes100 % 100) / 10) << (bytes100 % 10) << units[scale];
	}

	return result.str();
}

// Also stolen
u64 getFreeSpace() {
	FS_ArchiveResource resource;
	Result result = FSUSER_GetSdmcArchiveResource(&resource);
	return (result != 0) ? 0 : (u64)resource.clusterSize * (u64)resource.freeClusters;
}

// MAKE THIS RETURN DIRECTORIES AS TRUE AT SOME POINT
// Can be removed
bool fileExists(const std::string path) {
	FILE* file = fopen(path.c_str(), "r");
	if (file) {
		fclose(file);
		return true;
	}

	return false;
}

bool fileOrDirExists(const char* path) {
	struct stat info;

	if (stat(path, &info) != 0) //File or dir is unaccessible (doesn't exist?)
	{
		return false;
	}

	else if (info.st_mode & S_IFDIR)  // It's a directory
	{
		return true;
	}

	else //It's a file
	{
		return true;
	}
}
