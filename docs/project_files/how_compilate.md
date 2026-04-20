# Just for example!

# 1. compilation module file
g++ -std=c++20 -fmodules-ts -c my_module.ixx -o my_module.o

# 2. compilation main file
g++ -std=c++20 -fmodules-ts -c main.cpp -o main.o

# 3. linking objectives main file with module file
g++ main.o my_module.o -o my_app