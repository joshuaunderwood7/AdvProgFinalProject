AdvProgFinalProject
===================

An adventure game that involves pressing enter.

CSCI 3320
Project
Spring 2013
CASTLE ADVENTURE
OVERVIEW
Your task is to design and write an adventure game for a new software company.
It is a
game of combat where an adventurer must battle adversaries to secure treasure
stored in the
rooms of a castle. The adventurer enters the castle after choosing a weapon
that will be used
to fight the enemies while trying to secure the treasure. The interior of the
castle will look

(unable to show picture in txt)
like this:
Art Room
Courtyard
Great Hall
Guard
Room
Dungeon

Play
Each room has an enemy protecting the treasure. The enemy will also have a
weapon
(randomly chosen) to fight the adventurer. The amount of treasure is different
(random) and
consists of gold pieces. The adventurer enters the castle (one way only through
the Guard
Room) and immediately begins combat. The adventurer and the adversary take
turns striking
at each other with their weapons.
The adventurer and the enemies can only take so many hits before being killed.
The
adventurer will start with a specific number of hits. Each type of enemy will
have a different
number of hits. Each weapon has a specific chance of hitting an opponent (e.g.
20%). If a
strike is successful, the number of hits assigned to the weapon will be
deducted from the
receiver's total. The game ends when either the adventurer has collected all
the treasure or is
slain by an enemy.

-1-CSCI 3320
Project
Spring 2013

Here is how a typical battle might ensue:
Will enters the courtyard with a sword that has a 40% chance of hitting an
opponent and
which can do 5 hits of damage.
The courtyard is protected by a Gelfing that will take 6 hits to defeat.
The Gelfing's weapon is a Geff that has a 20% chance of hitting an opponent and
it can do 4
hits of damage.
Combat begins:
Gelfing swings and misses
Will swings and misses
Gelfing swings and hits! Will loses 4 hits and has 43 remaining
Will swings and hits! Gelfing loses 5 hits and has 2 remaining.
Gelfing swings and misses
Will swings and hits! Gelfing loses 5 hits. Gelfing is dead!
Will defeats Gelfing and has 3 rooms left to visit.
Press <RTN> to change rooms
Changing Rooms
The adventurer can change rooms by moving in a specific direction. For example:
Willard is in the courtyard.
North:
Queen's Room
South:
Guard Room
East:
Great Hall
West:
Wall
Where do you want to go? (Select randomly)
If the adventurer enters a previously visited room, no combat will take place,
as the enemy
will have been defeated.

-2-CSCI 3320
Project
Spring 2013

SPECIFICATION
You are to simulate the adventure game described in the previous handout. The
game should
open with an appropriate greeting, then a menu to start play or quit. Weapons
and Monsters
are to be randomly chosen by the program. You will be provided with all the
Weapons and
Monsters from which to choose (see last page).
Combat will start after the Adventurer enters the Castle (Guard Room). Combat
will consist
of the alternate swinging of Weapons. Notice each Weapon has a given
probability of hitting
an opponent on each swing. You may choose the start swing (Adventurer or Room
Monster)
randomly; but thereafter, the swings alternate. When a Weapon successfully hits
an
opponent, points will be subtracted from the opponent's total (the points for
the Adventurer
and each Monster will be given on the web). I want to see a blow by blow
account of the
combat. That means I want to see the progress as text displayed on the screen
(see previous
handout). Because I am a slow reader, put a short time delay (one second, for
example),
between each swing.
When a Room Monster is defeated, the Adventurer collects the Treasure and moves
to
another Room. This continues until either the Adventurer is defeated, or all
the Monsters are
conquered. After each Room combat, display the current state of affairs (which
Monster
was defeated, how much total Treasure the Adventurer now has, how many points
the
Adventurer has remaining, etc.)
REQUIREMENTS
• At least 5 new classes
• Style
• Initialization list
• Appropriate use of const
• Use of templates (functions and classes), as warranted.
• Code reuse by composition/containment ("has-a").
• Error checking where appropriate (exception handling).
• Use of Standard template library (algorithms, containers, iterators, and
function objects),
as warranted.

-3-CSCI 3320
Project

PROJECT VALUES
// Adventurer Weapons
Sword, Axe, Spear
// Adventurer Weapon damage value
Sword=5, Axe=4, Spear=3
// Adventurer Weapon probabilty of hitting opponent (out of 100)
Sword=40, Axe=50, Spear=60
// Monster Weapons
Troth, Geff, Beff
// Monster Weapon damage value
Troth=5, Geff=4, Beff=3
// Monster Weapon probability of hitting opponent (out of 100)
Troth=50, Geff=20, Beff=35
// Constants for Rooms
Treasure value=100
// Monster names
Troll, Gelfling, Belf
// Monster values
Troll=13, Gelfling=6, Belf=7
// Adventurer value
Adventurer=50
// Constants for Rooms
Treasure value = 100


(My notes while creating classes and gameplay:)
classes:

    item
      +name
        -prop
            -weapon
              +hit value
              +hip probablity
            -tresure
              +tresure value
        -actor
          +hit points
          +&weapon_weilded
            -hero
	      +collection of &tresure_collected
            -monster
	      +&tresure_held

    location
      +name
      +container of items
      +container listing adjacent locations
        -?room

    gameboard
      +container of locations
        -?castle

    game
     *"This controls game flow and display"


user story:

main calls game.

game greets user.

game creates gameboard:

	gameboard creates locations,

		locations are created with monsters:

			monsters create weapon and contain weapon.

			monsters create tresure and contain the tresure.

		locations create hero:

			hero creates weapon and contain weapon.

(Game LOOP):

game locates hero:

	game displays location info.

	game marks location as visited.

	if location has a monster:

		then game initiates battle.

			if hero wins:

				tresure is copied from monster and added to hero tresure list.

				monster is removed from location.

			else GAMEOVER.

	if every location has been visited: 

		then GAMEOVER.

	game displays adjacent locations.

	game PAUSES and waits for user to press enter.

	game chooses adjacent location, and moves hero to that location

	game displays tresure collected and hit points remaining.

(repeat game loop)

game displays tresure collected and hit points remaining.

(GAMEOVER)

if player is alive: then display a congratulation message

if player is dead: then display a failure message

