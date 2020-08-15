#include <BeastCode.h>

class Sandbox : public BeastCode::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{

	}

};

BeastCode::Application* BeastCode::CreateApplication()
{
	return new Sandbox();
}