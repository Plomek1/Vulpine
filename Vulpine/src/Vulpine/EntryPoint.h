#pragma once

#ifdef VP_PLATFORM_WINDOWS

extern Vulpine::Application* Vulpine::CreateApplication();

int main(int argc, char** argv)
{
	printf("TEEEEEEEEEEE");
	auto app = Vulpine::CreateApplication();
	app->Run();
	delete app;
}

#endif