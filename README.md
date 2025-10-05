# 🎰 Slot Machine Game (C++)

A simple console game of one-armed bandit in **C++**.
Player can deposit and pay out the funds, check balance and play with different symbols and multipliers

## 📋 Functionality
- 💰 Balance system
- ➕ Deposit and pay out funds
- 🎲 Draw symbols
- 🔥 Special symbol „🔥” win multiplier
- 💎 Win for threes (when rare symbol) and for pair
- 📝 Console menu
- 📂 Autosave balance

## 📂 Project structure
```bash
Slots/
├── slots/
│ ├── src/
│ │ ├── main.cpp
│ │ ├── slots.cpp
│ │ └── slots.h
│ ├── CMakeLists.txt
│ └── README.md
```
## 🛠️ Installation and start

### 🔹 Linux / macOS
Clone repository:
    ```bash
    git clone https://github.com/CitrusUpdate/Slots.git
    cd Slots/slots
    cmake -S . -B build
    cmake --build build
    ./build/slotgame

### 🔹 Windows
1. Install MinGW or MSYS2
    git clone https://github.com/CitrusUpdate/Slots.git
    cd Slots/slots
    cmake -S . -B build -G "MinGW Makefiles"
    cmake --build build
    build/slotgame.exe
    ``

## LICENSE
Project on license [MIT](LICENSE).