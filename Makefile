Main:
	clang main.c -lncurses -o etchi
	printf "\nCompilation successful, run Etchi locally with ./etchi in this directory, or run 'sudo make install' to run it globally.\n"
install:
	cp etchi /usr/bin/etchi
	printf "\nInstallation successful, you can now run Etchi globally!\n"
