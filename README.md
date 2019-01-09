# Counter-Strike: Source Memory Hack (Linux)

Simple memory hack for CSS. If you want to use the toggle switches, you will need to find your keyboard in /dev/input/by-id/

You will need to install X11 development libraries. You can do this by typing: 
sudo dnf groupinstall "X Software Development" in fedora.


Features:

Wireframe (F6) 

Fog override (F7)

Bunnyhop (SPACE) -> Must bind l to +jump in game

This has been completed as I have discovered that process_vm_writev is not as quick as the WriteProcessMemory on Windows, which leads to a terrible bunnyhop hack. It stands to reason that other time sensitive features like aimbot/triggerbot/esp will also be ineffective. I will be moving forward with a new project that will operate interally.
