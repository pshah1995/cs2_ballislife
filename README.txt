1) Our team cosists of Chris Bradley and Parth Shah.  We worked together planning and coding our strategy for the Othello competition, usually working
through Parth's computer.  Becuase I (Chris) had the ME72 competition last week, Parth did much of the early work in getting us started such as creating 
GIT hub ect.

2) Because of the rigerous finals schedual we decided to do all our work on this project during the first week.  To that effect we optimized our heuristic 
function constants such that we could defeat the ConstantTimePlayer without having to make any major changes this week.  Oaur strategy consisted of
first ranking the valuable positions: Corners are best, the edges, then normal moves, while making positions near edges negetive value.  It took us several 
iterations of testing to determine which multiplyer to assign to each of these moves to optimize our player.  After about five design revs we were able to 
defeat SimplePlayer and ConstantTimePlayer.