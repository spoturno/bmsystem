# Bank Managmente System
This is a bank managment system made with c and some of c++ (new & delete). The goal of this project is work with Abstract Data Types (Hash Table, AVL trees, Linked List).


# Modules
## userTable
This module represents the list of the users into the system. They're dynamically added to the userTable (hash table). Some operations implemented are: addUser() (O(1) on average), removeUser() (O(n) in wors case), contains() (O(1)).
## user
This module represents the user type which is inside of the userTable. Each item on the hash table is a user with his respective operations (see on user.h). En each index of the table, if a collision occurs new User is added as a linked list (if id of the new user is different of the existing one); This is called chaning in solving collisions in hash tables.
## utils
This module contains some needed abstract types such as nat (unsigned int, natural integer) and ArregloChars wich aims to represent an array of char. Also special operations like readChars() which reads an ArregloChars. 

# Prerequisites
- [g++ compiler](https://gcc.gnu.org) or `gcc -xc++ -lstdc++ -shared-libgcc`
- [Valgrind](https://valgrind.org) for memory managment 

# Installation
1. `git clone [https_or_ssh_link]`
2. `cd bmsystem`
3. `g++ -c src/user.cpp -o obj/user.o`
4. `g++ -c src/utils.cpp -o obj/utils.o`
5. `g++ -c src/userTable.cpp -o obj/userTable.o`
6. `g++ -c src/main.cpp -o obj/main.o`
7. `g++ obj/main.o obj/utils.o obj/user.o obj/userTable.o -o main`
8. `./main`


# Future functionalities
- Makefile
- help section
- store data in text file
- store data in mySQL databse


