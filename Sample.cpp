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
	CGE::Math::Vector<2, float> vec3 = vec1;
	vec3 -= vec2;
	std::cout << vec3[0] << ", " << vec3[1] << std::endl;
	
	if (vec3 == CGE::Math::Vector<2, float>{0.0f, 0.0f})
		std::cout << "I expected vec3 to equal 0, 0... looks like I was right!" << std::endl;
	if (vec3 != CGE::Math::Vector<2, float>{0.0f, 0.0f})
		std::cout << "I expected vec3 to equal 0, 0... looks like I was wrong!" << std::endl;
	
	float magnitude = vec3.Magnitude();
	std::cout << "By the way, it has a magnitude of " << magnitude << std::endl;
	vec3.Normalize();
	std::cout << "But if it was 1, vec3 would be " << vec3[0] << ", " << vec3[1] << std::endl;
	std::cout << "CRAP! I called vec3.Normalize().. how will I restore it?" << std::endl << "Right! I'll multiply it by the magnitude I had before" << std::endl;
	vec3 *= magnitude;
	CGE::Math::Vector<2, float> vec4 = vec3.Normalized();
	std::cout << "Okay this time I'm gonna call Normalized, which will make a new vector that should be the same as the one before..." << std::endl << vec4[0] << ", " << vec4[1] << std::endl;
	std::cout << "Now vec3 should be back to where it was: " << vec3[0] << ", " << vec3[1] << std::endl;
	
	//End CGE program
	delete cgeInstance;
	return 0;
}
