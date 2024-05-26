#pragma once

extern bi::Application* bi::CreateApplication();

int main(int argc, char** argv)
{
	auto app = bi::CreateApplication();
	app->run();
	delete app;
}