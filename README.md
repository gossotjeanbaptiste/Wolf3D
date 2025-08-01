# Epi-Graphical-Template-C

Before doing anything you have to do ```make start``` to modified the name of gitignore.txt to .gitignore to avoid any problem with git and make gitignore work fine. Also go to the Makefile and change the name of the project to your project name.
Where ever you see "project" change it to your project name.

For compilation of lib/my and lib/my_graphical make : ```make``` if you can't because it say "Nothing to be done for `all'" make : ```make re``` it should recompile as expected.

For clean make : ```make clean``` to clean the ```lib/my``` and for everywhere make : ```make fclean```

For coding-style : ```make cs``` Warning : You have to recompile the ```lib/my``` before any knew compilation of your project

(For unit_tests (create and run them) make : ```make unit_tests & make tests_run```)