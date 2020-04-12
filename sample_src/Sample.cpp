#include <CGE/Core.h>

int main()
{
	//Create CGE subsystems
	CGE::CORE::INTERFACE *coreInterface = new CGE::CORE::INTERFACE_OPENGL;
	
	//Initialize subsystems
	if (coreInterface->Initialize())
		return 1;
	
	//Delete subsystems
	delete coreInterface;
	return 0;
}
