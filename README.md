GraphMap
==========

C++ application named weighs that searches for the optimal route to travel to a location based on the shortest, and longest, potential travel times along a route.

==========

Command-line Arguments: 

	weighs start end streetMapGraphFile 

- start is the id of the starting waypoint in the graph (i.e., your current location). 
- end is the id of the ending waypoint in the graph (i.e., your destination). 
- streetMapGraphFile is the name of the input graph file using the format described below.

===========

Sample Input File

	WAYPOINTS:
	1 Kuwait and Qatar
	2 KSA and Oman
	3 UAE and bahrain

	STREETS:
	1 2 1.6 4
	2 3 3.5 8
	2 1 1 2.1
	3 2 3 4.3

=============

Technique 

Using Graphs, specifically (Dijkstra's Algorithm). 


