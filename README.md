
# AIChessMaster

## Project Overview

**AIChessMaster** is a C++ chess engine that uses the **Minimax algorithm** with **Alpha-Beta Pruning** to efficiently calculate the best moves. 
It includes advanced board evaluation based on piece values and strategic positioning, as well as the ability to save and load games. 
This project demonstrates key concepts in AI decision making, multi-threading (optional), and game development in C++.

## Features

- **Minimax Algorithm with Alpha-Beta Pruning**: Efficient search of game trees to find the best move.
- **Advanced Board Evaluation**: Assigns values to pieces based on type and position, helping to make smarter decisions.
- **Save/Load Game Functionality**: Save the current game state and resume later.
- **Multi-threading Potential**: The design can be easily expanded to support multi-threading for faster computations.
- **Modular Design**: Easy to extend and modify.

## Project Structure

```
/AIChessMaster
├── /include            # Header files
│   ├── board.h         # Board class declaration
│   ├── game.h          # Game class declaration
│   └── minimax.h       # Minimax algorithm declaration
├── /src                # Source files
│   ├── board.cpp       # Board class implementation
│   ├── game.cpp        # Game class implementation
│   └── minimax.cpp     # Minimax algorithm implementation
├── main.cpp            # Main program entry point
├── README.md           # Project documentation
└── .gitignore          # Ignored files
```

## Getting Started

### Prerequisites

To build and run the project, you will need:

- A C++ compiler (GCC, Clang, or MSVC).
- Git (for version control, optional).
- Visual Studio (for Windows users) or CMake (optional for cross-platform builds).

### Building and Running

#### Option 1: Using Visual Studio (Windows)

1. Open the `AIChessMaster.sln` file in Visual Studio.
2. Build the solution using `Ctrl + Shift + B` or `Build > Build Solution`.
3. Run the program by pressing `Ctrl + F5`.

#### Option 2: Using g++ (Linux/MacOS/Windows)

1. Navigate to the project directory.
2. Compile the project with the following command:
   ```bash
   g++ -o aichessmaster main.cpp src/board.cpp src/game.cpp src/minimax.cpp
   ```
3. Run the executable:
   ```bash
   ./aichessmaster
   ```

### Usage

After starting the game, you can input chess moves using the format `startX startY endX endY`, where the coordinates represent positions on the chessboard.

For example:
```bash
Enter your move (startX startY endX endY):
0 1 0 3
```

### Save and Load Game

- **Save**: During gameplay, type `save` to save the current game state to a file.
- **Load**: To load a previously saved game, type `load`.

### Example Gameplay

```bash
Enter your move (startX startY endX endY):
1 0 3 0
AI has moved:
New board:
```

## Future Improvements

- **Multi-threading**: Implement multi-threaded move calculations to speed up the engine.
- **GUI Support**: Add graphical interface using SFML or SDL for a more user-friendly experience.
- **More Advanced Heuristics**: Improve the board evaluation by considering advanced chess strategies such as control of the center, king safety, etc.
- **Undo/Redo Functionality**: Add ability to undo or redo moves.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
