# 🎮 Raylib C++ Cross-Platform Template

A concise template for raylib C++ projects using CMake and vcpkg (manifest mode), enabling cross-platform builds on macOS, Windows, and Linux.

## Setup

0. **Use this template**

Click **"Use this template"** button. This will initialize your repo from this template. 

1. **Clone & Initialize:**

```bash
git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name
git submodule update --init --recursive
```

2. **Bootstrap vcpkg:**

```bash
# macOS/Linux
./vcpkg/bootstrap-vcpkg.sh

# Windows
.\vcpkg\bootstrap-vcpkg.bat
```

## 🛠️ Build & Run

1. **Create Build Directory:**

```bash
mkdir build
cd build
```

2. **Configure CMake (select your OS triplet):**

   * **macOS (ARM64):**

   ```bash
   cmake .. -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=arm64-osx
   ```

   * **Windows (x64 - from VS Dev Cmd Prompt):**

   ```bash
   cmake .. -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows
   ```

   * **Linux (x64):**

   ```bash
   cmake .. -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-linux
   ```

3. **Build:**

```bash
cmake --build .
```

4. **Run:**
```bash
./bin/MyRaylibGame
```