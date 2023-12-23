#!/bin/bash

BLUE="\e[95m"
RED="\e[91m"
GREEN="\e[92m"
MAGENTA="\e[94m"
BOLD="\e[1m"

RESET_COLOR="\e[0m"

function line
{
	cols=$(tput cols)
	char=$1
	color=$2

	if test "$color" != ""; then
		echo -ne $color
	fi

	for i in $(eval echo "{1..$cols}"); do
		echo -n $char
	done
	echo

	if test "$color" != ""; then
		echo -ne $C_RST
	fi
}

echo -e $BLUE$BOLD
line "_"
cat << "EOF"
  _____           _        _ _                               
 |_   _|         | |      | | |                              
   | |  _ __  ___| |_ __ _| | |   ___ ___  _ __   __ _ _ __  
   | | | '_ \/ __| __/ _` | | |  / __/ _ \| '_ \ / _` | '_ \ 
  _| |_| | | \__ \ || (_| | | | | (_| (_) | | | | (_| | | | |
 |_____|_| |_|___/\__\__,_|_|_|  \___\___/|_| |_|\__,_|_| |_|
EOF
line "_"
echo -e $RESET_COLOR


####################### INSTALL PYTHON ###############################
echo -e "${MAGENTA}\e[1;4mInstallation of Python-pip...${RESET_COLOR}\n"
sudo apt install python3-pip
pip3 --version
if [ $? != 0 ]; then
        echo -e "${RED}${BOLD}Installation Failed${RESET_COLOR}";
        exit 84;
    else
        echo -e "${GREEN}${BOLD}Successfully installed${RESET_COLOR}\n";
fi;
#######################################################################

####################### INSTALL CONAN #################################
echo -e "${MAGENTA}\e[1;4mInstallation of conan${RESET_COLOR}\n"
sudo pip3 install conan
conan --version
if [ $? != 0 ]; then
        echo -e "${RED}${BOLD}Installation Failed${RESET_COLOR}";
        exit 84;
    else
        echo -e "${GREEN}${BOLD}Successfully installed${RESET_COLOR}\n";
fi;
########################################################################

echo -e $BLUE$BOLD
line "_"
cat << "EOF"
   _____             __ _                                     
  / ____|           / _(_)                                    
 | |     ___  _ __ | |_ _  __ _    ___ ___  _ __   __ _ _ __  
 | |    / _ \| '_ \|  _| |/ _` |  / __/ _ \| '_ \ / _` | '_ \ 
 | |___| (_) | | | | | | | (_| | | (_| (_) | | | | (_| | | | |
  \_____\___/|_| |_|_| |_|\__, |  \___\___/|_| |_|\__,_|_| |_|
                           __/ |                              
                          |___/ 
EOF
line "_"
echo -e $RESET_COLOR

############################## Config remotes #################################################
echo -e "${MAGENTA}\e[1;4mSet mandatory remotes${RESET_COLOR}\n"
conan remote remove conan-center
conan remote add conan-center-repo https://api.bintray.com/conan/conan/conan-center
conan remote add epitech-repo https://api.bintray.com/conan/epitech/public-conan
conan remote add bincrafters-repo https://api.bintray.com/conan/bincrafters/public-conan
conan remote list
echo -e "${GREEN}${BOLD}Successfully configured${RESET_COLOR}\n";
################################################################################################

############################## Create conanfile #################################################
echo -e "${MAGENTA}\e[1;4mCreate conanfile.txt with mandatory library${RESET_COLOR}\n"
if [ -f conanfile.txt ]; then
        echo -e "${RED}${BOLD}Conanfile already exist${RESET_COLOR}";
    else
        echo -e "[requires]\nqt/5.14.2@bincrafters/stable\nportaudio/v190600.20161030@bincrafters/stable\nopus/1.3.1@bincrafters/stable\nboost/1.74.0\nsqlite3/3.29.0@bincrafters/stable\n\n[generators]\ncmake" > conanfile.txt
        echo -e "${GREEN}Conanfile successfully created:${RESET_COLOR}${BOLD}"
        cat conanfile.txt
fi;
################################################################################################

echo -e "${MAGENTA}\e[1;4mBuild conan${RESET_COLOR}\n"
sudo apt-get install libjack0 xorg-dev libxcb-render-util0-dev libxcb-xkb-dev libxcb-icccm4-dev libxcb-xinerama0-dev libxcb-xinput0 libxcb-keysyms1-dev libx11-xcb-dev libxcb-image0-dev libxcb-randr0-dev libxcb-shape0-dev libxcb-sync-dev libxcb-xfixes0-dev

if [ ! -d build ]; then
  mkdir build ; cd build ; conan install .. --build=missing;
fi;

echo -e "\e[33m${BOLD}"
cat << "EOF"
       (`.
         ) )
        ( (
         \ \
          \ \
        .-'  `-.
       /        `.
      (      )    `-._ ,    _
       )   ,'         (.\--'(
       \  (         ) /      \
        \  \_(     / (    <6 (6
         \_)))\   (   `._  .:Y)__
          '''  \   `-._.'`---^_)))
                `-._ )))       ```
                     ```           Made by Tarek, Thiire, Hecto and Merimann
EOF
echo -e "To be used only for the babybel group"