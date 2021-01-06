cp ./scripts/OTG_INIT.sh /usr/local/bin/
python3 ./scripts/menuBuilder.py ./scripts/menu.json ./menu/include/menumod/menu.hpp
rm -r build
mkdir build
cd build
cmake ..
make -j4