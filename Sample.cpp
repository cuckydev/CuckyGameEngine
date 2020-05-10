#include <CGE/CuckyGameEngine.h>
#include <iostream>

int main()
{
	//Create a CuckyGameEngine instance
	static const CGE::Config config =
	{
		//Backend to be used
		CGE::Backend::GLFW,
		
		//Render configuration
		{
			"CuckyGameEngine sample", //Window title
			640, 480, //Screen dimensions
			true, //Resizable
			false, //Fullscreen
			0, //Target framerate (0 means only use VSync)
		},
	};
	
	CGE::Instance *cge_instance = new CGE::Instance(config);
	if (cge_instance == nullptr)
	{
		std::cout << "CuckyGameInstance was not created" << std::endl;
		return -1;
	}
	else if (cge_instance->GetError())
	{
		std::cout << cge_instance->GetError() << std::endl;
		delete cge_instance;
		return -1;
	}
	
	//Render test
	CGE::Render::Interface_Base *render = cge_instance->GetRender();
	float r = 0.0f;
	
	while (1)
	{
		if (render->ClearColor(r, r, r) || render->ClearDepth() || render->Flip())
		{
			std::cout << cge_instance->GetError() << std::endl;
			delete cge_instance;
			return -1;
		}
		
		r += 1.0f / 60.0f;
		if (r > 1.0f)
			r = 0.0f;
	}
	
	//End CGE program
	delete cge_instance;
	return 0;
}
