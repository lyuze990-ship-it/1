#include "core/engine.h"
#include <iostream>

int main(int argc, char* argv[])
{
    try
    {
        ShootingGame::Engine engine;
        engine.Initialize("5v5 Tactical Shooting Game", 1920, 1080);
        engine.Run();
        engine.Shutdown();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
