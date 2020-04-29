#include <iostream>
#include <CGE/CuckyGameEngine.h>
#include <GL/glew.h>

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
			30, //Target framerate (0 means only use VSync)
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
	
	GLfloat screenFlash = 0.0f;
	while (1)
	{
		screenFlash += 1.0f / 30.0f;
		if (screenFlash > 1.0f)
			screenFlash -= 1.0f;
		glClearColor(screenFlash, screenFlash, screenFlash, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		cgeInstance->GetRender()->Flip();
	}
	
	//Buh-bye!
	delete cgeInstance;
	return 0;
}
