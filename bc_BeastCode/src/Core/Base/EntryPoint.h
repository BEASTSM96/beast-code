
#pragma once

#ifdef BC_PLATFORM_WINDOWS

extern BeastCode::Application* BeastCode::CreateApplication();

int main(int argc, char** argv) {
	BeastCode::Log::Init();
#ifdef BC_CORE_DEBUG
	BC_CORE_INFO("Log inited");
#endif // BC_CORE_DEBUG
	auto app = BeastCode::CreateApplication();
	app->Run();
	delete app;

}
#endif // BC_PLATFORM_WINDOWS
