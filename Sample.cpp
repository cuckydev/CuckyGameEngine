#include <iostream>
#include <CGE/CuckyGameEngine.h>

int main()
{
	//Create a CuckyGameEngine instance
	static const CGE::CONFIG config =
	{
		//Backend to be used
		CGE::BACKEND_GLFW,
		
		//Render configuration
		{
			"CuckyGameEngine sample", //Window title
			640, 480, //Screen dimensions
			true, //Resizable
			false, //Fullscreen
			0, //Target framerate (0 means only use VSync)
		},
	};
	
	CGE::INSTANCE *cgeInstance = new CGE::INSTANCE(config);
	if (cgeInstance == nullptr)
	{
		std::cout << "CuckyGameInstance was not created" << std::endl;
		return -1;
	}
	else if (cgeInstance->GetError().Errored())
	{
		std::cout << cgeInstance->GetError().GetString() << std::endl;
		delete cgeInstance;
		return -1;
	}
	
	//Buh-bye!
	delete cgeInstance;
	return 0;
}
