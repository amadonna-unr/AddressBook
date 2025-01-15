addressbook: main.o helpers.o contact.o
		g++ main.o -o addressbook -g

main.o: main.cpp contact.h helpers.h 
		g++ -c main.cpp -g

helpers.o: helpers.cpp helpers.h contact.h
		g++ -c helpers.cpp -g

contact.o: contact.cpp contact.h
		g++ -c contact.cpp -g

clean:
		rm *.o addressbook