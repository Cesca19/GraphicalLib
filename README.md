# GraphicalLib
A program that allow to to choose between SDL and Raylib to create graphical experience in the same way wathever graphic mode you choose

## Requirements
* A windows sytem with Microsoft Visual Studio installed
* Vcpkg installed on tour computer

## Installation
1. Clone the repository:
```bash
git clone https://github.com/Cesca19/GraphicalLib.git
cd GraphicalLib
```

2. Install vcpkg if not already installed:
```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg; .\bootstrap-vcpkg.bat
.\vcpkg.exe integrate install
```

## Building
1. Open `GraphicalLib.sln` in Visual Studio
2. Select your Release configuration
3. Build the solution (F7)

## Usage
1. Navigate to your build configuration folder `Release`
2. Run the executable from the command line:

```bash
./GraphicalLib.exe [-option]
```

### Command Line Options

| Option    | Description          | 
|-----------|---------------------|
| (none)    | Uses SDL2           |
| `-sdl`    | Uses SDL2           |
| `-raylib` | Uses Raylib         |

