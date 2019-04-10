rectangle_search:	rectangle_search_skeleton.o rectangle.o exception.o controller.o
	g++ rectangle_search_skeleton.o rectangle.o exception.o controller.o -o rectangle_search

rectangle_search_skeleton.o: rectangle_search_skeleton.cc
	g++ -c rectangle_search_skeleton.cc

exception.o: exception.cc exception.h
	g++ -c exception.cc

rectangle.o: rectangle.cc rectangle.h
	g++ -c rectangle.cc

controller.o:controller.cc controller.h
	g++ -c controller.cc

clean:
	rm *.o output
