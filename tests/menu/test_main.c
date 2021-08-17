#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/user.h"
#include "../../include/utils.h"
#include "../../include/userTable.h"
#include "../../include/transactions.h"

#define WIDTH 50
#define HEIGHT 15

    char *menu[] = {
        "Open new user account",
        "Update user information", 
        "Users book",
        "Close user account",
        "Make transaction",
        "User Transactions",
        "Add balance to User",
        "Exit"

    };

    int n_choices = sizeof(menu) / sizeof(char *);

WINDOW *printMenu(WINDOW *winmenu, int hightlight);

int main(){
	int c;

    int startx = 0;
    int starty = 0;

	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */

    printf("\e[1;1H\e[2J");
    FILE * fp;
    int ch;
    fp = fopen("../../screen.txt", "r");

   /* print bmsystem sing
    * TODO: fix this shit
    while(1){
        c = fgetc(fp) ;
        if(feof(fp))
            break;
        addch(ch);
    }
    */

	startx = (COLS - WIDTH) / 2;
	starty = (LINES - HEIGHT) / 2;
	int highlight = 0;
	int choice = -1;
		
	WINDOW *menuwin = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menuwin, TRUE);
	mvprintw(0, 0, "Use arrow keys to go up and down, Press enter to select a choice");
    refresh();
    printMenu(menuwin, highlight); 

	while(1){	
        c = wgetch(menuwin);
		switch(c)
		{
            case KEY_UP:
				highlight--;
				if(highlight == -1)
					highlight = 0;
				break;
			case KEY_DOWN:
			    highlight++;
				if(highlight == n_choices)
					highlight = n_choices - 1;
				break;
            case 10:
                choice = highlight;
                break;
			default:
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
        printMenu(menuwin, highlight);

        if(choice != -1){
            wclear(menuwin);
            wrefresh(menuwin);
            int q  = wgetch(menuwin);
            if(q == KEY_F(10))
                break;
        }	/* User did a choice come out of the infinite loop */
	}	

	mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, menu[choice]);
	clrtoeol();
	refresh();
	endwin();
	return 0;
}


WINDOW *printMenu(WINDOW *winmenu, int hightlight){
    int x, y ,i;
    x = 2; y = 2;
    box(winmenu, 0, 0);
    for(i = 0; i < n_choices; i++){
        if(hightlight == i)
            wattron(winmenu, A_REVERSE);
        mvwprintw(winmenu, i+1, 2, menu[i]); 
        wattroff(winmenu, A_REVERSE);
    }
    mvwprintw(winmenu, 10, 2, "Quit F10");
    wrefresh(winmenu); 
    return winmenu;
}
