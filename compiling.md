---
layout: default
title: Compiling it yourself
---

Since **ethminer** is OpenSource you can compile it yourself.

## Basics

**ethminer** uses [CMake] and the [Hunter] package manager. 
You can compile it without Hunter if you like, but it will make life a lot easier to use it.

### Dependencies

Most dependencies get resolved via Hunter. Some special cases are:

#### OpenCL on linux
On linux you probably need to install some additional headers.
For more information [see here](https://github.com/ruslo/hunter/wiki/pkg.opencl#pitfalls)

For example on Ubuntu run:

```sh
sudo apt-get install mesa-common-dev
```

#### Windows
On Windows you need Microsoft Visual Studio 2015.
 
#### CUDA Toolkit
If you want to compile with CUDA Support you need to install the CUDA 8 Headers.
You can download them for Windows [here](https://github.com/ethereum/cpp-dependencies/releases/download/cache/CUDA-v8.0-WindowsServer2012.zip).

#### Disable Hunter

If you want to install dependencies yourself or use system package manager
you can disable Hunter by adding
[-DHUNTER_ENABLED=OFF](https://docs.hunter.sh/en/latest/reference/user-variables.html#hunter-enabled)
to configuration options.

## Lets compile

1. Create a build directory.

   ```sh
   mkdir build; cd build
   ```

2. Configure the project with CMake. Check out additional
   [configuration options](#cmake-configuration-options).

   ```sh
   cmake ..
   ```

3. Build the project using [CMake Build Tool Mode]. This is a portable variant
   of `make`.

   ```sh
   cmake --build .
   ```

4. _(Optional, Linux only)_ Install the built executable.

   ```sh
   sudo make install
   ```
   
[CMake]: https://cmake.org
[CMake Build Tool Mode]: https://cmake.org/cmake/help/latest/manual/cmake.1.html#build-tool-mode
[Hunter]: https://docs.hunter.sh