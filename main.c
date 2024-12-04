/*
 *
 *
 * Copyright 2024 Miles Jarvis
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE 
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 *
 */


#pragma clang diagnostic ignored "-Wformat-security"

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>


int main() {

    // Below is where variables are declared.

    int x = 0;                                                  /*  ##                                                               */
    int y = 0;                                                  /*  ##                                                               */
    int running = 1;                                            /*  ##                                                               */
    char *brush = "#";                                          /*  ##                                                               */
    int brushSwapper = 1;                                       /*  ##                                                               */
    int screenWidth;                                            /*  ##                                                               */
    int screenHeight;                                           /*  ##                                                               */
    int input;                                                  /*  ##                                                               */
    int input2;                                                 /*  ##                                                               */
    int isEraseOn = 0;                                          /*  ##                                                               */
    char fileName[250] = "temp";
    char *parsedFileName;
    int colorIndex = 1;

    // initscr() will initiate ncurses.
    initscr();

    // noecho() ensures that input will not be echoed on the display window
    noecho();

    // timeout(-1) makes it so that there is no wait for input. without timeout(-1), you'd have to hold the key for it to register.
	timeout(-1);

    start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    init_pair(5, COLOR_CYAN, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);

    init_pair(8, COLOR_BLACK, COLOR_WHITE);
    init_pair(9, COLOR_RED, COLOR_WHITE);
    init_pair(10, COLOR_YELLOW, COLOR_WHITE);
    init_pair(11, COLOR_GREEN, COLOR_WHITE);
    init_pair(12, COLOR_CYAN, COLOR_WHITE);
    init_pair(13, COLOR_BLUE, COLOR_WHITE);
    init_pair(14, COLOR_MAGENTA, COLOR_WHITE);

    init_pair(15, COLOR_WHITE, COLOR_RED);
    init_pair(16, COLOR_YELLOW, COLOR_RED);
    init_pair(17, COLOR_GREEN, COLOR_RED);
    init_pair(18, COLOR_CYAN, COLOR_RED);
    init_pair(19, COLOR_BLUE, COLOR_RED);
    init_pair(20, COLOR_MAGENTA, COLOR_RED);
    init_pair(21, COLOR_BLACK, COLOR_RED);

    init_pair(22, COLOR_BLACK, COLOR_GREEN);
    init_pair(23, COLOR_YELLOW, COLOR_GREEN);
    init_pair(24, COLOR_GREEN, COLOR_GREEN);
    init_pair(25, COLOR_CYAN, COLOR_GREEN);
    init_pair(26, COLOR_BLUE, COLOR_GREEN);
    init_pair(27, COLOR_MAGENTA, COLOR_GREEN);
    init_pair(28, COLOR_WHITE, COLOR_GREEN);

    init_pair(29, COLOR_WHITE, COLOR_BLUE);
    init_pair(30, COLOR_YELLOW, COLOR_BLUE);
    init_pair(31, COLOR_GREEN, COLOR_BLUE);
    init_pair(32, COLOR_CYAN, COLOR_BLUE);
    init_pair(33, COLOR_BLUE, COLOR_BLUE);
    init_pair(34, COLOR_MAGENTA, COLOR_BLUE);
    init_pair(35, COLOR_BLACK, COLOR_BLUE);

/*        
        COLOR_BLACK   0
        COLOR_RED     1
        COLOR_GREEN   2
        COLOR_YELLOW  3
        COLOR_BLUE    4
        COLOR_MAGENTA 5
        COLOR_CYAN    6
        COLOR_WHITE   7
*/

    // this is our main loop, all of the main logic of Etchi is housed within it.
    while (running == 1) {


        // the below for loop will draw our vertical border towards the right of the screen. we're using mvprintw instead of printw so that we can print to a coordinate.
	    for (int i = 0; i != 44; i++) {
		    mvprintw(i, 168, "|");
	    }


        // the below mvprintw statements print out the horizontal border towards the bottom of the screen, and the useful tips below it.
	    mvprintw(44, 0, "------------------------------------------------------------------------------------------------------------------------------------------------------------------------'");
	    mvprintw(46, 75, "Press \"?\" for help");
	    mvprintw(47, 71, "This program uses Vi keys");
	    mvprintw(48, 62, "Move horizontally and vertically with HJKL");
	    mvprintw(49, 72, "Move diagonally with YUBN");
	    mvprintw(51, 55, "This Software is licensed under the 3-Clause BSD License.");
	    mvprintw(52, 36, "To read more about said license, look at the LICENSE.txt file included with Etchi, or type \"L\"");
	    mvprintw(53, 69, "Copyright 2024 Miles Jarvis");


        // this refreshes the screen to display the new changes.
        refresh();

        attron(COLOR_PAIR(colorIndex));

        // the below switch cases handle the logic for changes the brush appearance.
        switch (brushSwapper) {
           
            case 0:
                brushSwapper = 15;
                refresh();
                break;

            case 1:
                brush = "#";
                refresh();
                break;
        
            case 2:
                brush = "@";
                refresh();
                break;

            case 3:
                brush = "%%";
                refresh();
                break;

            case 4:
                brush = "$";
                refresh();
                break;

            case 5:
                brush = "?";
                refresh();
                break;

            case 6:
                brush = "\"";
                refresh();
                break;

            case 7:
                brush = "-";
                refresh();
                break;
           
            case 8:
                brush = "=";
                refresh();
                break;

            case 9:
                brush = "_";
                refresh();
                break;

            case 10:
                brush = "/";
                refresh();
                break;
            
            case 11:
                brush = "\\";
                refresh();
                break;

            case 12:
                brush = "|";
                refresh();
                break;

                case 13:
                brush = "*";
                refresh();
                break;

            case 14:
                brush = "(";
                refresh();
                break;

            case 15:
                brush = ")";
                refresh();
                break;

            case 16:
                brush = "#";
                brushSwapper = 1;
                refresh();
                break;

            case 18:
                brush = " ";
                refresh();
                break;

            default:
                if (isEraseOn != 1) { 
                    brushSwapper = 1;
                    break;
                }

        }

        /*switch (colorIndex) {
            case 1:
                
        }*/

        // below prints the brush to the screen. this is done after drawing the borders to prevent the cursor from being positioned by the borders.
        mvprintw(y, x, brush);

        // here is were we set the input variable to getch() to collect input.
        input = getch();


        // the below switch cases handle the logic for keypresses and their associated logic.
        switch (input) {

            case 'h':
                x--;
                refresh();
                break;

            case 'j':
                y++;
                refresh();
                break;

            case 'k':
                y--;
                refresh();
                break;

            case 'l':
                x++;
                refresh();
                break;

            case 'y':
                x--;
                y--;
                refresh();
                break;

            case 'u':
                x++;
                y--;
                refresh();
                break;

            case 'b':
                x--;
                y++;
                refresh();
                break;

            case 'n':
                x++;
                y++;
                refresh();
                break;

            case 'Q':
                attroff(COLOR_PAIR(colorIndex));
                mvprintw(0, 0, "Really quit? Any unsaved progress will be lost. (y/n)");
                refresh();
	            input2 = getch();
	            if (input2 == 'y') {
	    	        clear();
                    endwin();
	    	        printf("\nThank you for using Etchi!!\n\n");
           	        return 0;
	            }
	            else {
                    mvprintw(0, 0, "                                                     ");
                    refresh();
                    break;
	            }

            case 'C':
                attroff(COLOR_PAIR(colorIndex));
                mvprintw(0, 0, "Really clear the canvas? Any unsaved progress will be lost. (y/n)");
                refresh();
                input2 = getch();
                if (input2 == 'y') {
                    x = 0;
		            y = 0;
		            clear();
                    refresh();
                    break;
                }
                else {
                    mvprintw(0, 0, "                                                                 ");
                    refresh();
                    break;
                }

            case '?':
                attroff(COLOR_PAIR(colorIndex));
                mvprintw(0, 0, "Really open the help page? This will clear the canvas, and any unsaved progress will be lost. (y/n)");
                refresh();
	    	    timeout(-1);
		        input2 = getch();
    		    if (input2 == 'y') {
	    		    clear();
		    	    mvprintw(1, 0, "HELP PAGE");
			        mvprintw(4, 0, "Press \"C\" to clear the canvas.");
    			    mvprintw(5, 0, "Press \"h\" to bring up the help menu.");
                    mvprintw(6, 0, "Press \"S\" to save. |DOES NOT CURRENTLY SUPPORT FILE PATHS, WILL BE SAVED IN YOUR CURRENT WORKING DIRECTORY|");
                    mvprintw(7, 0, "Press \"O\" to load a file. |DOES NOT CURRENTLY SUPPORT FILE PATHS, WILL LOAD IN YOUR CURRENT WORKING DIRECTORY|");
	    		    mvprintw(8, 0, "Press \"Q\" to quit.");
		    	    mvprintw(9, 0, "Press \"e\" to toggle erasing.");
			        mvprintw(10, 0, "Press \"p\" to cycle forward the brush appearance.");
			        mvprintw(11, 0, "Press \"P\" to cycle backward the brush appearance.");
                    mvprintw(12, 0, "Press \"f\" to cycle forwards between colors.");
                    mvprintw(13, 0, "Press \"F\" to cycle backwards between colors.");
	    		    mvprintw(14, 0, "Press \"z\" to undo. |NOT IMPLEMENTED YET|");
		    	    mvprintw(15, 0, "Press \"L\" to read more about licensing information.");
			        mvprintw(17, 0, "To exit the help page, press any key.");
                    refresh();
    			    curs_set(0);
	    		    getch();
		    	    clear();	
			        curs_set(2);
                    break;
		        }
		        else {
                    mvprintw(0, 0, "                                                                                                   ");
                    refresh();
                    break;
		        }

            case 'e':
                if (isEraseOn == 0) {
                    brush = " ";
		            isEraseOn = 1;
		            brushSwapper = 18;
                    refresh();
                }
                else if (isEraseOn == 1) {
                    brush = "#";
		            isEraseOn = 0;
    		        brushSwapper = 1;
                    brushSwapper--;
                    refresh();
                }

            case 'p':
                brushSwapper++;
                break;

            case 'L':
                attroff(COLOR_PAIR(colorIndex));
                mvprintw(0, 0, "Really open licensing info? This will clear the canvas, and any unsaved progress will be lost. (y/n)");
                refresh();
		        timeout(-1);
		        input2 = getch();
		        if (input2 == 'y') {
			        clear();
    			    mvprintw(1, 0, "LICENSING INFO");
	    		    mvprintw(4, 0, "Copyright 2024 Miles Jarvis");
		    	    mvprintw(6, 0, "Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:");
			        mvprintw(8, 0, "1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer");
    			    mvprintw(10, 0, "2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.");
	    		    mvprintw(12, 0, "3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.");
		    	    mvprintw(14, 0, "THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR");
			        mvprintw(15, 0, "PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF");
    			    mvprintw(16, 0, "SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING");
	    		    mvprintw(17, 0, "IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.");
                    refresh();
		    	    curs_set(0);
			        getch();
    			    clear();	
	    		    curs_set(2);
                    break;
		        }

		        else {
                    mvprintw(0, 0, "                                                                                                    ");
                    refresh();
                    break;
		        }

            case 'S':
                attroff(COLOR_PAIR(colorIndex));
                mvprintw(43, 0, "Would you like to save? (y/n)");
                refresh();
                input2 = getch();
                if (input2 == 'y') {
                    mvprintw(43, 0, "                             ");
                    mvprintw(43, 0, "What would you like to name the file? ");
                    refresh();
                    echo();
                    getstr(fileName);
                    scr_dump(fileName);
                    mvprintw(43, 0, "                                                                                                                                               ");
                    refresh();
                    noecho();
                    break;
                }

                else {
                    mvprintw(43, 0, "                             ");
                    refresh();
                    break;
                }
            
            case 'O':
                attroff(COLOR_PAIR(colorIndex));
                mvprintw(43, 0, "Would you like to load? (y/n)");
                refresh();
                input2 = getch();
                if (input2 == 'y') {
                    mvprintw(43, 0, "                             ");
                    mvprintw(43, 0, "What file would you like to load? ");
                    refresh();
                    echo();
                    getstr(fileName);
                    scr_restore(fileName);
                    mvprintw(43, 0, "                                                                                                                                               ");
                    refresh();
                    noecho();
                    break;
                }
                
                else {
                    mvprintw(43, 0, "                             ");
                    refresh();
                    break;
                } 
            case 'o':
                    brushSwapper--;
                    break; 

            case 'f':
                    if (has_colors() == FALSE) {
                        mvprintw(0, 0, "Sorry, your terminal doesn't support colors.");
                        getch();
                        mvprintw(0, 0, "                                            ");
                        break;
                    }
                    if (colorIndex > 36) {
                        colorIndex = 1;
                    }
                    else if (colorIndex < 0) {
                        colorIndex = 35;
                    }
                    colorIndex++;
                    break;

            case 'F':
                    if (has_colors() == FALSE) {
                        mvprintw(0, 0, "Sorry, your terminal doesn't support colors.");
                        getch();
                        mvprintw(0, 0, "                                            ");
                        break;
                    }
                    if (colorIndex > 36) {
                        colorIndex = 1;
                    }
                    else if (colorIndex < 0) {
                        colorIndex = 35;
                    }
                    colorIndex--;
                    break;

               }
        

                // the below if and else if statements handle if the brush is out of bounds and, if so, teleports it back to its proper spot.
                if (x < 0) {
                    x = 0;
                }
            
                else if (x > 167) {
                x = 167;
            }
        
            if (y < 0) {
                y = 0;
            }
        
            else if (y > 43) {
                y = 43;
            }

            // refreshes the screen.
            refresh();
            attroff(COLOR_PAIR(colorIndex));
    
    }      
    
    // closes the window
	endwin();

    // exits with a return value of 0
	return 0;

}
