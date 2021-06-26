
typedef struct _rep_node *Node;

/* 
 * Show the initial screen of the program, showing to the user the available options,
 */
void initialScreen();


/*
 * Gets the user input from keyboard, only options that are shown in the menu are avaiable to input
 */
int getInputUser();

/*
 * Operates with the user input, calling each respective function for every option that user choose.
 */
void manageUserInput(int option);

