#include <ncurses.h>


WINDOW *create_newwin(int height, int widht, int starty, int startx);
void destroy_win(WINDOW *local_win);


int main(){
    WINDOW *my_win;
    int startx, starty, width, height;
    int ch;

    initscr(); /* Initialize curses system all mem for stdscr and others*/
    //raw(); /* Line buffering disabled*/
    cbreak(); /* Line buffering disabled, pass on */

    keypad(stdscr, TRUE); /* enables reading of function keys, arrow keys etc*/
    //noecho(); /*blocks first -> better control of user input*/
   
    //printw("Type any character to see bold\n"); /* prints data on stdscr at 0,0, screen not update*/
    //ch = getch(); /*waits for user input*/

    height = 3;
    width = 10;
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;
    refresh();
    my_win = create_newwin(height, width, starty, startx);



    while((ch = getch()) != KEY_F(1)){
        switch(ch){
            case KEY_LEFT:
                destroy_win(my_win);
                my_win = create_newwin(height, width, starty, --startx);
                break;
            case KEY_RIGHT:
                destroy_win(my_win);
                my_win = create_newwin(height, width, starty, startx++);
                break;
            case KEY_UP:
                destroy_win(my_win);
                my_win = create_newwin(height, width, starty++, startx);
                break;
            case KEY_DOWN:
                destroy_win(my_win);
				my_win = create_newwin(height, width, ++starty,startx);
				break;
        }

    }
    endwin(); /* frees the memory of curses system and all its sturcuts*/
    return 0;
}


WINDOW *create_newwin(int height, int widht, int starty, int startx){
    WINDOW *local_win;
    local_win = newwin(height, widht, starty, startx);
    box(local_win, 0, 0); /*0,0 gives default characters for the vertical and horizontal lines*/
    wrefresh(local_win); /*show that box*/
    return local_win;
}

void destroy_win(WINDOW *local_win){
    wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(local_win);
    delwin(local_win);
}
