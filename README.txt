Rollback

This project is based off the concept of Rollback Equilibrium used in game theory. The method is
used to solve games with multiple players making decisions sequentially about the outcome of a game.
Each non-terminal node contains the option for a player to go "up" or "down" until a terminal node
is reached. Once arrived, there is a "payoff" for each player, which is a numerical reward value.

The method to solve these games is to eliminate any paths that a player would never take, which is
indicated by the payoff being lower following that path rather than another. As such, one starts at
the terminal nodes and eliminates moving backwards until the only likely path is found, which is
called the rollback equilibrium.

This method naturally drew similarities to recursive solutions in CS, which lead to this program
being developed.

More information on sequential games can be found here: http://www.sfu.ca/~rda18/302_8_SequentialGames.pdf