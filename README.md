# PAC-WARS

PAC-WARS is a combination of two classic games- PACMAN and STAR-WARS. It is an online (can be played on the same network) multiplayer game (supports upto 10 players). It crosses the eating each other functionality of pacman with the shooting each other functionality of star-wars.


NOTE: This project was made as an assignment for a course COP290 (Prof. Rijurekha Sen) at IIT Delhi.
https://www.cse.iitd.ac.in/~rijurekha/cop290_2021.html

# Installing dependencies:
### Ubuntu:
1) SDL2  
    use ```sudo apt install libsdl2-dev libsdl2-2.0-0 -y```

2) SDL mixer (For audio) (Not included in SDL2)  
    use ```sudo apt install libsdl2-mixer-2.0-0```

3) SDL image (For displaying images) (Not included in SDL2)  
    use ```sudo apt install libsdl2-image-dev```

(* one might have to install SDL_ttf separately too.)

### Windows:  
Why are you still using it?  

### Other OSs:
Kindly google ```install sdl [OS]``` and ```install sdl [image/mixer/ttf] [OS]```   

# How to run:  
1) Compile  
    use ```make```  

2) Run  
    use ```./game [player_name]```  
    player_name is an optional argument. Game window is named using it.
