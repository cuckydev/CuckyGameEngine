#include <iostream>
#include <CGE/Core.h>

int main()
{
	//Create CGE subsystems
	CGE::ERROR::CODE error;
	CGE::CORE::INTERFACE *coreInterface = new CGE::CORE::INTERFACE_OPENGL(&error);
	if (error != CGE::ERROR::NONE)
		std::cout << CGE::ERROR::GetString(error) << std::endl;
	
	//Delete subsystems
	delete coreInterface;
	return 0;
}
