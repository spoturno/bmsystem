# Bank Management System
Simple Bank managment system made with c and some of c++ (new & delete). The goal of this project is work with Abstract Data Types (Hash Table, AVL trees, Linked List).

- **src/** (source code of each module)
- **tests/** (some functions that test and showcase src/ code)
- **include/** (header files for src/ code)
- **obj/** (object files and executbles live here)

## Modules
### userTable
This module represents the list of the users into the system. They're dynamically added to the userTable (hash table). Some operations implemented are: addUser() (O(1) on average), removeUser() (O(n) in wors case), contains() (O(1)).
### user
This module represents the user type which is inside of the userTable. Each item on the hash table is a user with his respective operations (see on user.h). En each index of the table, if a collision occurs new User is added as a linked list (if id of the new user is different of the existing one); This is called chaning in solving collisions in hash tables.
### utils
This module contains some needed abstract types such as nat (unsigned int, natural integer) and ArregloChars wich aims to represent an array of char. Also special operations like readChars() which reads an ArregloChars. 
### timer
This module includes all the operations related to [date and time gnu]('https://www.gnu.org/software/libc/manual/html_node/Date-and-Time.html')
### hash
This module includes all the operations related to hashing a string with the sha-256 algorithm. It will substitute the current hash function of userTable module. Also It'll work for any transaction algorithm in the future.
### transaction
This module represents all the transaction made by one user in the userTable. Each transaction is stored in a binary search tree of type Transaction which is included in the _rep_transaction who is pointed by Transactions.

## Prerequisites
- [g++ compiler](https://gcc.gnu.org) or `gcc -xc++ -lstdc++ -shared-libgcc`
- [Valgrind](https://valgrind.org) for memory managment 

## Installation
1. `git clone [https_or_ssh_link]`
2. `cd bmsystem`
3. `make` compiles and generated de exe file
4. `./main`

## Usage
When executing the program the first thing that is found is the initial screen where you should choose on of the following options: 

    [1] Insert new user account           
    [2] Update user information           
    [3] User book                         
    [4] Remove user account               
    [5] Make transaction                  
    [6] Transaction user book             
    [7] Add balance to Account            
    [8] CLEAR SCREEN                      
    [0] Exit                              

By inserting a new user account you will be requested with some user information such as Name, Identification, Age, Balance (TODO: More formal data). Once you filled each blank, your new user will be added dynamically and correctly. If you choose to update user information you'll be asked to select the user identification of the user you want to select (table of users will be shown), once selected you can change a single entry of data of one user (Notice that this will only replace the current value of the data that you want to change).

After that if you want to remove a user, same as before, you will be asked to select the user by his id, once did that the user is removed from the table of users (userTable) and also his memory is free'd. 
Transaction book (TODO).
Clear Screen just clears the screen and show again the inital screen to make it cleaner. This also could be implemented reading and writing the stream, selecting the lines that are not supposed to be shown. Finally to exit the program just input `0` on the stream.

## TODOS
- Uses ncurses TUI library for better UX
- Help section for the program.
- Store data in mySQL databse.
- Make invalid_input_error() for checking program input.
- Image for github README
- Future gui implementation with gtk+ 
- Hash the user private info (sha256)
- Meaby some kind of real transaction

## Contributing
Have you spotted a typo, would you like to fix a link, or is there something you’d like to suggest? Be welcome to open a pull request!

## Resources
- [Hash Standar](https://nvlpubs.nist.gov/nistpubs/FIPS/NIST.FIPS.180-4.pdf)
- [Right and Left Shifting](https://www.geeksforgeeks.org/left-shift-right-shift-operators-c-cpp/)
- [Little-Big endian](https://www.geeksforgeeks.org/little-and-big-endian-mystery/)
- [Convert Little endian to Big endian](https://stackoverflow.com/questions/19275955/convert-little-endian-to-big-endian)
- [SQLite C](https://www.sqlite.org/index.html)
- [Ncurses howto](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/)
