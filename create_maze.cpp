#include "create_maze.h"

long numin=1;     //Number of cells in the maze.
const int xsize=15;
const int ysize=20;


cell MAZE[xsize][ysize];


void initialize() {
	//Initialize the maze!
	for(int x=0;x<xsize;x++) {
		for(int y=0;y<ysize;y++) {
			//The maze cells on the edges of the maze are "in" to provide padding. Otherwise, all maze cells are not in.
			MAZE[x][y].in   = (x==0||x==xsize-1||y==0||y==ysize-1)?1:0;
			//All maze cells have all walls existing by default, except the perimeter cells.
			MAZE[x][y].up   = (x==0||x==xsize-1||y==0)?0:1;
			MAZE[x][y].left = (x==0||y==0||y==ysize-1)?0:1;
		}
	}
	return;
}

void generate() {
	int xcur=1, ycur=1;//start growing from the corner. It could theoretically start growing from anywhere, doesn't matter.
	MAZE[xcur][ycur].in = 1;
	int whichway;
	bool success;
	do {
#ifdef nodeadend
		if( MAZE[xcur][ycur-1].in&&MAZE[xcur][ycur+1].in&&
			   MAZE[xcur-1][ycur].in&&MAZE[xcur+1][ycur].in ) {
				   //If at a dead end, randomly destroy a wall to make it not a dead end!
			do {
				success=0;
				whichway=rand()%4;
				switch(whichway) {
				case UP:
					if(MAZE[xcur][ycur].up&&ycur!=1) {
						success=1;
						MAZE[xcur][ycur].up=0;
					}
					break;
				case DOWN:
					if(MAZE[xcur][ycur+1].up&&ycur!=ysize-2) {
						success=1;
						MAZE[xcur][ycur+1].up=0;
					}
					break;
				case LEFT:
					if(MAZE[xcur][ycur].left&&xcur!=1) {
						success=1;
						MAZE[xcur][ycur].left=0;
					}
					break;
				case RIGHT:
					if(MAZE[xcur+1][ycur].left&&xcur!=xsize-2) {
						success=1;
						MAZE[xcur+1][ycur].left=0;
					}
					break;
				}
			} while(!success);
		}
#endif
#ifdef backtrack
		while( MAZE[xcur][ycur-1].in&&MAZE[xcur][ycur+1].in&&
			   MAZE[xcur-1][ycur].in&&MAZE[xcur+1][ycur].in ) {
				   //If all the neighbourhood cells are in, backtrack.
				int xcur2=MAZE[xcur][ycur].prevx;
				ycur=MAZE[xcur][ycur].prevy;
				xcur=xcur2;
		}
#endif
#ifdef prim
		do {
			//randomly find a cell that's in the maze
			xcur=rand()%(xsize-2)+1;
			ycur=rand()%(ysize-2)+1;
		} while(!MAZE[xcur][ycur].in ||
			MAZE[xcur][ycur-1].in&&MAZE[xcur][ycur+1].in&&
			MAZE[xcur-1][ycur].in&&MAZE[xcur+1][ycur].in);
#endif
		do {
			//Randomly grow the maze if possible.
			success=0;
			whichway=rand()%4;
			switch(whichway) {
			case UP:
				if(!MAZE[xcur][ycur-1].in) {
					success=1;
					MAZE[xcur][ycur].up=0;
					MAZE[xcur][ycur-1].prevx=xcur;
					MAZE[xcur][ycur-1].prevy=ycur;
					ycur--;
				}
				break;
			case DOWN:
				if(!MAZE[xcur][ycur+1].in) {
					success=1;
					MAZE[xcur][ycur+1].up=0;
					MAZE[xcur][ycur+1].prevx=xcur;
					MAZE[xcur][ycur+1].prevy=ycur;
					ycur++;
				}
				break;
			case LEFT:
				if(!MAZE[xcur-1][ycur].in) {
					success=1;
					MAZE[xcur][ycur].left=0;
					MAZE[xcur-1][ycur].prevx=xcur;
					MAZE[xcur-1][ycur].prevy=ycur;
					xcur--;
				}
				break;
			case RIGHT:
				if(!MAZE[xcur+1][ycur].in) {
					success=1;
					MAZE[xcur+1][ycur].left=0;
					MAZE[xcur+1][ycur].prevx=xcur;
					MAZE[xcur+1][ycur].prevy=ycur;
					xcur++;
				}
				break;
			}
		} while(!success);
		MAZE[xcur][ycur].in=1;
		numin++; //Every iteration of this loop, one maze cell is added to the maze.
	} while(numin<(xsize-2)*(ysize-2));
}

void savetxt() {
	ofstream out_file("map.txt");
	int x, y, n;

	for(y = 0; y < ysize; y++) {
		for(x = 0; x < xsize; x++) {
			if(x%2 == 1 && y%2 == 1) {
				if(MAZE[x][y].in) {
					out_file << "W";
				} else {
					out_file << "B";
				}
			} else if(x%2 == 0 && y%2 == 0) {
				out_file << "B";
			} else if(x%2 == 0 && y%2 == 1) {
				if(MAZE[x][y].left) {
					out_file << "B";
				} else {
					out_file << "W";
				}
			} else if(x%2 == 1 && y%2 == 0) {
				if(MAZE[x][y].up) {
					out_file << "B";
				} else {
					out_file << "W";
				}
			}
		}
		out_file << "\n";
	}

	out_file.close();
	return;
}
