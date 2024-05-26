#pragma once

//Maybe set up different entry points for each platform?

// #ifdef platform

extern bi::Application* bi::CreateApplication();

int main(int argc, char** argv)
{
	bi::Log::init();
	BI_CORE_ERROR("Skibidi toilet");
	int skibidi{5};
	BI_INFO("There is {0}", skibidi);

	auto app = bi::CreateApplication();
	app->run();
	delete app;
}

// #endif