#include "main.h"
#include "utility.h"


int main(int argc, char **argv) {
	gfxInitDefault();
	fsInit();

	consoleInit(GFX_TOP, NULL);
	printf("Initialized console\n");

	std::string freeSpace = uiFormatBytes(getFreeSpace());
	printf("%s left on the SD.\n\n", freeSpace.c_str());

	bool screenshotsExist = fileExists("sdmc:/screenshots_raw.bin");
	if (screenshotsExist) printf("screenshots_raw.bin \x1b[32mexists\x1b[0m!\n");

	bool dirExist = fileOrDirExists("sdmc:/SaveEditor");
	if (dirExist) {
		printf("SaveEditor dir \x1b[32mexists\x1b[0m!\n");
	}

	else {
		printf("SaveEditor dir \x1b[31mdoes not exist\x1b[0m!\n");
		printf("Creating one...\n");
		mkdir("SaveEditor", 0700);
		printf("Done!\n");
		
	}

	while (aptMainLoop()) {
		hidScanInput();
		if (hidKeysDown() & KEY_START) {
			printf("Exiting...");
			break;
		}

		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();
	}

	fsExit();
	gfxExit();
	return 0;
}