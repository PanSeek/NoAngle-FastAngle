#include <Windows.h>

auto __cdecl fill(unsigned __int32 address, unsigned __int8 value, unsigned __int32 size) -> void {
	DWORD oldProt{ 0 };
	VirtualProtect(reinterpret_cast<LPVOID>(address), size, PAGE_READWRITE, &oldProt);
	memset(reinterpret_cast<void*>(address), value, size);
	VirtualProtect(reinterpret_cast<LPVOID>(address), size, oldProt, &oldProt);
	return;
}

struct Main {
	Main() {
		fill(0x5E4DA1, 0xEB, 0x1);
		fill(0x5E4DF6, 0xEB, 0x1);
	};
	~Main() {
		fill(0x5E4DA1, 0x75, 0x1);
		fill(0x5E4DF6, 0x75, 0x1);
	};
} plugin;