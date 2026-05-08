#ifndef GAME_H
#define GAME_H

/**
 * @file game.h
 * @brief Main game class definition
 * @version 1.0
 */

#include <string>

/**
 * @class Game
 * @brief Core game engine class
 *
 * Handles the main game loop, initialization, and cleanup.
 */
class Game {
 public:
  /**
   * @brief Constructor
   * @param title Window title
   * @param width Window width
   * @param height Window height
   */
  Game(const std::string& title, int width, int height);

  /**
   * @brief Destructor
   */
  ~Game();

  /**
   * @brief Initialize the game
   * @return true if initialization successful, false otherwise
   */
  bool initialize();

  /**
   * @brief Run the main game loop
   */
  void run();

  /**
   * @brief Shutdown the game
   */
  void shutdown();

  /**
   * @brief Check if game is running
   * @return true if game is running, false otherwise
   */
  bool isRunning() const;

 private:
  /**
   * @brief Handle events
   */
  void handleEvents();

  /**
   * @brief Update game logic
   */
  void update();

  /**
   * @brief Render game frame
   */
  void render();

  std::string title_;
  int width_;
  int height_;
  bool is_running_;
  int frame_count_;
};

#endif  // GAME_H
