#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {

	Hazel::Log::init();
	HZ_CORE_WARN("Initialize Core log");
	HZ_INFO("Initialize Client log");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif // HZ
