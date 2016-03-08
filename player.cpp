#include "player.h"
#include <iostream>
#include <cmath>

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    //std:cerr << "blah" << std::endl;
	//fprintf(stderr, "%d\n", "123");
    testingMinimax = false;
    board = new Board();
    me = side;
    move = NULL;
    if (side == BLACK)
    {
    	opp = WHITE;
    }
    else
    {
    	opp = BLACK;
    }

    /* 
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /* 
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */ 
    board->doMove(opponentsMove, opp);

    return heuristic();
}

Move *Player::heuristic() {
	//int score_array [8][8];
    int index_x = -1;
    int index_y = -1;
    double score = (-3*64)+1;
    double score_temp = 0;
    double score_prev = board->count(me) - board->count(opp);
    
    //std::cerr << "in move" << std::endl;
    for(int i = 0; i < 8; i++)
    {
    	for(int j = 0; j < 8; j++)
    	{
    		//std::cerr << "in loop" << std::endl;
    		Move *move_temp = new Move(i, j);
    		if(board->checkMove(move_temp, me))
    		{
    			//std::cerr << "in true" << std::endl;
    		    Board *board_1 = board->copy();
    		    board_1->doMove(move_temp, me);

    			if(i == 1 || i == 6 || j == 1 || j == 6)
    			{
    				score_temp = (0.33) * (board_1->count(me) - board_1->count(opp) - score_prev);
    				if(score_temp > score)
    				{
    					score = score_temp;
    					index_x = i;
    					index_y = j;
    				}
    			}
    			else if(i == 0 || i == 7 || j == 0 || j == 7)
    			{
    				score_temp = 3 * (board_1->count(me) - board_1->count(opp) - score_prev);
    				if(score_temp > score)
    				{
    					score = score_temp;
    					index_x = i;
    					index_y = j;
    				}
    			}
    			else if((i == 0 && j == 0) || (i == 0 && j == 7) || (i == 7 && j == 0) || (i == 7 && j == 7))
    			{
    				score_temp = 5 * (board_1->count(me) - board_1->count(opp) - score_prev);
    				if(score_temp > score)
    				{
    					score = score_temp;
    					index_x = i;
    					index_y = j;
    				}    				
    			}    			
    			else
    			{
    				score_temp = (board_1->count(me) - board_1->count(opp) - score_prev);
    				if(score_temp > score)
    				{
    					score = score_temp;
    					index_x = i;
    					index_y = j;
    				}    				
    			}
    		delete(board_1);
    		//std::cerr << score << std::endl;
    		}
    		delete(move_temp);
    	}
    }
 
    if(index_x == -1)
    {
    	return NULL;
    }
    else 
    {
        Move *myMove = new Move(index_x, index_y);
    	board->doMove(myMove, me);    	
    	return myMove;
    }
}

//Move *Player::minimax() {

//}