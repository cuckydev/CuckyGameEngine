#include <CGE/CuckyGameEngine.h>
#include <CGE/Math.h>
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
	
	//3D render test
	CGE::Render::Interface_Base *render = cge_instance->GetRender();
	CGE::Math::Matrix<float> mat = CGE::Math::PerspectiveMatrix<float>(0.785398f, 4.0f / 3.0f, 0.1f, 100.0f);
	
	while (1)
	{
		if (render->ClearColor(0.0f, 1.0f, 0.0f) || render->ClearDepth() || render->Flip())
		{
			std::cout << render->GetError() << std::endl;
			delete cge_instance;
			return -1;
		}
	}
	
	//End CGE program
	delete cge_instance;
	return 0;
}
