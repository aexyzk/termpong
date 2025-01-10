#include <curses.h>
#include <unistd.h>

#define DELAY 30000

int main()
{
	initscr();
	noecho();
	curs_set(FALSE);

	int ballX = 0;
	int ballY = 0;
	int axisX = 1;
	int axisY = 1;
	int winX, winY;

	getmaxyx(stdscr, winY, winX);

	bool running = true;
	while(running){
		if (ballX >= winX || ballX < 0) {
			axisX*= -1;
		}
		ballX += 1 * axisX;

		if (ballY >= winY || ballY < 0) {
			axisY*= -1;
		}
		ballY += 1 * axisY;

		clear();
		mvprintw(ballY,ballX,"O");
		refresh();

		usleep(DELAY);
	}

	endwin();

    return 0;
}