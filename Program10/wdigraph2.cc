/*
Victor Amaro
Section 1
Program 10
program to implement several graph algorithms on weighted digraphs.
*/

//#include "/home/cs340/progs/16f/p10/wdigraph.h"
#include "wdigraph.h"

/*
depth_first(int)
returns: nothing
arguments: The starting node, u
purpose: traverses a digraph in the depth-first order
    and it also prints the resulting path
*/
void wdigraph::depth_first(int node) const {
	static int vertex = -1;
    static bool* visited = NULL;

    if (vertex == -1) {
		vertex = node;

    //allocate visited array of size elements
    visited =  new bool(size);

    //set all elements of visited to false
    for(int i = 0; i < size; i++)
        visited[i] = false;
    }

    cout << label[node];
    visited[node] = true;

	for(int i = 0; i != size; i++) {
		if (adj_matrix[node][i] != 0 && visited[i] != true) {
			cout << "->";

            depth_first(i);
        }
    }

    if (node == vertex) {
		cout << endl << endl;
		vertex = -1;
		delete[] visited;
		visited = NULL;
    }
}

/*
print_graph()
returns: nothing
arguments: none
purpose: prints out the followings for a digraph..
    Number of nodes in the digraph,
    An adjaceny matrix for the digraph.
*/
void wdigraph::print_graph() const {
    cout << "\nNo of Nodes = " << get_size() << endl << endl
		<< "Adjacency Matrix" << endl << endl;

    cout << "  |";
    for(int i = 0; i < (int) label.size(); i++)
        cout << "  " << label[i];

    cout << endl <<"--|";
    for(int i = 0; i < (int) label.size(); i++)
        cout << "---";
    cout << endl;

    for(int i = 0; i < (int) label.size(); i++) {
        cout << label[i] << " |";

        for(int j = 0; j < (int) label.size(); j++) {
			if(adj_matrix[i][j] != 0)
				cout << setw(3) << adj_matrix[i][j];
            else
				cout << setw(3) << "-";
        }

		if(i < (int) label.size() -1)
			cout << endl << "  |" << endl;
    }
    cout << endl << endl;
}

//why this doesn't work in VS, I do not know
//But works on the server where I have to turn it in /shrug