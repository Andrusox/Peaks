#include <iostream>
#include <list>
#include <fstream> 
#include <vector>
#include <map>
#include <string>
using namespace std;

// ###############################################################################################################

struct Graph{
    int V;
    list<int> *adj;
};

// inizializzazione
int link, from, to,n, source, destination, path;
int** enemy;
Graph* g;

typedef std::pair< int, int> Link; //definisce arco
typedef std::vector<int> Path;  //definisce percorso
typedef std::vector<Path> PathSet; //definisce serie di percorsi
typedef std::vector<Path>::const_iterator Paths; //bho non so cosa voglia dire

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


void findAllPaths(int start, int finish){

        list<int> lst = returnList(start);
        if(lst.size() > 0){     
            cout << "Itero su elementi adiacenti di " << start << endl;
            for(list<int>::iterator it=lst.begin(); it != lst.end(); ++it){
                int node = *it;
                cout << start <<" -> " << node << endl;
                if(node == finish){
                    path++;
                    cout << "Fine sono arrivato a destinazione!" << endl;
                    cout << endl;
                    //return;
                }else{
                    findAllPaths(node,finish);
                }
            }
        }
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
    
    for(int i=0; i<n; i++){
        cout << "Stampo contatore: " << i << endl;
        list<int> lst = returnList(i);
        if(lst.size() > 0){
            cout << "La size della lista di "<< i << " è: " << lst.size() << endl;
            cout << "Nodo " << i <<" ha una lista di nodi di adiacenza che sono: ";
            for(list<int>::iterator it=lst.begin(); it != lst.end(); ++it){
                int node = *it;
                cout << node << "  ";
            }
            cout << endl;
        }else{
            cout << "Nodo " << i <<" non ha una lista di nodi di adiacenza!" << endl;
        }
    }
<<<<<<< Updated upstream
    
=======
    */

   /* enemy = new int*[n];
>>>>>>> Stashed changes


    //fornisce la lista dei nemici
    for(int i=0; i<link; i++){
        if(isReachable(a[i], da[i]) == 0){
            // qui vanno salvati in memoria invece che sputati fuori
        	cout << "Da nodo " << a[i] << " a nodo " << da[i] << " è: " << isReachable(a[i], da[i]) << endl;
        }
    }

<<<<<<< Updated upstream
	
=======
    */
    

>>>>>>> Stashed changes
    findAllPaths(source,destination);
    

    // apro il file in scrittura
    ofstream outf;
    outf.open("output.txt");
    outf << path << endl;
    outf.close();
}

// ###############################################################################################################
