#include <CGE/CuckyGameEngine.h>
#include <CGE/Math.h>
#include <iostream>

int main()
{
	//Create a CuckyGameEngine instance
	static const CGE::Config config =
	{
		//Backend to be used
		CGE::Backend::SDL2,
		
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
	
	std::vector<CGE::Math::Vector<3, float>> position = {
		{-1.0f, 1.0f, -2.0f},
		{-1.0f, -1.0f, -2.0f},
		{1.0f, -1.0f, -2.0f},
		{1.0f, 1.0f, -2.0f},
	};
	
	std::vector<CGE::Math::Vector<3, float>> normal = {
		{0.0f, 0.0f, 1.0f},
		{0.0f, 0.0f, 1.0f},
		{0.0f, 0.0f, 1.0f},
		{0.0f, 0.0f, 1.0f},
	};
	
	std::vector<CGE::Math::Vector<2, float>> uv = {
		{0.0f, 0.0f},
		{0.0f, 1.0f},
		{1.0f, 1.0f},
		{1.0f, 0.0f},
	};
	
	std::vector<CGE::Math::Vector<4, float>> colour = {
		{1.0f, 1.0f, 1.0f, 1.0f},
		{1.0f, 1.0f, 1.0f, 1.0f},
		{1.0f, 1.0f, 1.0f, 1.0f},
		{1.0f, 1.0f, 1.0f, 1.0f},
	};
	
	std::vector<uint16_t> indices = {
		0, 1, 3, 3, 1, 2
	};
	
	CGE::Render::Mesh *mesh = render->NewMesh(indices, position, normal, uv, colour);
	
	CGE::Math::Matrix<float> mat = CGE::Math::PerspectiveMatrix<float>(0.785398f, 4.0f / 3.0f, 0.1f, 100.0f);
	
	while (1)
	{
		if (render->ClearColor(0.25f, 0.9f, 0.5f) ||
			render->ClearDepth() ||
			render->Draw(mesh) ||
			render->Flip())
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
