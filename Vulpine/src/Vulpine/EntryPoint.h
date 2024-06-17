#pragma once

#ifdef VP_PLATFORM_WINDOWS

extern Vulpine::Application* Vulpine::CreateApplication();

int main(int argc, char** argv)
{
	Vulpine::Log::Init();

	VP_CORE_LOG_TRACE("test");
	VP_CORE_LOG_INFO("test");
	VP_CORE_LOG_WARN("test");
	VP_CORE_LOG_ERROR("test");

	VP_LOG_INFO("TT");

	auto app = Vulpine::CreateApplication();
	app->Run();
	delete app;
}

#endif