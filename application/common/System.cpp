#include "loom/script/loomscript.h"
#include "loom/common/utils/utString.h"
#include "loom/common/platform//platformThread.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

class System
{
protected:
	FILE* pipe;
	char buffer[1024];

	static int __stdcall getData(void *param)
	{
		System* self = (System*)param;
		while (!feof(self->pipe)) {
			if (fgets(self->buffer, 1024, self->pipe) != NULL)//Think about increasing buffer size
			{
				// Remove a new line character at the end, if there is a new line present
				int bufLength = strlen(self->buffer);
				if (self->buffer[bufLength - 1] == 10)
					self->buffer[bufLength - 1] = 0;

				self->_OnDataDelegate.pushArgument(self->buffer);
				self->_OnDataDelegate.invoke();
			}
		}
        
#if LOOM_PLATFORM == LOOM_PLATFORM_WIN32
		_pclose(self->pipe);
#elif LOOM_PLATFORM == LOOM_PLATFORM_OSX
        pclose(self->pipe);
#else
        // Do nothing, there is no pipe to close!
#endif
		// After the pipe is closed, invoke the onFinish delegate
		self->_OnFinishDelegate.invoke();

		return 0;
	}

public:
	LOOM_DELEGATE(OnData);
	LOOM_DELEGATE(OnFinish);

	void cmd(const char *command)
	{
#if LOOM_PLATFORM == LOOM_PLATFORM_WIN32
		pipe = _popen(command, "r");
#elif LOOM_PLATFORM == LOOM_PLATFORM_OSX
        pipe = popen(command, "r");
#else
        pipe = NULL;
#endif
        loom_thread_start(getData, this);
	}
};


static int registerLoomSystem(lua_State* L)
{
	beginPackage(L, "loom")

		.beginClass<System>("System")

		.addConstructor <void(*)(void) >()

		.addMethod("cmd", &System::cmd)

		.addVarAccessor("onData", &System::getOnDataDelegate)

		.addVarAccessor("onFinish", &System::getOnFinishDelegate)

		.endClass()

		.endPackage();

	return 0;
}

void installLoomSystem()
{
	LOOM_DECLARE_NATIVETYPE(System, registerLoomSystem);
}
