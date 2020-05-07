#include <iostream>
#include <CGE/CuckyGameEngine.h>
#include <CGE/Math.h>
#include <GL/glew.h>

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
	
	CGE::Instance *cgeInstance = new CGE::Instance(config);
	if (cgeInstance == nullptr)
	{
		std::cout << "CuckyGameInstance was not created" << std::endl;
		return -1;
	}
	else if (cgeInstance->GetError())
	{
		std::cout << cgeInstance->GetError().ToString() << std::endl;
		delete cgeInstance;
		return -1;
	}
	
	CGE::Math::Vector<2, float> vec1{-5.0f, 5.0f};
	CGE::Math::Vector<2, float> vec2{5.0f, -5.0f};
	CGE::Math::Vector<2, float> vec3 = vec1.Lerp(vec2, 0.5f);
	std::cout << vec3[0] << ", " << vec3[1] << std::endl;
	
	//End CGE program
	delete cgeInstance;
	return 0;
}
