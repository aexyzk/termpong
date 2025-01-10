#include <curses.h>
#include <unistd.h>

#define DELAY 30000

#define max(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b;       \
})

#define min(a,b)             \
({                           \
    __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a < _b ? _a : _b;       \
})


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

	int paddleHeight = winY / 4;

	bool running = true;
	while(running){
		if (ballX >= winX-1 || ballX < 0) {
			axisX*= -1;
		}
		ballX += 1 * axisX;

		if (ballY >= winY || ballY < 0) {
			axisY*= -1;
		}
		ballY += 1 * axisY;

		clear();

		move(0, 1);
		vline('#', paddleHeight);

		move(max(min(ballY-(paddleHeight/2),winY-(paddleHeight)),0),winX-1);
		vline('#', paddleHeight);

		mvprintw(ballY,ballX,"O");
		refresh();

		usleep(DELAY);
	}

	endwin();

    return 0;
}