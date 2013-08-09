#ifdef _MSC_VER
#include <Windows.h>
#endif // _MSC_VER

#include "GameApp.h"
#include "Config.h"



int main()
{
	Config config("config.xml");
	GameApp app(config);
	try
	{
		app.run();
	}
	catch (std::exception& e)
	{
#ifdef _MSC_VER		// Windows specific code
		MessageBoxA(nullptr, (std::string("An Exception happened: ") + e.what()).c_str(), "Unexpected Exception", MB_OK);
#else
		std::cout << "Exception: " << e.what() << std::endl;
		std::getchar();
#endif // _MSC_VER
	}
	
	return 0;
}