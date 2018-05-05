# EC504-Project-Final
Final Project for EC504: Advanced Data structures


Files:

eVEB.h: class definition of space Efficient VEB Trees

eVEB.cpp: functions of Insert, Delete, GetCount

Fibheap.h: class definition of Fibonacci Heaps and their functions

Source: https://github.com/beniz/fiboheap/blob/master/fiboheap.h

Fibtest.cpp: main function to simulate Fibonacci Heaps runtime

runtime.sh: script to simulate Fibonacci Heaps for dense and sparse graphs with varying graph sizes (The larger graphs take awhile to run)

Graph.h: class defintion of Graph

Graph.cpp: functions implemented for Graph

GraphVEB.cpp: Dijkstra's algorithm using space efficient VEB trees

GraphFib.cpp: Dijkstra's algorithm using Fibonacci Heaps

graph.txt: sample graph in the form of V1 V2 Weight(V1,V2)




-------------------------------------------------------------------------------------
How to run Simulations: (For large numbers, might take a while):

Fibonacci Heaps: Run "g++ fibtest.cpp -o fibtest" to compile and name the executable file "fibtest"
Then run "./fibtest.sh" to run the simulation. The runtimes are outputted on the scale of nanoseconds.



How to run Dijkstra's: (only works with small # of Vertices)

Being in the directory with all files, run "g++ GraphVEB.cpp" or "g++ GraphFib.cpp" and your outpue will return a clear depiciton of the Graph printed in a readable format as well as a the shortest path starting at Vertex 0 to all other nodes.




