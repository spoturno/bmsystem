# Bank Managmente System
This is a bank managment system made with c and some of c++ (new & delete). 

# Model Bank Managment System

|******************************************|
|          Banka Managment System          |
|******************************************|
|                                          |
|     [1] Insert new user                  |               
|     [2] Manage transaction               |
|     [3] Transaction book                 |
|     [0] Exit                             |
|                                          |                
|******************************************|
    

# Modules
##userTable
This module represents the list of the users into the system. They're dynamically added to the userTable (hash table). Some operations implemented are: addUser() (O(1) on average), removeUser() (O(n) in wors case), contains() (O(1)).
##user
This module represents the user type which is inside of the userTable. Each item on the hash table is a user with his respective operations (see on user.h).
##utils
This module contains some needed abstract types such as nat (unsigned int, natural integer) and ArregloChars wich aims to represent an array of char. Also special operations like readChars() which reads an ArregloChars. 

# Future functionalities
- help section
- delete user from user book
- store data in text file
- store data in mySQL databse


