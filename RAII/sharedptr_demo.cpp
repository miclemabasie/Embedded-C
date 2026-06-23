#include <iostream>
#include <memory>
#include <string>

// The resource being shared
class GameConfig
{
public:
    std::string theme = "Dark Mode";

    GameConfig() { std::cout << "[Config] Created in memory.\n"; }
    ~GameConfig() { std::cout << "[Config] Destroyed! Memory cleaned up.\n"; }
};

// First subsystem that needs the config
class GraphicsEngine
{
private:
    std::shared_ptr<GameConfig> config_;

public:
    GraphicsEngine(std::shared_ptr<GameConfig> cfg) : config_(cfg)
    {
        std::cout << "GraphicsEngine initialized. Current owners: " << config_.use_count() << "\n";
    }
    ~GraphicsEngine() { std::cout << "GraphicsEngine destroyed.\n"; }
};

// Second subsystem that needs the config
class SoundSystem
{
private:
    std::shared_ptr<GameConfig> config_;

public:
    SoundSystem(std::shared_ptr<GameConfig> cfg) : config_(cfg)
    {
        std::cout << "SoundSystem initialized. Current owners: " << config_.use_count() << "\n";
    }
    ~SoundSystem() { std::cout << "SoundSystem destroyed.\n"; }
};

int main()
{
    std::cout << "--- Scope Start ---\n";

    // Create the resource. Reference count = 1.
    std::shared_ptr<GameConfig> sharedConfig = std::make_shared<GameConfig>();

    // Create an inner block scope
    {
        std::cout << "\n--- Initializing Subsystems ---\n";
        // Pass it to GraphicsEngine. Reference count becomes 2.
        GraphicsEngine graphics(sharedConfig);

        // Pass it to SoundSystem. Reference count becomes 3.
        SoundSystem sound(sharedConfig);

        std::cout << "\n--- Operating inside inner scope ---\n";
    } // graphics and sound go out of scope here!

    std::cout << "\n--- Inner Scope End ---\n";
    std::cout << "Config owner count: " << sharedConfig.use_count() << "\n";

    std::cout << "\n--- Main Scope End ---\n";
    return 0;
    // sharedConfig goes out of scope here. Count hits 0. Cleanup triggers!
}