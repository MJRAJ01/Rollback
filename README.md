# Rollback

A fun console game to solve any sized sequential game using Rollback equilibrium.

## What is Rollback equilibrium?
Rollback equilibrium (RBE) is used to solve games with multiple players making decisions sequentially about the outcome of a game. Each non-terminal node contains the option for a player to go "up" or "down" until a terminal node is reached. Once arrived, there is a "payoff" for each player, which is a numerical reward value.

RBE solves these games by eliminating any paths that a player would never take, which is indicated by the payoff being lower following that path rather than another. As such, one starts at the terminal nodes and eliminates moving backwards until the only likely path is found, which is called the rollback equilibrium.

## How it works

RBE naturally drew similarities to recursive solutions in CS, which lead me to put this together based off traversing and solving trees. After puting together a picture of the game you would like to solve, such as the ones in the link below, just follow the prompts in the console to insert the nodes properly and it will solve the game from there.


## More info

More information on sequential games can be found here: http://www.sfu.ca/~rda18/302_8_SequentialGames.pdf
