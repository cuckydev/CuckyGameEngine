#include <CGE/Core.h>

int main()
{
	//Create CGE instances
	CGE::CORE::INTERFACE *interface = new CGE::CORE::INTERFACE_OPENGL();
	interface->TestBackend();
	delete interface;
	return 0;
}
