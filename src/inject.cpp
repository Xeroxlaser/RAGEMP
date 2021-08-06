#include "imports.hpp"
#include "nemo.hpp"

DWORD WINAPI startThread(LPVOID lParameter)
{
	Log::Push(new Log::ConsoleStream);

	auto module = (HMODULE)lParameter;
	Nemo::Instance().Run(module);

	while (true)
	{
		if (GetAsyncKeyState(VK_END) & 0x8000)
			break;

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		std::this_thread::yield();
	}

	FreeLibraryAndExitThread(module, 0);

	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		
		AllocConsole();
		SetConsoleTitleA("NEMO | Developer-Output Console");

		freopen_s((FILE**)stdin, "conin$", "r", stdin);
		freopen_s((FILE**)stdout, "conout$", "w", stdout);

		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)startThread, hModule, 0, nullptr);
	}

	return TRUE;
}