# Pong-v1.0

# Pong Game

A simple Pong game implemented using SFML (Simple and Fast Multimedia Library).

## Gameplay


The objective of the game is to survive as long as possible by hitting the ball with the paddle. The ball will bounce back and forth between the walls and the paddle. However, if the ball touches the bottom wall, the player loses a life. The game ends when the player loses all three lives.

## Prerequisites

Before running the game, you need to have SFML installed on your system. Here's how to set up SFML:

### Installing SFML

1. Download SFML: Visit the SFML website (https://www.sfml-dev.org/) and navigate to the "Download" section. Choose the appropriate version of SFML for your operating system and download it.

2. Extract the SFML package: Once the download is complete, extract the contents of the package to a directory of your choice.

3. Link SFML with your project: To use SFML in your project, you need to link the necessary SFML libraries. Follow the steps below based on your operating system:

   - **Linux**: Open a terminal and navigate to your project directory. Run the following command to compile your project:

     ```
     g++ sfml.cpp ball.cpp Paddle.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
     ```

   - **Windows**: Use an IDE such as Code::Blocks or Visual Studio. Create a new project and configure it to include the necessary SFML libraries. Refer to the SFML documentation (https://www.sfml-dev.org/tutorials/2.5/start-cb.php) for detailed instructions on setting up SFML with Code::Blocks.

### Running the Game

To run the game, follow these steps:

1. Clone the repository: Clone this GitHub repository to your local machine using the following command:
    ```
     git clone https://github.com/your-username/pong-game.git
     ```
2. Build the game: Navigate to the project directory and compile the source files using the appropriate commands for your operating system (as mentioned in the "Installing SFML" section).

3. Run the game: Execute the compiled game file, `sfml-app`, to launch the Pong game.

4. Gameplay: Use the keyboard arrow keys (up and down) to control the paddle and hit the ball. The objective is to keep the ball in play for as long as possible.

## License

This project is licensed under the [MIT License](LICENSE).



