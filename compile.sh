python3 ./tools/menuBuilder.py ./tools/menu.json ./menu/include/menumod/menu.hpp
rm -r build
mkdir build
cd build
cmake ..
make -j4