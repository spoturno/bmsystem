# Bank Management System
This is a bank managment system made with c and some of c++ (new & delete). The goal of this project is work with Abstract Data Types (Hash Table, AVL trees, Linked List).

- **src/** (source code of each module)
- **tests/** (some functions that test and showcase src/ code)
- **include/** (header files for src/ code)
- **obj/** (object files and executbles live here)

# Modules
## userTable
This module represents the list of the users into the system. They're dynamically added to the userTable (hash table). Some operations implemented are: addUser() (O(1) on average), removeUser() (O(n) in wors case), contains() (O(1)).
## user
This module represents the user type which is inside of the userTable. Each item on the hash table is a user with his respective operations (see on user.h). En each index of the table, if a collision occurs new User is added as a linked list (if id of the new user is different of the existing one); This is called chaning in solving collisions in hash tables.
## utils
This module contains some needed abstract types such as nat (unsigned int, natural integer) and ArregloChars wich aims to represent an array of char. Also special operations like readChars() which reads an ArregloChars. 
## time
This module includes all the operations related to [date and time gnu]('https://www.gnu.org/software/libc/manual/html_node/Date-and-Time.html')

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

# Usage
When executing the program the first thing that is found is the initial screen where you should choose on of the following options: 
- Insert new user account [1]
- Update user information [2]
- User book [3]
- Remove user account [4]
- Transaction book [5]
- CLEAR SCREEN [6]
- Add balance to account [7]
- Exit [0]

By inserting a new user account you will be requested with some user information such as Name, Identification, Age, Balance (TODO: More formal data). Once you filled each blank, your new user will be added dynamically and correctly. If you choose to update user information you'll be asked to select the user identification of the user you want to select (table of users will be shown), once selected you can change a single entry of data of one user (Notice that this will only replace the current value of the data that you want to change).
After that if you want to remove a user, same as before, you will be asked to select the user by his id, once did that the user is removed from the table of users (userTable) and also his memory is free'd. 
Transaction book (TODO).
Clear Screen just clears the screen and show again the inital screen to make it cleaner. This also could be implemented reading and writing the stream, selecting the lines that are not supposed to be shown. Finally to exit the program just input `0` on the stream.

# Future functionalities
- Makefile
- help section
- store data in text file
- store data in mySQL databse
- invalid_input_error()

