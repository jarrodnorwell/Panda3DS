#include "services/ndm.hpp"

namespace NDMCommands {
	enum : u32 {
		OverrideDefaultDaemons = 0x00140040,
		SuspendDaemons = 0x00060040
	};
}

namespace Result {
	enum : u32 {
		Success = 0,
	};
}

void NDMService::reset() {}

void NDMService::handleSyncRequest(u32 messagePointer) {
	const u32 command = mem.read32(messagePointer);
	switch (command) {
		case NDMCommands::OverrideDefaultDaemons: overrideDefaultDaemons(messagePointer); break;
		case NDMCommands::SuspendDaemons: suspendDaemons(messagePointer); break;
		default: Helpers::panic("NDM service requested. Command: %08X\n", command);
	}
}

void NDMService::overrideDefaultDaemons(u32 messagePointer) {
	printf("NDM::OverrideDefaultDaemons(stubbed)\n");
	mem.write32(messagePointer + 4, Result::Success);
}

void NDMService::suspendDaemons(u32 messagePointer) {
	printf("NDM::SuspendDaemons(stubbed)\n");
	mem.write32(messagePointer + 4, Result::Success);
}