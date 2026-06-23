#include <iostream>
#include <memory>
#include <string>

class GameConfig
{
public:
    std::string theme = "Dark Mode";

    GameConfig() { std::cout << "[Config] Created in memory.\n"; }
    ~GameConfig() { std::cout << "[Config] Destroyed! memory cleaned up.\n"; }
};

class GraphicsEngine
{
private:
    std::shared_ptr<GameConfig> config_;

public:
    GraphicsEngine(std::shared_ptr<GameConfig> &cfg)
        : config_(cfg)
    {
        std::cout << "GraphicsEngine initialized. Current owners: " << config_.use_count() << "\n";
    }

    ~GraphicsEngine()
    {
        std::cout << "GraphicsEngine destroyed!\n";
    }
};

class SoundSystem
{
private:
    std::shared_ptr<GameConfig> config_;

public:
    SoundSystem(std::shared_ptr<GameConfig> &cfg)
        : config_(cfg)
    {
        std::cout << "SoundSystem initialized. Current owners: " << config_.use_count() << "\n";
    }

    ~SoundSystem()
    {
        std::cout << "Soundsystem destroyed!\n";
    }
};

int main(void)
{

    std::cout << "--- Scop Start --- \n";

    // Create the Resource reference, count = 1
    std::shared_ptr<GameConfig> sharedGameConfig = std::make_shared<GameConfig>();
    // create inner block scope
    {
        std::cout << "\n --- Initializing Subsytems ---\n";
        std::cout << sharedGameConfig.use_count() << std::endl;
        // pass it to the graphicengin. reference count becomes 2.
        GraphicsEngine graphics(sharedGameConfig);

        // pass it to the soundSystem. Reference becomes 3
        SoundSystem sound(sharedGameConfig);

        std::cout << "\n --- Operating inside inner scope --- \n";

    } // graphics and sound go out of scop here!

    std::cout << std::endl
              << "Inner Scope End ---" << std::endl;

    std::cout << "Config owner count: " << sharedGameConfig.use_count() << std::endl;

    std::cout << std::endl
              << "--- Main Scope End --- " << std::endl;
    return 0;
}