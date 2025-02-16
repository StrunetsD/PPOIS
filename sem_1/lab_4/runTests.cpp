#include "src/Graph.h"
#include "src/IncidentEdgeIterator.h"
#include "src/VertexIter.h"
#include "src/EdgeIter.h"
#include <gtest/gtest.h>
//lab-4
using namespace std;

int main(int argc, char** argv) {
    Graph<string> graph;


    graph.add_vertex("A");
    graph.add_vertex("B");
    graph.add_vertex("C");


    graph.add_edge("A", "B");
    graph.add_edge("B", "C");
    graph.add_edge("A", "C");

    cout << "Graph adjacency list:" << endl;
    graph.print();
    int vertex_num_first = graph.vertex_count();
    cout << "\nVertex number: " << vertex_num_first << endl;

    cout << "\nIterating over vertices:" << endl;
    for (auto it = VertexIterator<Graph<string>, string>(graph.begin(), graph.end()); it != VertexIterator<Graph<string>, string>(graph.end(), graph.end()); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    cout << "\nRemoving vertex B..." << endl;
    for (auto it = VertexIterator<Graph<string>, string>(graph.begin(), graph.end()); it != VertexIterator<Graph<string>, string>(graph.end(), graph.end()); ++it) {
        if (*it == "B") {
            it.remove_vertex(graph);
            break;
        }
    }

    cout << "\nGraph after removing vertex B:" << endl;
    graph.print();
    int vertex_num = graph.vertex_count();
    cout << "\nVertex number: " << vertex_num << endl;
    int degree_A = graph.degree_of_vertex("A");
    int degree_C = graph.degree_of_vertex("C");
    cout << "\nDegree of vertex A: " << degree_A << endl;
    cout << "Degree of vertex C: " << degree_C << endl;
    int degree_AC = graph.degree_of_edge("A", "C");
    cout<<endl;
    cout << "\nDegree of vertex AC: " << degree_AC << endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
