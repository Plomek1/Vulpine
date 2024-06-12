#include <Vulpine.h>

class Sandbox : public Vulpine::Application
{

};

Vulpine::Application* Vulpine::CreateApplication()
{
	return new Sandbox();
}