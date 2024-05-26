#include <Bismuth.h>

class Sandbox : public bi::Application
{
private:
    /* data */
public:
    Sandbox(/* args */){

    }

    ~Sandbox(){

    }
};

bi::Application* bi::CreateApplication() {
    return new Sandbox();
}
