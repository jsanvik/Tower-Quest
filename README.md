# CPSC2720 Major Project: Text Based Adventure Game

## Design Phase 

First Group Meeting: 
November 1, 2024
Goal: Discuss ideas and finalize the plot
All members were present. We settled on the main plot/idea that we will use for the project. To adhere to the guidelines, we started by reading the project description, and everyone voiced their suggestions in different interactions that we needed while staying within the requirements. We also clearified certain aspects of how the game would work.
    Tasks: Make a UML diagram for the next meeting.

Second Group Meeting:
November 6, 2024
Goal: Have a rough final UML design 
Everyone brought their own UML designs. We looked at all of them and combined the best aspects of each while making improvements. Had lots of group discussions about how the implementation would work and if we correctly adhered to design principles. We booked a meeting with Nicole to ensure we were on the right track, and finalize the UML design. 
    Tasks: Meet with Nicole at set time and date
    
Third Group Meeting with Nicole:
November 7, 2024 
Goal: Ask Questions and finalize the UML design 
All members were present. We explained the idea to Nicole and got help figuring out a few things. Also received helpful suggestions about our design and how we would go about it in our implementation.
    Tasks: Finish the UML design and design report


## Team member contributions:
Solomon
- Came up with the main project plot
- Created UML class diagram that was then used to collaborate on our final design 
- Dicussed game flow ideas
- Helped with design report
- Helped with dia file
- Helped with README
- Class: Item and inventory
- Helped with integration of all code 

John
- Created UML class diagram that was then used to collaborate on our final design 
- Dicussed game flow ideas
- Helped with dia file 
- Helped with design report
- Class: Character and Game
- Helped with integration of all code 

Sofiah
- Created UML class diagram that was then used to collaborate on our final design 
- Dicussed game flow ideas
- Helped with dia file 
- Helped with README
- Class: NPC and User Input
- Helped with integration of all code 

Gurmannat
- Created UML class diagram that was then used to collaborate on our final design 
- Dicussed game flow ideas
- Helped with design report
- Helped with README
- Class: Environment and User Input
- Helped with integration of all code 

## NPCs (names or descriptions)
### Guard
- Guards the gate to the tower
- Allows the player to pass after solving a math puzzle
### Librarian
- Guards the tower's Library
- Allows the player to pass after solving a word puzzle
### Dementor
- Guards the darkest room in the tower
- Suggests the player use an item to overcome the darkness and advance to the next room
### Witch
- Offers the player a riddle
- If the player answers correctly, gives the player the potion that will **wake up** the princess
- If the player answers incorrectly, gives the player the potion that will **kill** the princess!
### Princess
- If given the correct potion, wakes up, allowing the player to win the game
- If given the incorrect potion, dies, causing the player to lose the game
    
    
## Environments
### Safe Environment
- Front Yard: The tower's front yard, where the player begins the game
- Door Room: Choose the correct door to advance, choosing the wrong one takes you to a Dangerous Environment (where you die!)
### Puzzle Environment
- Gate: The tower's gate, where a guard allows you to pass after solving a math puzzle
- Library: The tower's library, where the librarian allows you to pass after solving a word puzzle
- Dark Room: The darkest room in the tower, requires lighting the flaming sword to pass
- Witch's Cavern: The Witch's lair, she will give you a good or bad potion depending on your answer to her riddle
- Princess's Room: Room where the princess lies sleeping, if given the correct potion she will wake up and win the game
### Dangerous Environment
- Pit Room: Upon entering the pit room, the player falls to their death and dies, losing the game.
- Spike Room: Upon entering the spike room, the player is impaled and dies, losing the game.
    
## Usable Items
### Flaming Sword
- Used to light up the dark room in order to proceed
### Good Potion
- Given to the player by the Witch if her riddle is answered correctly.
- Giving this to the princess causes the princess to wake up and the player to win the game.
### Bad potion
- Given to the player by the Witch if her riddle is answered correctly.
- Giving this to the princess causes the princess to die and the player to lose the game.

## Puzzles
### Math Puzzle
- Given by the guard guarding the gate
- Halt! You seek to rescue the princess, but you shall not pass so easily. 
The gate to the tower will remain sealed until you prove your intellect. 
Behold the sequence: 3 6 12 24 48 __? 
- Correct answer: 96
### Word Puzzle
- Multiple choice puzzle given by Librarian in the Library
- To keep ascending the tower, your mind must be sharper than your blade. 
Rearrange the letters and reveal the hidden word: dsimwo
- Options:
* A. widsom
* B. wisdom
* C. domwis
* D. dowmis
- Correct answer: B
### Item Puzzle
- Presented by the Dementor
- The dementor asks the player what item will help them navigate the dark room:
- The darkness is overwhelming. You cannot see the door ahead. 
To get past you need to navigate this dark room. 
What item might help you?
- Options:
* A. Coins
* B. Shield
* C. Flaming Sword
- Correct answer: C
- After giving the correct answer, the game prompts the player to use the item (by pressing 'L' to light up the room), allowing them to proceed.
### Riddle
- Multiple choice puzzle given by the Witch
- Before you take what you seek, you must prove your worth again and again. 
Another puzzle for you, brave knight, to test the strength of the mind as much as the heart. 
Here is the test of association: 
Moon Crows Sun 
What is the connection between them?
- Options:
* A. Sky
* B. Celestial
* C. Darkness
- Correct answer: A
- If the player answers correctly, the witch gives the player the good potion that will **wake up** the princess
- If the player answers incorrectly, the witch gives the player the bad potion that will **kill** the princess!
### Final Puzzle
- The player is prompted to give a potion to the princess.
- If the player answered the witch's riddle correctly in the previous room, the witch has given the player the good potion that will **wake up** the princess! The player wins the game.
- If the player answered the witch's riddle incorrectly in the previous room, the witch gives the player the bad potion that will **kill** the princess! The player loses the game.
    
## How to lose the game
### Answer a riddle incorrectly
Sample input sequence to get there:
- Enter any name
- 42
### Enter a dangerous room 1(Pit Room)
Input sequence to get there:
- Enter any name
- 96
- breadme
- c
- l
- 1
### Enter a dangerous room 2(Spike Room)
- Enter any name
- 96
- b
- c
- l
- 2
### Give the princess the bad potion
Input sequence to get there: 
- Enter any name
- 96
- b
- c
- l
- 3
- b
- a
### 
## Player actions
### Solve Puzzle
- The player gives an answer to a puzzle presented by an NPC
### Ignite Flaming Sword
- The player uses the flaming sword to light up a dark room.
### Give Potion
- Gives a potion to the Princess, the correct potion will wake her up, the incorrect potion will kill her.
### Move to Different Rooms
- The player goes through different rooms to save the princess. 