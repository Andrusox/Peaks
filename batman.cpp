#include <iostream>
#include <list>
#include <fstream> 
#include <vector>
using namespace std;

// ###############################################################################################################

struct Graph{
    int V;
    list<int> *adj;
};

// inizializzazione
int link, from, to,n, source, destination;
Graph* g;

// ###############################################################################################################

// metodo per inizializzare il grafo
void init(int V){
    g = new Graph;
    g->V = V;
    g->adj = new list<int>[V];
}

// metodo per aggiungere un arco
void addEdge(int v, int w){
    g->adj[v].push_back(w);
}
// metodo che ritorna la lista di adiacenza di uno specifico nodo
list<int> returnList(int i){
    return g->adj[i];
}

// metodo che utilizza una bfs per verificare se due nodi sono raggiungibili
bool isReachable(int s, int d){
    // Base case
    if (s == d){
      return true;
    }
 
    // segna tutti i vertici come non visitati
    bool *visited = new bool[g->V];
    for (int i = 0; i < g->V; i++)
        visited[i] = false;
 
    // crea la coda per la BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
    while (!queue.empty()){

        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = g->adj[s].begin(); i != g->adj[s].end(); ++i){

            // If this adjacent node is the destination node, then return true
            if (*i == d){
                delete [] visited;
                return true;
            }
 
            // Else, continue to do BFS
            if (!visited[*i]){

                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    delete [] visited;
    return false;
}

// ###############################################################################################################


int main(int argc, char *argv[]){

    // apro il file input in lettura
    ifstream in ("input0.txt");
    in >> n >> link >> source >> destination;

    // inizializzo la struct Graph
    init(n);

    vector<int> da;
    vector<int> a;

    // leggo elementi e creo le liste di adiacenza
    while(!in.eof()){
        in >> from >> to;
        da.push_back(from);
        a.push_back(to);
        addEdge(from, to);
    }
    in.close();

    list<int> lst = returnList(source);
    if(lst.size() > 0){
        cout << "La sorgente ha una lista di nodi di adiacenza che sono: " << endl;
        for(list<int>::iterator it=lst.begin(); it != lst.end(); ++it){
            int node = *it;
            cout << node << endl;
        }
    }

    for(int i=0; i<link; i++){
        cout << "Da nodo " << a[i] << " a nodo " << da[i] << " è: " <<isReachable(a[i], da[i]) << endl;
    }


    // apro il file in scrittura
    ofstream outf;
    outf.open("output.txt");
    //outf << ragg << endl;
    outf.close();
}

// ###############################################################################################################
