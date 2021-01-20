
build:
	gcc -o MonitorBacklight main.c -lncurses

clean:
	rm -f *.o MonitorBacklight
