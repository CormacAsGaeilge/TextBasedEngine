<h1>C++ Text Based Adventure GameEngine</h1>

Create a text based adventure without having to code it! (Kinda) 
Create your rooms, characters and items and place them in a text file and this engine will load a text based adventure from it.


<h2><b>Version 1.0:-</b></h2>
  - Create weapons, consumbables, keys, dynamic items, scenery, characters(npc,enemy and player) and rooms from text file
  - Use Verb/noun commands
  - "go" command - lets you move the player character from the room it is in to any connected rooms
  - "lookat" command can be used on rooms, weapons, consumbables, keys, dynamic items, scenery, characters(npc,enemy and player), character inventories and rooms to view critical information about them
  - "pickup" command can be used on weapons, consumbables, keys and dynamic items to store them in a player's inventory
  - "use" command can be used on weapons, consumbables, keys and dynamic items in a player's inventory with different effects happening depending on the type of item
  - "view" command can be used to see current health, current wealth and player stats such as how many unique rooms the player has visited or the total value of the items in the player's inventory
  - "help" command for viewing help info in regards to controls,items, scenery, characters and rooms
  - "settings" command to quit the game (i.e. Enter prompt:settings quit)
  
  
  
<h3>Unimplemented functionality/bugs to be included/fixed in a future release:-</h3>
  - "use" commands to effect other objects. Such as the commented out useItem() override in Weapon
  - Correct spelling error where I misspelt Scenery as Scenary almost everywhere (I'm an idiot)
  - Potential memory leak when destroying rooms. I had to comment out the destructor code as it was breaking basically everything and I couldn't figure out why
  - Set up "tradewith" command to buy and sell items to other characters
  - Set up a random AI for other characters in the game so that as you play they can move between rooms, fight each other, trade with each other, pick up items etc
  - Set up an end goal system
  - add more statistics
  
 
 
