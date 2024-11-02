# ChessLogicMeson

This project is a C++17 DLL built using Meson for move generation in chess. The DLL is intended for use in a Unity project, [Deezchess-Unity](https://github.com/AdamAzuddin/Deezchess-Unity), to provide efficient chess move logic.

## Features

- Chess move generation using the [chess-library by Disservin](https://github.com/Disservin/chess-library).
- Built as a dynamic library (DLL) with C++17 standards.
- Compatible with Unity integration.

## Prerequisites

- **C++17**: This project requires a compiler that supports C++17.
- **Meson**: Build system used to compile the project.

## Setup and Build

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/ChessLogicMeson.git
cd ChessLogicMeson
```

### 2. Initialize and Install Dependencies

This project is using the meson build system. https://mesonbuild.com/

#### Setup

```bash
meson setup build
```

#### Compilation

```bash
meson compile -C build
```

The output DLL will be available in the build directory.

## Usage
The compiled DLL can be used in the [DeezChess Unity project](https://github.com/AdamAzuddin/Deezchess-Unity). Simply reference the DLL in your Unity project to utilize its chess move generation logic.


Feel free to contribute or open issues if you encounter any problems or have suggestions for improvements.