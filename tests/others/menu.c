#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 50
#define HEIGHT 20


int main(){
	int c;

    int startx = 0;
    int starty = 0;

	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */

	startx = (80 - WIDTH) / 2;
	starty = (24 - HEIGHT) / 2;

	int highlight = 0;
	int choice;
		
	WINDOW *menuwin = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menuwin, TRUE);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    refresh();
    box(menuwin, 0, 0);
	wrefresh(menuwin);

    char *menu[] = {
        "Open new user account",
        "Update user information",
        "User boo",
        "close user account",
        "make transaction",
        "transaction user book",
        "add balance to account",
        "Exit"

    };

    int n_choices = sizeof(menu) / sizeof(char *);
      

	while(1){	
        for (int i=0; i < n_choices; i++){
            if(i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, menu[i]); 
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);
		switch(choice)
		{
            case KEY_UP:
				highlight--;
				if(highlight == -1)
					highlight = 0;
				break;
			case KEY_DOWN:
			    highlight++;
				if(highlight == n_choices)
					highlight = 7;
				break;
			default:
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", choice, choice);
				refresh();
				break;
		}
		if(choice == 10)	/* User did a choice come out of the infinite loop */
			break;
	}	
	mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, menu[choice - 1]);

	clrtoeol();
	refresh();
	endwin();
	return 0;
}


