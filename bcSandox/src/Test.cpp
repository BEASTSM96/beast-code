#include <BeastCode.h>

class Sandbox : public BeastCode::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());

	}

	~Sandbox()
	{

	}

};

BeastCode::Application* BeastCode::CreateApplication()
{
	return new Sandbox();
}