自己用的作业框架


# build 
clone
```
git clone https://github.com/zone-1614/zone_cg_template.git xxx
cd xxx
git submodule update --init --recursive
```

build executable:
```
cmake -B build 
cmake --build build
```

build emscripten:
```
emcmake cmake . -B cmake-build-emscripten -G "CodeBlocks - MinGW Makefiles"
cmake --build cmake-build-emscripten
```


> 自己的 vcpkg -DCMAKE_TOOLCHAIN_FILE:STRING="D:/software/vcpkg/scripts/buildsystems/vcpkg.cmake"

