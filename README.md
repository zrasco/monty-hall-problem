# monty-hall-problem

This is a quick Win32 console app I wrote to confirm the findings of the Monty Hall problem, which I found hard to believe without proof.

Basically, you're on a game show and you get to pick 1 of 3 doors. Only 1 has the car, the other two have donkeys. So you pick a door, and the host reveals one of the other doors with a donkey behind it. However, the host gives you the chance to switch your chosen door to the other unknown door. Do you make the switch?

Because the host has given you new information about which door had a donkey, switching doors increases your overall probability of success from 1/3 to 2/3, because you now know the revealed door had a donkey. However, staying with your original choice leaves you with a 1/3 probability of being right, so switching doors increases your chance of winning.

It's raw mathematics so to think of this intuitively, imagine the same setup with 50 doors (instead of 3), where 49 doors have donkeys and 1 has a car. You pick, say... door 24. The host opens 48 of the other doors, revealing donkeys in all. He leaves door 43 closed. He gives you the opportunity to switch, and you do because there's no way you correctly guessed the car door on the first chance unless you were really, really lucky.

This program runs an arbitrary number of monty hall simulations and outputs the results, confirming the expected outcome over a large number of tries.
