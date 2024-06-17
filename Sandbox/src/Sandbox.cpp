#include <Bismuth.h>

class ExampleLayer : public bi::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void onUpdate() override
	{
		BI_INFO("ExampleLayer::Update");
	}

	void onEvent(bi::Event& event) override
	{
		BI_TRACE("{0}", event.toString());
	}

};

class Sandbox : public bi::Application
{
private:
    /* data */
public:
    Sandbox(/* args */){
		pushLayer(new ExampleLayer());
    }

    ~Sandbox(){

    }
};

bi::Application* bi::CreateApplication() {
    return new Sandbox();
}
